#include "DTDataCliente.h"

DTDataCliente::DTDataCliente(string nickname, DTFecha fecha, string direccion, string ciudad)
        : DTInfoUsuarios(nickname, fecha), direccion(direccion), ciudad(ciudad) {}

string DTDataCliente::getDireccion() {
    return this->direccion;
}

string DTDataCliente::getCiudad() {
    return this->ciudad;
}