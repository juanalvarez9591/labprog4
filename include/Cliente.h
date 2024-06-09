#ifndef CLIENTE_H
#define CLIENTE_H

#include <string>
#include <vector>
#include "Usuario.h"
/*
#include "DTNotificacion.h"
*/
using namespace std;

class Cliente: public Usuario {
public:
    Cliente(string nickname, string password, DTFecha fechaNacimiento, string direccion, string ciudad);

private:
    string direccion;
    string ciudad;
/*
    vector<DTNotificacion> notificaciones;
*/
};

#endif