#include "Usuario.h"

Usuario::Usuario(string nickname, string password, DTFecha fechaNacimiento) {
    this->nickname = nickname;
    this->password = password;
    this->fechaNacimiento = fechaNacimiento;
}

string Usuario::getNickname() {
    return nickname;
}

void Usuario::addComentario(Comentario c) {
    this->comentarios.push_back(c);
}

void Usuario::olvidarComentario(Comentario c) {
    this->comentarios.erase(c);
}

vector<Comentario*> Usuario::getComentarios() {
    return this->comentarios;
}