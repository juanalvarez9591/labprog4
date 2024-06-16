#include "Producto.h"

Producto::Producto(string nombre, string descripcion, int id, int stock, int precio, Categoria categoria, Vendedor* vendedor) {
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

Categoria Producto::getCategoria() {
    return this->categoria;
}

int Producto::getPrecio() {
    return this->precio;
}

int Producto::getId() {
    return this->id;
}

int Producto::getStock() {
    return this->stock;
}

Vendedor* Producto::getVendedor() {
    return this->vendedor;
}

DTProducto Producto::toDTProducto() {
    return DTProducto(this->nombre, this->id);
}


DTInfoProducto Producto::toDTInfoProducto() {
    return DTInfoProducto(this->nombre, this->precio, this->stock, this->descripcion, this->vendedor->getNickname(), this->categoria);
}

Producto::~Producto() {
}