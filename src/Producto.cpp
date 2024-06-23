#include "Producto.h"
#include <iostream>
Producto::Producto() {
    this->nombre = "";
    this->descripcion = "";
    this->id = 0;
    this->stock = 0;
    this->precio = 0;
    this->categoria = Categoria::Otro;
    this->vendedor = nullptr;
}

Producto::Producto(string nombre, string descripcion, int id, int stock, float precio, Categoria categoria, Vendedor* vendedor) {
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

float Producto::getPrecio() {
    return this->precio;
}

int Producto::getId() {
    return this->id;
}

int Producto::getStock() {
    return this->stock;
}

Vendedor* Producto::getVendedor() const {
    return this->vendedor;
}

DTProducto Producto::toDTProducto() const {
    return DTProducto(this->nombre, this->id);
}


DTInfoProducto Producto::toDTInfoProducto() const {
    return DTInfoProducto(this->nombre, this->precio, this->stock, this->descripcion, this->vendedor->getNickname(), this->categoria);
}
DTDatosProducto Producto::toDTDatosProducto() const{
    return DTDatosProducto(this->stock, this->nombre, this->precio, this->id);
}

void Producto::actualizarStock(int cantidad) {
    stock -= cantidad;

    // Nunca deberia de pasar, pero en ese caso es bueno tener este check
    if (stock < 0) {
        stock = 0;
    }
}

Producto::~Producto() {
}