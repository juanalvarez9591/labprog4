#ifndef COMENTARIOARBOL_H
#define COMENTARIOARBOL_H

#include "Producto.h"
#include "Usuario.h"
#include "DTFecha.h"
#include "ComentarioNodo.h"

class ComentarioArbol {
private:
    Producto* producto;
    ComentarioNodo* raiz;

    ComentarioNodo* buscarComentarioRecursivo(ComentarioNodo* nodo, const char* texto);

public:
    ComentarioArbol(Producto* prod);
    ~ComentarioArbol();

    Producto* getProducto() const { return producto; }
    ComentarioNodo* getRaiz() const { return raiz; }

    void agregarComentario(const char* texto, Usuario* usuario, DTFecha fecha, ComentarioNodo* padre = nullptr);
    bool eliminarComentario(ComentarioNodo* nodo);
    ComentarioNodo* buscarComentario(const char* texto);
};

#endif