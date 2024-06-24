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
    usuarioEnMemoria = "";
    productoEnMemoria = -1;
    comentarioEnMemoria = "";
    arboles = vector<ComentarioArbol*>();
}

ControlComentario::~ControlComentario() {
    for (ComentarioArbol* arbol : arboles) {
        delete arbol;
    }
}


void ControlComentario::seleccionarUsuario(string nickUsuario) {
    usuarioEnMemoria = nickUsuario;

}

void ControlComentario::seleccionarProducto(int codigoProducto) {
    productoEnMemoria = codigoProducto;
}

bool ControlComentario::realizarComentario(string texto) {
    if (!usuarioEnMemoria.empty() && productoEnMemoria != -1) {
        DTFecha fechaActual = controlFecha->getFechaActual();
        ComentarioArbol* arbol = buscarArbol(productoEnMemoria);
        if (arbol == nullptr) {
            Producto* producto = controlPromocion->getProductoByID(productoEnMemoria);
            arbol = new ComentarioArbol(producto);
            arboles.push_back(arbol);
        }
        Usuario* usuario = controlUsuario->getUsuario(usuarioEnMemoria);
        arbol->agregarComentario(texto.c_str(), usuario, fechaActual);
        return true;
    }
    return false;
}

string ControlComentario::listarComentarios() {
    if (productoEnMemoria != -1) {
        ComentarioArbol* arbol = buscarArbol(productoEnMemoria);
        if (arbol != nullptr) {
            return listarComentariosRecursivo(arbol->getRaiz(), 0);
        }
    }
    return "";
}

bool ControlComentario::elegirComentario(string texto) {
    if (productoEnMemoria != -1) {
        ComentarioArbol* arbol = buscarArbol(productoEnMemoria);
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

ComentarioArbol* ControlComentario::buscarArbol(int codigoProducto) {
    for (ComentarioArbol* arbol : arboles) {
        if (arbol->getProducto()->getId() == codigoProducto) {
            return arbol;
        }
    }
    return nullptr;
}

bool ControlComentario::eliminarComentario(string texto) {
    for (ComentarioArbol* arbol : arboles) {
        ComentarioNodo* nodo = arbol->buscarComentario(texto.c_str());
        if (nodo != nullptr) {
            bool resultado = arbol->eliminarComentario(nodo);
            if (resultado) {
                comentarioEnMemoria = "";
                comentarioNodoEnMemoria = nullptr;
            }
            return resultado;
        }
    }
    return false;
}

string ControlComentario::listarComentariosProducto(int codigoProducto) {
    ComentarioArbol* arbol = buscarArbol(codigoProducto);
    if (arbol != nullptr) {
        return listarComentariosRecursivo(arbol->getRaiz(), 0);
    }
    return "No se encontraron comentarios para este producto.";
}

bool ControlComentario::responderComentario(string texto) {
    if (productoEnMemoria != -1 && !usuarioEnMemoria.empty() && !comentarioEnMemoria.empty()) {
        DTFecha fechaActual = controlFecha->getFechaActual();
        ComentarioArbol* arbol = buscarArbol(productoEnMemoria);
        if (arbol != nullptr) {
            ComentarioNodo* padreNodo = arbol->buscarComentario(comentarioEnMemoria.c_str());
            if (padreNodo) {
                Usuario* usuario = controlUsuario->getUsuario(usuarioEnMemoria);
                arbol->agregarComentario(texto.c_str(), usuario, fechaActual, padreNodo);
                return true;
            }
        }
    }
    return false;
}

string ControlComentario::listarComentariosRecursivo(ComentarioNodo* nodo, int nivel) {
    if (!nodo) return "";

    string indentacion(nivel * 2, ' ');
    string resultado = indentacion + nodo->getTexto();

    DTFecha fecha = nodo->getFecha();
    resultado += " "+nodo->getUsuarioNick()+" ("+to_string(fecha.getDia()) + "/" + to_string(fecha.getMes()) + "/" + to_string(fecha.getAnio()) + ")\n";

    resultado += listarComentariosRecursivo(nodo->getHijo(), nivel + 1);
    resultado += listarComentariosRecursivo(nodo->getHermano(), nivel);

    return resultado;
}

string ControlComentario::listarComentariosDeUsuario(string nickUsuario) {
    string resultado = "";
    for (ComentarioArbol* arbol : arboles) {
        resultado += arbol->obtenerComentariosDeUsuario(nickUsuario);
    }
    return resultado;
}