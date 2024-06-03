#ifndef VENDEDOR_H
#define VENDEDOR_H

#include <string>

class Vendedor {
public:
    Vendedor(std::string nickname, std::string nombre, std::string apellido, std::string email, std::string password);

private:
    std::string nickname;
    std::string nombre;
    std::string apellido;
    std::string email;
    std::string password;
};

#endif