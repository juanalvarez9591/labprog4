#ifndef CANTIDAD_H
#define CANTIDAD_H

#include <string>   
#include "Producto.h"
using namespace std;

class Cantidad {
public:
    Cantidad(int cantidad, Producto* producto);

private:
    int cantidad;
    bool enviado;
    Producto* producto;
};

#endif