#include "Cliente.h"

Cliente::Cliente(string nickname, string password, DTFecha fechaNacimiento, string direccion, string ciudad) : Usuario(nickname, password, fechaNacimiento) {
    this->direccion = direccion;
    this->ciudad = ciudad;
    this->notificaciones = vector<DTNotificacion>();
}