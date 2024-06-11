#include "Vendedor.h"

Vendedor::Vendedor(string nickname, string password, DTFecha fechaNacimiento, int rut) : Usuario(nickname, password, fechaNacimiento) {
    this->rut = rut;
}

bool Vendedor::estaSuscrito(Usuario* usuario) {
    for (int i = 0; i < this->observers.size(); i++) {
        if (this->observers[i]->getNickname() == usuario->getNickname()) {
            return true;
        }
    }
    return false;
}

string Vendedor::getNickname() {
    return this->nickname;
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

void Vendedor::notificarObservers(std::string message) {
    for (int i = 0; i < this->observers.size(); i++) {
        this->observers[i]->update(message);
    }
}