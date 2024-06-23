#include "Cantidad.h"

Cantidad::Cantidad(int cantidad, Producto* producto) {
    this->cantidad = cantidad;
    this->enviado = false;
    this->producto = producto;
}

int Cantidad::getCantidad() const {
    return this->cantidad;
}

void Cantidad::setCantidad(int newCantidad) {
    this->cantidad = newCantidad;
}

Producto* Cantidad::getProducto() const {
    return this->producto;
}

bool Cantidad::getEnviado(){
    return this->enviado;
}