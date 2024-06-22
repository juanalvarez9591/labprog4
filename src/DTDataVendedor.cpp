#include "DTDataVendedor.h"
#include "DTFecha.h"

DTDataVendedor::DTDataVendedor(string nickname, DTFecha fechaNacimiento, string rut) {
    this->rut = rut;
    this-> nickname = nickname;
    this-> fechaNacimiento = fechaNacimiento;
}

string DTDataVendedor::getRut() const {
    return this->rut;
}

string DTDataVendedor::getNickname() const{
    return this->nickname;

}

DTFecha DTDataVendedor::getFechaNacimiento() const {
    return this->fechaNacimiento;
}