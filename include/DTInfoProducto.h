#ifndef DTINFOPRODUCTO_H
#define DTINFOPRODUCTO_H

#include <string>

using namespace std;

enum class Categoria {
    Ropa,
    Electrodomestico,
    Otro
};

class DTInfoProducto {
private:
    int precio;
    int stock;
    string descripcion;
    string nickVendedor;
    Categoria categoria;

public:
    DTInfoProducto();
    DTInfoProducto(int precio, int stock, string descripcion, string nickVendedor, Categoria categoria);
};

#endif // DTINFOPRODUCTO_H