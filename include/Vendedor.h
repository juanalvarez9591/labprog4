#ifndef VENDEDOR_H
#define VENDEDOR_H

#include <string>
#include "Usuario.h"

using namespace std;

class Vendedor : public Usuario {
public:
    Vendedor(string nickname, string password, DTFecha fechaNacimiento, int rut);

private:
    int rut;
};

#endif