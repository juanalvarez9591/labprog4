#include "ComentarioNodo.h"
#include "Usuario.h"
#include <cstring>


ComentarioNodo::ComentarioNodo(const char* texto, Usuario* usuario, DTFecha* fecha)
        : usuario(usuario), fecha(fecha), hijo(nullptr), hermano(nullptr) {
    this->texto = new char[strlen(texto) + 1];
    strcpy(this->texto, texto);
}

ComentarioNodo::~ComentarioNodo() {
    delete[] texto;
    delete fecha;
}

Usuario* ComentarioNodo::getUsuario() const {
    return usuario;
}

const char* ComentarioNodo::getTexto() const {
    return texto;
}

DTFecha* ComentarioNodo::getFecha() const {
    return fecha;
}

ComentarioNodo* ComentarioNodo::getHijo() const {
    return hijo;
}

ComentarioNodo* ComentarioNodo::getHermano() const {
    return hermano;
}

void ComentarioNodo::setHijo(ComentarioNodo* nodo) {
    hijo = nodo;
}

void ComentarioNodo::setHermano(ComentarioNodo* nodo) {
    hermano = nodo;
}