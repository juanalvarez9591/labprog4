#ifndef COMENTARIONODO_H
#define COMENTARIONODO_H

#include "Usuario.h"
#include "DTFecha.h"

class ComentarioNodo {
private:
    Usuario* usuario;
    char* texto;
    DTFecha fecha;
    ComentarioNodo* hijo;
    ComentarioNodo* hermano;

public:
    ComentarioNodo(const char* texto, Usuario* usuario, DTFecha fecha);
    ~ComentarioNodo();

    Usuario* getUsuario() const;
    const char* getTexto() const;
    DTFecha getFecha() const;
    ComentarioNodo* getHijo() const;
    ComentarioNodo* getHermano() const;

    void setHijo(ComentarioNodo* nodo);
    void setHermano(ComentarioNodo* nodo);
};

#endif