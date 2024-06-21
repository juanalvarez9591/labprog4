#include "DTInfoProducto.h"

DTInfoProducto::DTInfoProducto() {
    this->nombre = "";
    this->precio = 0;
    this->stock = 0;
    this->descripcion = "";
    this->nickVendedor = "";
    this->categoria = Categoria::Otro;
}

DTInfoProducto::DTInfoProducto(string nombre, int precio, int stock, string descripcion, string nickVendedor, Categoria categoria) {
    this->nombre = nombre;
    this->precio = precio;
    this->stock = stock;
    this->descripcion = descripcion;
    this->nickVendedor = nickVendedor;
    this->categoria = categoria;
}

string DTInfoProducto::toString() const {
    return "Nombre: " + nombre + "\n" +
            "Descripcion del producto: " + descripcion + "\n" +
            "Precio: $" + to_string(precio) + "\n" +
            "Stock: " + to_string(stock) + "\n" +
            "Vendedor: " + nickVendedor + "\n" +
            "Categoria: " + ::toString(categoria) + "\n";
}