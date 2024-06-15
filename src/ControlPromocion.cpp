#include "ControlPromocion.h"
#include "ControlUsuario.h"
#include "DTPromocion.h"
#include "DTInfoProducto.h"
#include "DTProducto.h"

class ControlUsuario;

ControlPromocion* ControlPromocion::instance = nullptr;

ControlPromocion* ControlPromocion::getInstance() {
    if (instance == nullptr) {
        instance = new ControlPromocion();
    }
    return instance;
}

ControlPromocion::ControlPromocion() {
    controlUsuario = ControlUsuario::getInstance();

    productos = vector<Producto>();
    promociones = vector<Promocion>();
    requisitos = vector<Requisitos>();
}

set<string> ControlPromocion::listarNicknameVendedores() {
    vector<Vendedor> vendedores = controlUsuario->getVendedores();
    set<string> nicknames;
    for (int i = 0; i < vendedores.size(); i++) {
        nicknames.insert(vendedores[i].getNickname());
    }
    return nicknames;
}

void ControlPromocion::elegirVendedor(string nickVendedor) {
    return;
}

void ControlPromocion::ingresarProducto(string nombre, string descripcion, float precio, int stock, string categoria) {
    return;
}

set<DTProducto> ControlPromocion::listarProductos() {
    return set<DTProducto>();
}

DTInfoProducto ControlPromocion::verInfoProducto(int idProducto) {
    return DTInfoProducto();
}

void ControlPromocion::ingresarDatosPromocion(string nombre, string descripcion, DTFecha fechaVencimiento, int porcentaje) {
    return;
}

set<DTProducto> ControlPromocion::verProductosVendedor() {
    return set<DTProducto>();
}

void ControlPromocion::agregarProductoPromocion(int idProducto, int cantidad) {
    return;
}

void ControlPromocion::confirmarPromocion() {
    return;
}

set<DTInfoProducto> ControlPromocion::consultarProductosPromocion(string nombrePromocion) {
    return set<DTInfoProducto>();
}

ControlPromocion::~ControlPromocion() {
}