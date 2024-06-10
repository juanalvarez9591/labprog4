#include "../include/DTInfoProducto.h"

DTInfoProducto::DTInfoProducto() {
    this->precio = 0;
    this->stock = 0;
    this->descripcion = "";
    this->nickVendedor = "";
    this->categoria = Categoria::Otro;
}

DTInfoProducto::DTInfoProducto(int precio, int stock, string descripcion, string nickVendedor, Categoria categoria) {
    this->precio = precio;
    this->stock = stock;
    this->descripcion = descripcion;
    this->nickVendedor = nickVendedor;
    this->categoria = categoria;
}