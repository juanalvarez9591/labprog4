#include "DTDataVendedor.h"
#include "DTFecha.h"

DTDataVendedor::DTDataVendedor(string nickname, DTFecha fecha, int rut) : DTInfoUsuarios(nickname, fecha) {
    this->rut = rut;
}

int DTDataVendedor::getRut() {
    return this->rut;
}