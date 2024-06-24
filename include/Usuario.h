#ifndef USUARIO_H
#define USUARIO_H

#include <string>
#include <vector>
#include <set>
#include "DTFecha.h"
using namespace std;

class Usuario {
public:
    Usuario(string nickname, string password, DTFecha fechaNacimiento);
    string getNickname() const;
    string getPassword() const;
    DTFecha getFechaNacimiento() const;
    virtual ~Usuario() = default;
    string getNickname();

protected:
    string nickname;
    string password;
    DTFecha fechaNacimiento;
};

#endif