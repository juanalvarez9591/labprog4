#ifndef DTINFOPRODUCTO_H
#define DTINFOPRODUCTO_H

#include <string>
#include "Categoria.h"

using namespace std;

class DTInfoProducto {
private:
    string nombre;
    float precio;
    int stock;
    string descripcion;
    string nickVendedor;
    Categoria categoria;

public:
    DTInfoProducto();
    DTInfoProducto(string nombre, float precio, int stock, string descripcion, string nickVendedor, Categoria categoria);
    string toString() const;
    string getNombre() const;
    float getPrecio() const;
};

#endif // DTINFOPRODUCTO_H