#include "Comentario.h"
#include "DTComentario.h"
#include "DTFecha.h"
#include <queue>

using namespace std;

Comentario::Comentario(string texto, DTFecha fecha) {
    this->texto = texto;
    this->fecha = fecha;
    this->Sigcomentario = nullptr;
    this->Respuesta = nullptr;
}

Comentario::~Comentario() {
}

set<Comentario*> Comentario::getRespuestas() {
    set<Comentario*> respuestas;
    Comentario* i = this->Respuesta;
    while (i != nullptr) {
        respuestas.insert(i);
        i = i->Sigcomentario;
    }
    return respuestas;
}

void Comentario::borrarRespuestas() {
    queue<Comentario*> cola;
    if (this->Respuesta) cola.push(this->Respuesta);

    while (!cola.empty()) {
        Comentario* actual = cola.front();
        cola.pop();

        if (actual->Sigcomentario) cola.push(actual->Sigcomentario);
        if (actual->Respuesta) cola.push(actual->Respuesta);

        delete actual;
    }

    this->Respuesta = nullptr;
}

Comentario* Comentario::buscarComentario(const string& mensaje) {
    if (this->texto == mensaje) return this;

    Comentario* encontrado = nullptr;
    if (this->Sigcomentario) {
        encontrado = this->Sigcomentario->buscarComentario(mensaje);
    }
    if (!encontrado && this->Respuesta) {
        encontrado = this->Respuesta->buscarComentario(mensaje);
    }
    return encontrado;
}

void Comentario::agregarRespuesta(Comentario* respuesta) {
    if (!this->Respuesta) {
        this->Respuesta = respuesta;
    } else {
        Comentario* ultimo = this->Respuesta;
        while (ultimo->Sigcomentario) {
            ultimo = ultimo->Sigcomentario;
        }
        ultimo->Sigcomentario = respuesta;
    }
}

Comentario* Comentario::getResp() {
    return this->Respuesta;
}

Comentario* Comentario::getSig() {
    return this->Sigcomentario;
}

void Comentario::setSig(Comentario* Sig) {
    this->Sigcomentario = Sig;
}

void Comentario::setRes(Comentario* Res) {
    this->Respuesta = Res;
}

string Comentario::getTexto() {
    return this->texto;
}

DTComentario Comentario::getDTComentario() {
    return DTComentario(this->texto, this->fecha);
}

bool Comentario::UltimoDelNivel() {
    return (this->Sigcomentario == nullptr);
}

void Comentario::listarComentariosRecursivo(vector<string>& lista, int nivel) {
    string prefijo(nivel * 2, ' '); // esto es para que se lea bien
    lista.push_back(prefijo + this->texto);

    if (this->Respuesta) {
        this->Respuesta->listarComentariosRecursivo(lista, nivel + 1);
    }

    if (this->Sigcomentario) {
        this->Sigcomentario->listarComentariosRecursivo(lista, nivel);
    }
}