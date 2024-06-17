#include "ControlPromocion.h"
#include "ControlUsuario.h"
#include "ControlFecha.h"
#include "DTPromocion.h"
#include "DTInfoProducto.h"
#include "DTProducto.h"
#include "Categoria.h"
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
        if (fechaActual >= promocion.getFechaVencimiento()) {
            DTPromocion dtPromocion = promocion.toDTPromocion();
            dtPromociones.push_back(dtPromocion);
        }
    }
    return dtPromociones;
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

vector <DTInfoProducto> ControlPromocion::infoProductos(){




}

ControlPromocion::~ControlPromocion() {
}