#ifndef USUARIO_H
#define USUARIO_H

#include <string>
#include "DTFecha.h"
using namespace std;

class Usuario {
public:
    Usuario(string nickname, string password, DTFecha fechaNacimiento);
    string getNickname();
    string getPassword();
    DTFecha getFechaNacimiento();

protected:
    string getNickname() const;
    string getPassword() const;
    DTFecha getFechaNacimiento() const;
};

#endif