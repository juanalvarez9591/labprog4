#include "DTDatosProducto.h"

DTDatosProducto::DTDatosProducto(int stock, string nombreProducto, int precio, int codigoProducto) {
    this->stock = stock;
    this->nombreProducto = nombreProducto;
    this->precio = precio;
    this->codigoProducto = codigoProducto;
}

string DTDatosProducto::toString() const {
    return "Nombre: " + nombreProducto + "\n" +
           "Precio: $" + to_string(precio) + "\n" +
           "Stock: " + to_string(stock) + "\n" +
           "Código: " + to_string(codigoProducto) + "\n";
}

int DTDatosProducto::getCodigo() const {
    return this->codigoProducto;
}

int DTDatosProducto::getStock() const {
    return this->stock;
}

int DTDatosProducto::getPrecio() const {
    return this->precio;
}

string DTDatosProducto::getNombre() const {
    return this->nombreProducto;
}