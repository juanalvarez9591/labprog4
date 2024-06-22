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
    ~Producto();

    Comentario* GetComentarios();
    void SetComentario(Comentario* Nuevaraiz);

    void PrintTodosComentarios();
    void PrintComentario(Comentario *Comentario, int Sangria);
    Comentario* GetComentario(string Text);
private:
    string descripcion;
    string nombre;
    int id;
    int stock;
    int precio;
    Categoria categoria;
    Vendedor* vendedor;
    Comentario* Foro;
    void PrintTodosComentariosAux(Comentario *Comentario, int Sangria);
    Comentario *Estecomentario(Comentario *It, string Text);
};

#endif