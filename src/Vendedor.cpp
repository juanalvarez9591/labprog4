#include "Vendedor.h"

Vendedor::Vendedor(string nickname, string password, DTFecha fechaNacimiento, int rut) : Usuario(nickname, password, fechaNacimiento) {
    this->rut = rut;
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
        this->observers[i]->notify(message);
    }
}