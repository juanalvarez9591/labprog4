#include "Producto.h"
#include <iostream>
#include "Comentario.h"

Producto::Producto() {
    this->nombre = "";
    this->descripcion = "";
    this->id = 0;
    this->stock = 0;
    this->precio = 0;
    this->categoria = Categoria::Otro;
    this->vendedor = nullptr;
    this->raizComentarios = nullptr;
}

Producto::Producto(string nombre, string descripcion, int id, int stock, float precio, Categoria categoria, Vendedor* vendedor) {
    this->nombre = nombre;
    this->descripcion = descripcion;
    this->id = id;
    this->stock = stock;
    this->precio = precio;
    this->categoria = categoria;
    this->vendedor = vendedor;
    this->raizComentarios = nullptr;
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

void Producto::agregarComentario(Comentario* comentario) {
    if (!raizComentarios) {
        raizComentarios = comentario;
    } else {
        Comentario* ultimo = raizComentarios;
        while (ultimo->getSig()) {
            ultimo = ultimo->getSig();
        }
        ultimo->setSig(comentario);
    }
}

Comentario* Producto::buscarComentario(const string& texto) {
    if (!raizComentarios) return nullptr;
    return raizComentarios->buscarComentario(texto);
}

void Producto::eliminarComentario(Comentario* comentario) {
    if (!raizComentarios) return;

    if (raizComentarios == comentario) {
        Comentario* temp = raizComentarios;
        raizComentarios = raizComentarios->getSig();
        delete temp;
    } else {
        Comentario* actual = raizComentarios;
        while (actual->getSig() && actual->getSig() != comentario) {
            actual = actual->getSig();
        }
        if (actual->getSig()) {
            Comentario* temp = actual->getSig();
            actual->setSig(temp->getSig());
            delete temp;
        }
    }
}

vector<string> Producto::listarComentarios() {
    vector<string> lista;
    if (raizComentarios) {
        raizComentarios->listarComentariosRecursivo(lista, 0);
    }
    return lista;
}

DTInfoProducto Producto::toDTInfoProducto() const {
    return DTInfoProducto(this->nombre, this->precio, this->stock, this->descripcion, this->vendedor->getNickname(), this->categoria);
}

DTDatosProducto Producto::toDTDatosProducto() const {
    return DTDatosProducto(this->stock, this->nombre, this->precio, this->id);
}

void Producto::actualizarStock(int cantidad) {
    stock -= cantidad;
    if (stock < 0) {
        stock = 0;
    }
}

Producto::~Producto() {
    // Delete all comments
    while (raizComentarios) {
        Comentario* temp = raizComentarios;
        raizComentarios = raizComentarios->getSig();
        delete temp;
    }
}