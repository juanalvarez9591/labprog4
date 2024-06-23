#include "DTExpCompra.h"

DTExpCompra::DTExpCompra() {
    this->costo = 0;
    this->fechaCompra = DTFecha();
    this->productos = vector<DTExpProducto>();
}

DTExpCompra::DTExpCompra(float costo, DTFecha fechaCompra, vector<DTExpProducto> productos) {
    this->costo = costo;
    this->fechaCompra = fechaCompra;
    this->productos = productos;
}

float DTExpCompra::getCosto() const {
    return this->costo;
}

DTFecha DTExpCompra::getFecha() const {
    return this->fechaCompra;
}

vector<DTExpProducto> DTExpCompra::getProductos() const {
    return this->productos;
}