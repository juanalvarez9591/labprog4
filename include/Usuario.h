#ifndef USUARIO_H
#define USUARIO_H

#include <string>
#include "DTFecha.h"
using namespace std;

class Usuario {
public:
    Usuario(string nickname, string password, DTFecha fechaNacimiento);
    string getNickname();

protected:
    string nickname;
    string password;
    DTFecha fechaNacimiento;
};

#endif