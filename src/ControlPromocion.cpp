#include "ControlPromocion.h"
#include "ControlUsuario.h"
#include "ControlFecha.h"
#include "DTPromocion.h"
#include "DTInfoProducto.h"
#include "DTProducto.h"
#include "Categoria.h"
#include "Vendedor.h"
#include "DTDatosProducto.h"
#include "DTNotificacion.h"
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

vector<DTPromocion> ControlPromocion::verPromocionesVendedor(string nickVendedor) {
    vector<DTPromocion> promocionesVendedor;
    Vendedor* vendedor = controlUsuario->getVendedor(nickVendedor);

    if (vendedor == nullptr) {
        return promocionesVendedor;
    }

    for (const auto& pair : promociones) {
        const Promocion& promocion = pair.second;
        const vector<Requisitos>& requisitos = promocion.getRequisitos();

        bool perteneceAVendedor = false;
        for (const Requisitos& req : requisitos) {
            if (req.getProducto()->getVendedor() == vendedor) {
                perteneceAVendedor = true;
                break;
            }
        }

        if (perteneceAVendedor) {
            promocionesVendedor.push_back(promocion.toDTPromocion());
        }
    }

    return promocionesVendedor;
}
bool ControlPromocion::crearProducto(string nombre, float precio, int stock, string descripcion, string categoria, string vendedorElegido){
    Vendedor* vendedor = controlUsuario->getVendedor(vendedorElegido);
    if (vendedor == NULL){
        return false;
    }
    Categoria cat = fromString(categoria);
    int codigoProducto = productos.size() + 1;
    Producto producto = Producto(nombre, descripcion, codigoProducto, stock, precio, cat, vendedor);
    productos[codigoProducto] = producto;
    return true;
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

vector<DTProducto> ControlPromocion::verProductosVendedorEnMemoria() {
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
        Producto* productoPtr = &(it->second);
        Requisitos requisito(cantidad, productoPtr);
        this->promocionEnMemoria.agregarRequisitos(requisito);
    }
}

Producto* ControlPromocion::getProductoByID(int idProducto){
    unordered_map<int, Producto>::iterator it = productos.find(idProducto);
    if (it != productos.end()) {
        return &(it->second);
    }
    return nullptr;
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
    vector<string> nombreProductos;
    for (int i = 0; i < this->promocionEnMemoria.getRequisitos().size(); i++) {
        Requisitos requisito = this->promocionEnMemoria.getRequisitos()[i];
        codigosProductos.push_back(requisito.getProducto()->getId());
        nombreProductos.push_back(requisito.getProducto()->getNombre());
    }
    DTNotificacion notificacion(nombrePromo, nickVendedor, codigosProductos, nombreProductos);
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

set<DTPromocion> ControlPromocion::listarPromocionesVigentes() {
    set<DTPromocion> dtPromociones;
    DTFecha fechaActual = controlFecha->getFechaActual();
    for (const auto& pair : promociones) {
        const Promocion& promocion = pair.second;
        if (promocion.getFechaVencimiento() >= fechaActual) {
            dtPromociones.insert(promocion.toDTPromocion());
        }
    }
    return dtPromociones;
}


vector<DTDatosProducto> ControlPromocion::listarDataProductos(){
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

vector<DTProducto> ControlPromocion::verProductosVendedor(string nickUsuario) {
    vector<DTProducto> dtProductos;
    Vendedor* vendedor = controlUsuario->getVendedor(nickUsuario);

    if (vendedor == nullptr) {
        return dtProductos;
    }

    unordered_map<int, Producto>::const_iterator it;
    for (it = productos.begin(); it != productos.end(); ++it) {
        const Producto& producto = it->second;
        if (producto.getVendedor() == vendedor) {
            dtProductos.push_back(producto.toDTProducto());
        }
    }

    return dtProductos;
}

float ControlPromocion::calcularPrecioTotal(int codigoProducto, int cantidad) {
    float total = 0.0;

    Producto* producto = getProductoByID(codigoProducto);
    if (producto != NULL) {
        total = producto->getPrecio() * cantidad;
    } else {
        return total;
    }

    set<DTPromocion> promocionesVigentes = listarPromocionesVigentes();

    for (const DTPromocion& promo : promocionesVigentes) {
        vector<Requisitos> requisitos = obtenerRequisitosPromocion(promo.getNombre());

        bool cumplePromocion = true;
        float descuento = 0.0;

        for (const Requisitos& req : requisitos) {
            if (req.getProducto()->getId() == codigoProducto && cantidad >= req.getMinimo()) {
                descuento = total * (promo.getPorcentaje() / 100.0);
            } else {
                cumplePromocion = false;
                break;
            }
        }

        if (cumplePromocion) {
            total -= descuento;
            break;
        }
    }

    return total;
}

ControlPromocion::~ControlPromocion() {
}