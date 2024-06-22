#include "Compra.h"

Compra::Compra(DTFecha fechaCompra, Cliente* cliente) {
    this->fechaCompra = fechaCompra;
    this->costo = 0;
      this->cliente = cliente;
    this->cantidades = vector<Cantidad*>();
}

void Compra::agregarCantidad(Cantidad* cantidad) {
    this->cantidades.push_back(cantidad);
}

void Compra::eliminarCantidad(Cantidad* cantidad) {
    for (int i = 0; i < this->cantidades.size(); i++) {
        if (this->cantidades[i] == cantidad) {
            this->cantidades.erase(this->cantidades.begin() + i);
            break;
        }
    }
}

vector<Cantidad*> Compra::getCantidades() {
    return this->cantidades;
}
