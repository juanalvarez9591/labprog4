#ifndef PRODUCTO_H
#define PRODUCTO_H

#include <string>
#include "Comentario.h"
using namespace std;

enum class CatProducto {
    Ropa,
    Electrodomestico,
    Otro
};  // para revisar si lo guardado es de un tipo parece qeu se usa (Variable.CatProducto::Ropa) y eso puede dar true o false

class Producto {
public:
    Producto(string Nombre, string Descripcion, int Id, int stock, int precio, CatProducto Categoria);
    ~Producto();

    void GetDTProducto();
    
    string GetNombre();
    string GetDescripcion();
    CatProducto GetCategoria();
    int GetPrecio();
    int GetStock();

    //Medio para quitar del stock cosas vendidas + posible forma de ver si se pide mas de lo que se tiene
    bool RestarAStock(int Vendidos);
    //No se si se pide restock pero por las dudas
    // void Restock(int envio);

    Comentario GetComentario(string Text);
    void AgregarComentario(Comentario *Comenario);
    void AgregarRespuesta(Comentario *Comentario, string Text);

private:
    string Descripcion;
    string Nombre;
    int Id;
    int Stock;
    int Precio;
    CatProducto Categoria;
    Comentario Foro;
};

#endif