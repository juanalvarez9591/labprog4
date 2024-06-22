#ifndef PRODUCTO_H
#define PRODUCTO_H

#include <string>
#include "Vendedor.h"
#include "DTProducto.h"
#include "DTInfoProducto.h"
#include "Categoria.h"
#include "DTDatosProducto.h"

using namespace std;

class Producto {
public:
    Producto();
    Producto(string nombre, string descripcion, int id, int stock, int precio, Categoria categoria, Vendedor* vendedor);
    string getNombre();
    string getDescripcion();
    Categoria getCategoria();
    int getPrecio();
    int getId();
    int getStock();
    Vendedor* getVendedor() const;
    DTProducto toDTProducto() const;
    DTInfoProducto toDTInfoProducto() const;
    DTDatosProducto toDTDatosProducto() const;
    void actualizarStock(int cantidad);
    ~Producto();

private:
    string descripcion;
    string nombre;
    int id;
    int stock;
    int precio;
    Categoria categoria;
    Vendedor* vendedor;
};

#endif