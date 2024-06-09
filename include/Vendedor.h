#ifndef VENDEDOR_H
#define VENDEDOR_H

#include <string>
using namespace std;

class Vendedor {
public:
    Vendedor(string nickname, string nombre, string apellido, string email, string password);

private:
    string nickname;
    string nombre;
    string apellido;
    string email;
    string password;
};

#endif