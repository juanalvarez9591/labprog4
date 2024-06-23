#include <vector>
#include "Comentario.h"
#include "Usuario.h"

Usuario::Usuario(string nickname, string password, DTFecha fechaNacimiento)
        : nickname(nickname), password(password), fechaNacimiento(fechaNacimiento) {
}

string Usuario::getNickname() const {
    return nickname;
}

string Usuario::getPassword() const {
    return password;
}

DTFecha Usuario::getFechaNacimiento() const {
    return fechaNacimiento;
}

void Usuario::addComentario(Comentario* c) {
    this->comentarios.push_back(c);
}

void Usuario::olvidarComentario(Comentario* c) {
    auto iter = this->comentarios.begin();
    //int pos = 1;

    while(iter != this->comentarios.end() && (*iter != c)) {
        //pos++;
        ++iter;
    }
    /*if (pos <= this->comentarios.size()) {
        this->comentarios.erase(pos);
    }*/
    if (iter != this->comentarios.end()) {
        this->comentarios.erase(iter);
    }
}

vector<Comentario*> Usuario::getComentarios() {
    return this->comentarios;
}