#ifndef COMENTARIOARBOL_H
#define COMENTARIOARBOL_H

#include "Producto.h"
#include "Usuario.h"
#include "DTFecha.h"

class ComentarioNodo;

class ComentarioArbol {
private:
    Producto* producto;
    ComentarioNodo* raiz;

    ComentarioNodo* buscarComentarioRecursivo(ComentarioNodo* nodo, const char* texto);

public:
    ComentarioArbol(Producto* prod);
    ~ComentarioArbol();

    void agregarComentario(const char* texto, Usuario* usuario, DTFecha fecha, ComentarioNodo* padre = nullptr);
    void eliminarComentario(ComentarioNodo* nodo);
    ComentarioNodo* buscarComentario(const char* texto);
};

#endif