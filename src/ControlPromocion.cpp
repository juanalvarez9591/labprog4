#include "ControlPromocion.h"
#include "ControlUsuario.h"
#include "ControlFecha.h"
#include "DTPromocion.h"
#include "DTInfoProducto.h"
#include "DTProducto.h"
#include "Categoria.h"
#include <iostream>
ControlPromocion* ControlPromocion::instance = nullptr;

ControlPromocion* ControlPromocion::getInstance() {
    if (instance == nullptr) {
        instance = new ControlPromocion();
    }
    return instance;
}

ControlPromocion::ControlPromocion() {
    controlUsuario = ControlUsuario::getInstance();
    controlFecha = ControlFecha::getInstance();

    productos = unordered_map<int, Producto>();
    promociones = unordered_map<string, Promocion>();

    Vendedor* vendedorEnMemoria = nullptr;
    Promocion promocionEnMemoria = Promocion();
}

set<string> ControlPromocion::listarNicknameVendedores() {
    vector<Vendedor> vendedores = controlUsuario->getVendedores();
    set<string> nicknames;
    for (int i = 0; i < vendedores.size(); i++) {
        nicknames.insert(vendedores[i].getNickname());
    }
    return nicknames;
}

bool ControlPromocion::elegirVendedor(string nickVendedor) {
    Vendedor* vendedorElegido = controlUsuario->getVendedor(nickVendedor);
    this->vendedorEnMemoria = vendedorElegido;
    return vendedorElegido != nullptr;
}

bool ControlPromocion::ingresarProducto(string nombre, string descripcion, float precio, int stock, string categoria) {
    if (this->vendedorEnMemoria == nullptr) {
        return false;
    }
    Categoria cat = fromString(categoria);
    int codigoProducto = productos.size() + 1;

    if (productoEnPromocion(codigoProducto)) {
        return false;
    }
    Producto producto = Producto(nombre, descripcion, codigoProducto, stock, precio, cat, this->vendedorEnMemoria);
    productos[codigoProducto] = producto;
    return true;
}

vector<DTProducto> ControlPromocion::listarProductos() {
    vector<DTProducto> dtProductos;
    unordered_map<int, Producto>::iterator it;
    for (it = productos.begin(); it != productos.end(); ++it) {
        DTProducto dtProducto = it->second.toDTProducto();
        dtProductos.push_back(dtProducto);
    }
    return dtProductos;
}

DTInfoProducto ControlPromocion::verInfoProducto(int idProducto) {
    unordered_map<int, Producto>::iterator it = productos.find(idProducto);
    if (it != productos.end()) {
        return it->second.toDTInfoProducto();
    }
    return DTInfoProducto();
}

void ControlPromocion::ingresarDatosPromocion(string nombre, string descripcion, DTFecha fechaVencimiento, int porcentaje) {
    this->promocionEnMemoria = Promocion(nombre, descripcion, fechaVencimiento, porcentaje);
    
}

vector<DTProducto> ControlPromocion::verProductosVendedor() {
    vector<DTProducto> dtProductos;
    unordered_map<int, Producto>::iterator it;
    for (it = productos.begin(); it != productos.end(); ++it) {
        Producto producto = it->second;
        if (producto.getVendedor() == this->vendedorEnMemoria) {
            DTProducto dtProducto = producto.toDTProducto();
            dtProductos.push_back(dtProducto);
        }
    }
    return dtProductos;
}

void ControlPromocion::agregarProductoPromocion(int idProducto, int cantidad) {
    unordered_map<int, Producto>::iterator it = productos.find(idProducto);
    if (it != productos.end()) {
        Producto producto = it->second;
        Requisitos requisito = Requisitos(cantidad, &producto);
        this->promocionEnMemoria.agregarRequisitos(requisito);
        
    }
}

Producto* ControlPromocion::getProductoByID(int idProducto){
    unordered_map<int, Producto>::iterator it = productos.find(idProducto);
    if (it != productos.end()) {
        return &(it->second);
    }
    return NULL; 

}

void ControlPromocion::confirmarPromocion() {
    if (this->promocionEnMemoria.getNombre().empty()) {
        return;
    }
    promociones[this->promocionEnMemoria.getNombre()] = this->promocionEnMemoria;
    // Como todos los productos de la promocion son del mismo vendedor, tomamos el primer requisito
    Vendedor* vendedor = this->promocionEnMemoria.getRequisitos()[0].getProducto()->getVendedor();
    string nombrePromo = this->promocionEnMemoria.getNombre();
    string nickVendedor = vendedor->getNickname();
    vector<int> codigosProductos;
    for (int i = 0; i < this->promocionEnMemoria.getRequisitos().size(); i++) {
        Requisitos requisito = this->promocionEnMemoria.getRequisitos()[i];
        codigosProductos.push_back(requisito.getProducto()->getId());
    }
    DTNotificacion notificacion(nombrePromo, nickVendedor, codigosProductos);
    vendedor->notificarObservers(notificacion);
    this->promocionEnMemoria = Promocion();
    this->vendedorEnMemoria = nullptr;
}

vector<DTInfoProducto> ControlPromocion::consultarProductosPromocion(string nombrePromocion) {
    vector<DTInfoProducto> dtInfoProductos;
    unordered_map<string, Promocion>::iterator it = promociones.find(nombrePromocion);
    if (it != promociones.end()) {
        vector<Requisitos> requisitos = it->second.getRequisitos();
        for (int j = 0; j < requisitos.size(); j++) {
            Producto* producto = requisitos[j].getProducto();
            DTInfoProducto dtInfoProducto = producto->toDTInfoProducto();
            dtInfoProductos.push_back(dtInfoProducto);
            
        }
    }
    return dtInfoProductos;
}

vector<DTPromocion> ControlPromocion::listarPromocionesVigentes() {
    vector<DTPromocion> dtPromociones;
    DTFecha fechaActual = controlFecha->getFechaActual();
    unordered_map<string, Promocion>::iterator it;
    for (it = promociones.begin(); it != promociones.end(); ++it) {
        Promocion promocion = it->second;
        if (promocion.getFechaVencimiento() >= fechaActual ) {
            DTPromocion dtPromocion = promocion.toDTPromocion();
            dtPromociones.push_back(dtPromocion);
        } 
    }
    return dtPromociones;
}


vector<DTDatosProducto> ControlPromocion::dataProductos(){
    vector <DTDatosProducto>  data;
    for (auto it = productos.begin(); it != productos.end(); ++it){
        data.push_back(it->second.toDTDatosProducto());
    }
    return data;
}

bool ControlPromocion::productoEnPromocion(int idProducto) {
    unordered_map<string, Promocion>::iterator it;
    for (it = promociones.begin(); it != promociones.end(); ++it) {
        Promocion promocion = it->second;
        vector<Requisitos> requisitos = promocion.getRequisitos();
        for (int i = 0; i < requisitos.size(); i++) {
            if (requisitos[i].getProducto()->getId() == idProducto) {
                return true;
            }
        }
    }
     return false;
}
vector<Requisitos> ControlPromocion::obtenerRequisitosPromocion(string nombre){
    auto it = promociones.find(nombre);
    if (it != promociones.end()) {
        return it->second.getRequisitos();
    }
    return {};
}

float ControlPromocion::calcularPrecioTotal(vector<DTDetalleProducto> parCompra) {
    float total = 0.0;
    // Primero, calcular el precio sin promociones
    for (auto it = parCompra.begin(); it != parCompra.end(); ++it) {
        Producto* producto = instance->getProductoByID(it->getCodigoProducto());
        if (producto != NULL) {
            total += producto->getPrecio() * it->getCantProducto();
        }
    }
    
     // Ahora verificar y aplicar promociones
     //Se asume que NUNCA existirá más de una promoción posible a aplicar.
    vector<DTPromocion> promociones = instance->listarPromocionesVigentes();
    
    for (auto promoIt = promociones.begin(); promoIt != promociones.end(); ++promoIt) {
        vector<Requisitos> requisitos = instance->obtenerRequisitosPromocion(promoIt->getNombre());
        
        bool cumplePromocion = true;
        float descuentoTotal = 0.0;

        // Verificar si se cumplen todos los requisitos de la promoción
        /*Se itera sobre los requisitos de una promoción, por cada requisito se itera sobre el vector 
        con los productos de la compra. Si hay un requisito que no se cumple, entonces no se aplica la promoción.*/
        for (auto req = requisitos.begin(); req != requisitos.end(); ++req) {
            cout << "Los nombres de los productos son: "<< endl;
            cout << req->getProducto()->getNombre()<< endl;
        } 
        
        /*for (auto reqIt = requisitos.begin(); reqIt != requisitos.end(); ++reqIt) {
            bool requisitoCumplido = false;

            for (auto it = parCompra.begin(); it != parCompra.end(); ++it) {
                if (reqIt->getProducto()->getId() == it->getCodigoProducto() && it->getCantProducto() >= reqIt->getMinimo()) {
                    cout << "El producto con codigo: " << to_string(it->getCodigoProducto()) << "TIENE MISMO ID QUE LA PROMO Y UNA CANTIDAD MAYOR O IGUAL AL MINIMO"<< endl;
                    float descuento = (reqIt->getProducto()->getPrecio() * it->getCantProducto()) * promoIt->getPorcentaje() / 100.0;
                    descuentoTotal += descuento;
                    requisitoCumplido = true;
                    break;
                }
            }

            if (!requisitoCumplido) {
                cumplePromocion = false;
                break;
            }
        }

        // Aplicar el descuento si todos los requisitos se cumplen
        if (cumplePromocion) {
            total -= descuentoTotal;
            break; // Solo aplicamos una promoción
        }*/
    }

    return total;
}

   



ControlPromocion::~ControlPromocion() {
}