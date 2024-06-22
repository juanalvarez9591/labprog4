#include "DTDataVendedor.h"
#include "DTFecha.h"

DTDataVendedor::DTDataVendedor(string nickname, DTFecha fecha, string rut) : DTInfoUsuarios(nickname, fecha) {
    this->rut = rut;
}

string DTDataVendedor::getRut() {
    return this->rut;
}