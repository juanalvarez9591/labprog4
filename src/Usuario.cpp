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
    auto iter = this->comentarios.begin();
    int pos = 1;
    while(iter != this->comentarios.end() && *iter != c) {
        pos++;
        ++iter;
    }
    if (pos <= this->comentarios.size()) {
        this->comentarios.erase(pos);
    }
}

vector<Comentario*> Usuario::getComentarios() {
    return this->comentarios;
}