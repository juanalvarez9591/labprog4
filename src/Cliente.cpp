#include "Cliente.h"

Cliente::Cliente(string nickname, string password, DTFecha fechaNacimiento, int nroPuerta,  string calle, string ciudad) : Usuario(nickname, password, fechaNacimiento) {
    this->calle = calle;
    this->ciudad = ciudad;
    this->nroPuerta = nroPuerta;
    this->notificaciones = vector<DTNotificacion>();
}

void Cliente::update(DTNotificacion notificacion) {
    notificaciones.push_back(notificacion);
}

vector<DTNotificacion> Cliente::listarNotificaciones() {
    return notificaciones;
}

void Cliente::limpiarNotificaciones() {
    notificaciones.clear();
}

string Cliente::getNickname() const {
    return nickname;
}
DTFecha Cliente::getFechaNacimiento() const {
    return this->fechaNacimiento;
}
string Cliente::getCalle() const {
        return this-> calle;
}
string Cliente::getCiudad() const {
        return this->ciudad;
}
int Cliente::getNroPuerta() const {
        return this->nroPuerta;
    }

