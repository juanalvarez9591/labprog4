#include "Cliente.h"

Cliente::Cliente(string nickname, string password, DTFecha fechaNacimiento, string direccion, string ciudad) : Usuario(nickname, password, fechaNacimiento) {
    this->direccion = direccion;
    this->ciudad = ciudad;
    this->notificaciones = vector<DTNotificacion>();
}

void Cliente::update(string message) {
    DTNotificacion notificacion = DTNotificacion(message, "test", vector<DTInfoProducto>());
    notificaciones.push_back(notificacion);
}

vector<DTNotificacion> Cliente::listarNotificaciones() {
    return notificaciones;
}

void Cliente::limpiarNotificaciones() {
    notificaciones.clear();
}

string Cliente::getNickname() {
    return nickname;
}