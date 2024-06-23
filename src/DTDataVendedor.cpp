#include "DTDataVendedor.h"
#include "DTFecha.h"


DTDataVendedor::DTDataVendedor(string nickname, DTFecha fechaNacimiento, string rut): DTInfoUsuarios(nickname, fechaNacimiento) {

    this->rut = rut;
   
}


string DTDataVendedor::getRut() const {

    return this->rut;
}

