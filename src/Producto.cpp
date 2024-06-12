#include "Producto.h"

Producto::Producto(string nombre, string descripcion, int id, int stock, int precio, CatProducto categoria, Vendedor* vendedor) {
    this->nombre = nombre;
    this->descripcion = descripcion;
    this->id = id;
    this->stock = stock;
    this->precio = precio;
    this->categoria = categoria;
    this->vendedor = vendedor;
}

string Producto::getNombre() {
    return this->nombre;
}

string Producto::getDescripcion() {
    return this->descripcion;
}

CatProducto Producto::getCategoria() {
    return this->categoria;
}

int Producto::getPrecio() {
    return this->precio;
}

int Producto::getStock() {
    return this->stock;
}

Producto::~Producto() {
}