#include "DTInfoUsuarios.h"
#include "DTFecha.h"

DTInfoUsuarios::DTInfoUsuarios(){
    this->nickname = "";
    this->fechaNacimiento = DTFecha();
}

DTInfoUsuarios::DTInfoUsuarios(string nickname, DTFecha fechaNacimiento){
    this->nickname = nickname;
    this->fechaNacimiento = fechaNacimiento;
}

string DTInfoUsuarios::getNickname() const{
    return this->nickname;
}

DTFecha DTInfoUsuarios::getFechaNacimiento() const{
    return this->fechaNacimiento;
}

DTInfoUsuarios::~DTInfoUsuarios() {
}