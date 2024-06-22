#include "DTProducto.h"

DTProducto::DTProducto(string Nombre, int Id) {
    this->Nombre = Nombre;
    this->Id = Id;
}

DTProducto::DTProducto() {
    this->Nombre = "";
    this->Id = 0;
}

string DTProducto::getNombre() const {
    return this->Nombre;
}

int DTProducto::getId() const {
    return this->Id;
}