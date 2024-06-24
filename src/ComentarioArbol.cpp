#include "ComentarioArbol.h"
#include "ComentarioNodo.h"
#include "DTFecha.h"
#include "Usuario.h"
#include "Producto.h"
#include <cstring>

ComentarioArbol::ComentarioArbol(Producto* prod) : producto(prod), raiz(nullptr) {}

ComentarioArbol::~ComentarioArbol() {
    eliminarComentario(raiz);
}

void ComentarioArbol::agregarComentario(const char* texto, Usuario* usuario, DTFecha fecha, ComentarioNodo* padre) {
    ComentarioNodo* nuevoNodo = new ComentarioNodo(texto, usuario, fecha);

    if (!padre) {
        if (!raiz) {
            raiz = nuevoNodo;
        } else {
            nuevoNodo->setHermano(raiz);
            raiz = nuevoNodo;
        }
    } else {
        if (!padre->getHijo()) {
            padre->setHijo(nuevoNodo);
        } else {
            ComentarioNodo* hermano = padre->getHijo();
            while (hermano->getHermano()) {
                hermano = hermano->getHermano();
            }
            hermano->setHermano(nuevoNodo);
        }
    }
}

bool ComentarioArbol::eliminarComentario(ComentarioNodo* nodo) {
    if (!nodo) return false;

    if (nodo == raiz) {
        raiz = nodo->getHermano();
        delete nodo;
        return true;
    }

    ComentarioNodo* padre = raiz;
    while (padre) {
        if (padre->getHijo() == nodo) {
            padre->setHijo(nodo->getHermano());
            delete nodo;
            return true;
        }
        ComentarioNodo* hermano = padre->getHijo();
        while (hermano && hermano->getHermano() != nodo) {
            hermano = hermano->getHermano();
        }
        if (hermano && hermano->getHermano() == nodo) {
            hermano->setHermano(nodo->getHermano());
            delete nodo;
            return true;
        }
        padre = padre->getHermano();
    }
    return false;
}

ComentarioNodo* ComentarioArbol::buscarComentario(const char* texto) {
    return buscarComentarioRecursivo(raiz, texto);
}

ComentarioNodo* ComentarioArbol::buscarComentarioRecursivo(ComentarioNodo* nodo, const char* texto) {
    if (!nodo) return nullptr;

    if (strcmp(nodo->getTexto(), texto) == 0) {
        return nodo;
    }

    ComentarioNodo* encontrado = buscarComentarioRecursivo(nodo->getHijo(), texto);
    if (encontrado) return encontrado;

    return buscarComentarioRecursivo(nodo->getHermano(), texto);
}