#include "Cantidad.h"

Cantidad::Cantidad(int cantidad, Producto* producto) {
    this->cantidad = cantidad;
    this->enviado = false;
    this->producto = producto;
}