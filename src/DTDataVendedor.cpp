#include "../include/DTDataVendedor.h"


DTDataVendedor::DTDataVendedor(string nickname, DTFecha fecha, int rut) : DTInfoUsuarios(nickname, fecha) {
    this-> rut = rut;
    

}
string DTDataVendedor::getRut(){
    return this->rut;

}

