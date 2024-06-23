#include "DTDataCliente.h"


#include "../include/DTDataCliente.h"

DTDataCliente::DTDataCliente(){
    
}

DTDataCliente::DTDataCliente(string nickname, DTFecha fechaNacimiento, int nroPuerta, string calle, string ciudad): DTInfoUsuarios(nickname, fechaNacimiento) {
    this-> ciudad = ciudad;
    this-> calle = calle;
    this->nroPuerta = nroPuerta;
}


string DTDataCliente::getCalle() const{
    return this->calle;

}

string DTDataCliente::getCiudad() const{
    return this->ciudad;
}


int DTDataCliente::getNroPuerta() const {
    return this-> nroPuerta;
}

DTDataCliente::~DTDataCliente() {

}