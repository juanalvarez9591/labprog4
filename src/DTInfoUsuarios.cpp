#include "DTInfoUsuarios.h"
#include "DTFecha.h"

DTInfoUsuarios::DTInfoUsuarios(){
    this->nickname = "";
    this->fecha = DTFecha();
}

DTInfoUsuarios::DTInfoUsuarios(string nickname, DTFecha fecha){
    this->nickname = nickname;
    this->fecha = fecha;
}

string DTInfoUsuarios::getNickname(){
    return this->nickname;
}

DTFecha DTInfoUsuarios::getFecha(){
    return this->fecha;
}

DTInfoUsuarios::~DTInfoUsuarios() {
}