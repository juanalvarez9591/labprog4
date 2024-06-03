#ifndef CLIENTE_H
#define CLIENTE_H

#include <string>
#include <vector>
#include "DTNotificacion.h"

class Cliente {
public:
    Cliente(std::string nickname, std::string nombre, std::string apellido, std::string email, std::string password);

private:
    std::string nickname;
    std::string nombre;
    std::string apellido;
    std::string email;
    std::string password;
    std::vector<DTNotificacion> notificaciones;
};

#endif