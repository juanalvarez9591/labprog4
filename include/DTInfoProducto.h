// DTInfoProducto.h
#ifndef DTINFOPRODUCTO_H
#define DTINFOPRODUCTO_H

#include <string>
#include "Categoria.h"

using namespace std;

class DTInfoProducto {
private:
    string nombre;
    int precio;
    int stock;
    string descripcion;
    string nickVendedor;
    Categoria categoria;

public:
    DTInfoProducto();
    DTInfoProducto(string nombre, int precio, int stock, string descripcion, string nickVendedor, Categoria categoria);
    string toString() const;
};

#endif // DTINFOPRODUCTO_H