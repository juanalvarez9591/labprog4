#include "ControlComentario.h"
#include "ControlUsuario.h"
#include "ControlPromocion.h"
#include "ControlFecha.h"

using namespace std;

ControlComentario* ControlComentario::instance = nullptr;

ControlComentario* ControlComentario::getInstance() {
    if (instance == nullptr) {
        instance = new ControlComentario();
    }
    return instance;
}

ControlComentario::ControlComentario() {
    controlUsuario = ControlUsuario::getInstance();
    controlPromocion = ControlPromocion::getInstance();
    controlFecha = ControlFecha::getInstance();
    usuarioEnMemoria = nullptr;
    productoEnMemoria = nullptr;
    comentarioEnMemoria = "";
    arboles = vector<ComentarioArbol*>();
}

ControlComentario::~ControlComentario() {
    for (ComentarioArbol* arbol : arboles) {
        delete arbol;
    }
}

void ControlComentario::seleccionarUsuario(string nickUsuario) {
    usuarioEnMemoria = controlUsuario->getUsuario(nickUsuario);
}

void ControlComentario::seleccionarProducto(int codigoProducto) {
    productoEnMemoria = controlPromocion->getProductoByID(codigoProducto);
}

void ControlComentario::realizarComentario(string texto) {
    if (usuarioEnMemoria != nullptr && productoEnMemoria != nullptr) {
        DTFecha fechaActual = controlFecha->getFechaActual();
    }
}

string ControlComentario::listarComentarios() {
    if (productoEnMemoria != nullptr) {
    }
    return "";
}

bool ControlComentario::elegirComentario(string texto) {
    if (productoEnMemoria != nullptr) {
        ComentarioArbol* arbol = buscarArbol(productoEnMemoria->getCodigo());
        if (arbol != nullptr) {
            comentarioNodoEnMemoria = arbol->buscarComentario(texto.c_str());
            if (comentarioNodoEnMemoria) {
                comentarioEnMemoria = texto;
                return true;
            }
        }
    }
    comentarioEnMemoria = "";
    comentarioNodoEnMemoria = nullptr;
    return false;
}

bool ControlComentario::eliminarComentario() {
    if (productoEnMemoria != nullptr && comentarioNodoEnMemoria != nullptr) {
        ComentarioArbol* arbol = buscarArbol(productoEnMemoria->getCodigo());
        if (arbol != nullptr) {
            bool resultado = arbol->eliminarComentario(comentarioNodoEnMemoria);
            if (resultado) {
                comentarioEnMemoria = "";
                comentarioNodoEnMemoria = nullptr;
            }
            return resultado;
        }
    }
    return false;
}

void ControlComentario::responderComentario(string texto) {
    if (productoEnMemoria != nullptr && usuarioEnMemoria != nullptr && !comentarioEnMemoria.empty()) {
        DTFecha fechaActual = controlFecha->getFechaActual();
    }
}