#include "DTDataCliente.h"


#include "../include/DTDataCliente.h"


DTDataCliente::DTDataCliente(string nickname, DTFecha fechaNacimiento, int nroPuerta, string calle, string ciudad) {
    this-> nickname = nickname;
    this-> ciudad = ciudad;
    this-> fechaNacimiento = fechaNacimiento;
    this-> calle = calle;
    this->nroPuerta = nroPuerta;
    

DTDataCliente::DTDataCliente(string nickname, DTFecha fecha, string direccion, string ciudad)
        : DTInfoUsuarios(nickname, fecha), direccion(direccion), ciudad(ciudad) {
}

string DTDataCliente::getCalle() const{
    return this->calle;


string DTDataCliente::getDireccion() {
    return this->direccion;
}


string DTDataCliente::getCiudad() const{
    return this->ciudad;
}
string DTDataCliente::getNickname() const{
    return this->nickname;
}

DTFecha DTDataCliente::getFechaNacimiento() const{
    return this-> fechaNacimiento;
}

int DTDataCliente::getNroPuerta() const {
    return this-> nroPuerta;


DTDataCliente::~DTDataCliente() {

}