#include "Vendedor.h"

Vendedor::Vendedor(string nickname, string password, DTFecha fechaNacimiento, int rut) : Usuario(nickname, password, fechaNacimiento) {
    this->rut = rut;
}