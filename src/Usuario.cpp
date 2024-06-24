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
