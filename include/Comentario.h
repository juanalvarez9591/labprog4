#ifndef COMENTARIO_H
#define COMENTARIO_H

#include <string>

using namespace std;

class Comentario {
public:

    //falta agregar lo de la fecha(En su DT) y crea un comentario que no es apuntado ni apunta a nada, el control se va a tener que hacer una funcion de agragar cuando se haga
    Comentario(string texto);

    //Libera el DTfecha asociado
    void Liberar();

    Comentario* getSig();
    Comentario* getResp();
    void setSig(Comentario* Sig);
    void setRes(Comentario* Res);
    DTFecha* getFecha();

    //Devuelve el puntero a la primera respuesta, y puedes navegar al resto luego
    Comentario* borrarRespuestas();

    //Crea y devuelve un DTComentario de este comentario
    DTComentario getDTComentario()

    bool UltimoDelNivel();

    void PrintComentario();

private:
    DTFecha date;
    string texto;
    Comentario* Sigcomenario;
    Comentario* Respuesta
};

#endif