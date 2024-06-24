#ifndef PRODUCTO_H
#define PRODUCTO_H

#include <string>
#include "Vendedor.h"
#include "DTProducto.h"
#include "DTInfoProducto.h"
#include "Categoria.h"
#include "Comentario.h"
#include "DTDatosProducto.h"

using namespace std;

class Producto {
public:
    Producto();
    Producto(string nombre, string descripcion, int id, int stock, float precio, Categoria categoria, Vendedor* vendedor);
    string getNombre();
    string getDescripcion();
    Categoria getCategoria();
    float getPrecio();
    int getId();
    int getStock();
    Vendedor* getVendedor() const;
    DTProducto toDTProducto() const;
    DTInfoProducto toDTInfoProducto() const;
    DTDatosProducto toDTDatosProducto() const;
    void actualizarStock(int cantidad);
    ~Producto();

    void agregarComentario(Comentario* comentario);
    Comentario* buscarComentario(const string& texto);
    void eliminarComentario(Comentario* comentario);
    vector<string> listarComentarios();
private:
    string descripcion;
    string nombre;
    int id;
    int stock;
    float precio;
    Categoria categoria;
    Vendedor* vendedor;
    Comentario* raizComentarios;
};

#endif