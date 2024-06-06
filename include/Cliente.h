#ifndef CLIENTE_H
#define CLIENTE_H

#include <string>
#include <vector>
#include "DTNotificacion.h"
using namespace std;

class Cliente {
public:
    Cliente(string nickname, string nombre, string apellido, string email, string password);

private:
    string nickname;
    string nombre;
    string apellido;
    string email;
    string password;
    vector<DTNotificacion> notificaciones;
};

#endif