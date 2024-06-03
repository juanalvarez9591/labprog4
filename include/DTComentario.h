#ifndef DTCOMENTARIO_H
#define DTCOMENTARIO_H

#include <string>
using namespace std;

class DTComentario
{
private:
    string autor;
    string texto;

public:
    DTComentario();
    DTComentario(string autor, string texto);
};

#endif // DTCOMENTARIO_H