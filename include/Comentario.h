#ifndef COMENTARIO_H
#define COMENTARIO_H

#include <string>
#include <set>
#include "DTComentario.h"
#include "DTFecha.h"
using namespace std;

class Comentario {
public:

    //falta agregar lo de la fecha(En su DT) y crea un comentario que no es apuntado ni apunta a nada, el control se va a tener que hacer una funcion de agragar cuando se haga
    Comentario(string texto, DTFecha fecha);

    //Libera el DTfecha asociado
    //void Liberar();

    Comentario* getSig();
    Comentario* getResp();
    void setSig(Comentario* Sig);
    void setRes(Comentario* Res);
    DTFecha* getFecha();
    string getTexto();

    //Devuelve un set con las respuestas DIRECTAS del comentario
    set<Comentario*> getRespuestas();
    void eliminarNodo();
    void borrarRespuestas();        //(Comentario comentario)
    bool eliminarNodoPosterior(string mensaje);
    void AgregarRespuesta(Comentario *respuesta);

    //Crea y devuelve un DTComentario de este comentario
    DTComentario getDTComentario();

    bool UltimoDelNivel();

    void PrintComentario();
    Comentario* ComentarioEnForo(Comentario *It, string Text);

private:
    DTFecha fecha;
    string texto;
    Comentario* Sigcomentario;
    Comentario* Respuesta;
};

#endif