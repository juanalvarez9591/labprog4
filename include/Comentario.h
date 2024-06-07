#ifndef COMENTARIO_H
#define COMENTARIO_H

#include <string>
using namespace std;

class Comentario {
public:
    Comentario(string autor, string texto);

private:
    string autor;
    string texto;
};

#endif