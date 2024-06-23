#include "Vendedor.h"
#include "DTNotificacion.h"

Vendedor::Vendedor(string nickname, string password, DTFecha fechaNacimiento, string rut) : Usuario(nickname, password, fechaNacimiento) {
    this->rut = rut;
}


bool Vendedor::estaSuscrito(IObserver* observer) {
    for (int i = 0; i < this->observers.size(); i++) {
        if (this->observers[i] == observer) {
            return true;
        }
    }
    return false;
}


string Vendedor::getNickname() const {
    return this->nickname;
}
DTFecha Vendedor::getFechaNacimiento() const {
    return this-> fechaNacimiento;
}
string Vendedor::getRut() const {
    return this-> rut;
}


void Vendedor::agregarObserver(IObserver* observer) {
    this->observers.push_back(observer);
}

void Vendedor::eliminarObserver(IObserver* observer) {
    for (int i = 0; i < this->observers.size(); i++) {
        if (this->observers[i] == observer) {
            this->observers.erase(this->observers.begin() + i);
            break;
        }
    }
}

void Vendedor::notificarObservers(DTNotificacion notificacion) {
    for (int i = 0; i < this->observers.size(); i++) {
        this->observers[i]->update(notificacion);
    }
}