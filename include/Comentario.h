#ifndef COMENTARIO_H
#define COMENTARIO_H

#include <string>
#include <set>
#include <vector>
#include "DTComentario.h"
#include "DTFecha.h"

class Comentario {
private:
    string texto;
    DTFecha fecha;
    Comentario* Sigcomentario;
    Comentario* Respuesta;

public:
    Comentario(string texto, DTFecha fecha);
    ~Comentario();

    set<Comentario*> getRespuestas();
    void borrarRespuestas();
    Comentario* buscarComentario(const string& mensaje);
    void agregarRespuesta(Comentario* respuesta);

    Comentario* getResp();
    Comentario* getSig();
    void setSig(Comentario* Sig);
    void setRes(Comentario* Res);
    string getTexto();
    DTComentario getDTComentario();
    bool UltimoDelNivel();

    void listarComentariosRecursivo(vector<string>& lista, int nivel);
};

#endif // COMENTARIO_H