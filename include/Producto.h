#ifndef PRODUCTO_H
#define PRODUCTO_H

#include <string>
#include "Vendedor.h"
using namespace std;

enum class CatProducto {
    Ropa,
    Electrodomestico,
    Otro
};

class Producto {
public:
    Producto(string nombre, string descripcion, int id, int stock, int precio, CatProducto categoria, Vendedor* vendedor);
    string getNombre();
    string getDescripcion();
    CatProducto getCategoria();
    int getPrecio();
    int getStock();
    ~Producto();

private:
    string descripcion;
    string nombre;
    int id;
    int stock;
    int precio;
    CatProducto categoria;
    Vendedor* vendedor;
};

#endif