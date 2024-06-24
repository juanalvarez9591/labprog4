#include "ControlComentario.h"
#include <algorithm>

ControlComentario* ControlComentario::instance = nullptr;

ControlComentario* ControlComentario::getInstance() {
    if (instance == nullptr) {
        instance = new ControlComentario();
    }
    return instance;
}

ControlComentario::ControlComentario() {
    ContrUsua = ControlUsuario::getInstance();
    ContrProm = ControlPromocion::getInstance();
    UsuarioSeleccionado = nullptr;
    ProdSeleccionado = nullptr;
    AResponder = nullptr;
}

ControlComentario::~ControlComentario() {
}

vector<string> ControlComentario::listarComentariosUsuario(string nombreUsuario) {
    Usuario* usuario = ContrUsua->getUsuario(nombreUsuario);
    if (!usuario) return {};

    vector<string> comentarios;
    vector<string> comentarios;
    for (Comentario* c : usuario->getComentarios()) {
        comentarios.push_back(c->getTexto());
    }
    return comentarios;
}

void ControlComentario::eliminarComentario(string mensaje) {
    if (!UsuarioSeleccionado || !ProdSeleccionado) return;

    Comentario* comentario = ProdSeleccionado->buscarComentario(mensaje);
    if (comentario) {
        ProdSeleccionado->eliminarComentario(comentario);
        UsuarioSeleccionado->olvidarComentario(comentario);
    }

    UsuarioSeleccionado = nullptr;
    ProdSeleccionado = nullptr;
}

bool ControlComentario::seleccionarUsuario(string nombreUsuario) {
    UsuarioSeleccionado = ContrUsua->getUsuario(nombreUsuario);
    return UsuarioSeleccionado != nullptr;
}

vector<DTProducto> ControlComentario::listarProductos() {
    return ContrProm->listarProductos();
}

bool ControlComentario::seleccionarProducto(int IDProducto) {
    ProdSeleccionado = ContrProm->getProductoByID(IDProducto);
    return ProdSeleccionado != nullptr;
}

void ControlComentario::realizarComentario(string texto, DTFecha fecha) {
    if (!ProdSeleccionado || !UsuarioSeleccionado) return;

    Comentario* nuevoComentario = new Comentario(texto, fecha);
    ProdSeleccionado->agregarComentario(nuevoComentario);
    UsuarioSeleccionado->addComentario(nuevoComentario);

    UsuarioSeleccionado = nullptr;
    ProdSeleccionado = nullptr;
}

vector<string> ControlComentario::listarComentarios() {
    if (!ProdSeleccionado) return {};
    return ProdSeleccionado->listarComentarios();
}

bool ControlComentario::elegirComentario(string mensaje) {
    if (!ProdSeleccionado) return false;

    AResponder = ProdSeleccionado->buscarComentario(mensaje);
    return AResponder != nullptr;
}

void ControlComentario::responderComentario(string respuesta, DTFecha fecha) {
    if (!UsuarioSeleccionado || !AResponder) return;

    Comentario* nuevaRespuesta = new Comentario(respuesta, fecha);
    AResponder->agregarRespuesta(nuevaRespuesta);
    UsuarioSeleccionado->addComentario(nuevaRespuesta);

    UsuarioSeleccionado = nullptr;
    AResponder = nullptr;
}