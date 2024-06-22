#ifndef REQUISITOS_H
#define REQUISITOS_H

#include <string>
#include "Producto.h"
using namespace std;

class Requisitos {
public:
    Requisitos(int minimo, Producto* producto);

    int getMinimo() const;
    void setMinimo(int minimo);

    Producto* getProducto() const;
    void setProducto(Producto* producto);

    bool operator==(const Requisitos& other) const;

private:
    int minimo;
    Producto* producto;
};

#endif