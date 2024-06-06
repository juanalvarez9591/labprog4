#ifndef COMENTARIO_H
#define COMENTARIO_H

#include <string>
using namespace std;

class Comentario {
public:

    //falta agregar lo de la fecha(En su DT) y crea un comentario que no es apuntado ni apunta a nada, el control se va a tener que hacer una funcion de agragar cuando se haga
    Comentario(string autor, string texto);

    //Libera el DTfecha asociado
    void Liberar();

    Comentario* getSig();
    Comentario* getResp();
    DTFecha* getFecha();

    //Devuelve el puntero a la primera respuesta, y puedes navegar al resto luego
    Comentario* borrarRespuestas();

private:
    DTFecha date;
    string autor;
    string texto;
    Comentario* Sigcomenario;
    Comentario* Respuesta
};

#endif