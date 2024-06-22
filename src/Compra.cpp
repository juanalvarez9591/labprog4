#include "Compra.h"

Compra::Compra(DTFecha fechaCompra, Cliente* cliente) {
    this->fechaCompra = fechaCompra;
    this->costo = 0;
    this->cliente = cliente;
    this->cantidades = vector<Cantidad*>();
}

DTFecha Compra::getFechaCompra() {
    return this->fechaCompra;
}

void Compra::agregarCantidad(Cantidad* cantidad) {
    this->cantidades.push_back(cantidad);
}

void Compra::eliminarCantidad(Cantidad* cantidad) {
    for (auto it = this->cantidades.begin(); it != this->cantidades.end(); ++it) {
        if (*it == cantidad) {
            this->cantidades.erase(it);
            break;
        }
    }
}

vector<Cantidad*>& Compra::getCantidades() {
    return this->cantidades;
}