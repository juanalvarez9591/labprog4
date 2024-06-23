#ifndef CANTIDAD_H
#define CANTIDAD_H

#include <string>
#include "Producto.h"
using namespace std;

class Cantidad {
public:
    Cantidad(int cantidad, Producto* producto);
    int getCantidad() const;
    void setCantidad(int newCantidad);
    Producto* getProducto() const;
    bool getEnviado();
    void setEnviado(bool estado);

private:
    int cantidad;
    bool enviado;
    Producto* producto;
};

#endif