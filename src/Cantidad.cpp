#include "Cantidad.h"

Cantidad::Cantidad(int cantidad, bool enviado, Producto* producto) {
    this->cantidad = cantidad;
    this->enviado = enviado;
    this->producto = producto;
}