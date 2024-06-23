#include "Requisitos.h"

Requisitos::Requisitos(int minimo, Producto* producto) {
    this->minimo = minimo;
    this->producto = producto;
}

int Requisitos::getMinimo() const {
    return minimo;
}

void Requisitos::setMinimo(int minimo) {
    this->minimo = minimo;
}

Producto* Requisitos::getProducto() const {
    return producto;
}

void Requisitos::setProducto(Producto* producto) {
    this->producto = producto;
}

bool Requisitos::operator==(const Requisitos& other) const {
    return minimo == other.minimo && producto == other.producto;
}