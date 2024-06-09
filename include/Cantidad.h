#ifndef CANTIDAD_H
#define CANTIDAD_H

#include <string>   
#include "Producto.h"
using namespace std;

class Cantidad {
public:
    Cantidad(int cant, bool enviado);

private:
    int cant;
    bool enviado;
};

#endif