#ifndef DTCOMENTARIO_H
#define DTCOMENTARIO_H

#include <string>
#include <DTFecha.h>
using namespace std;

class DTComentario
{
private:
    string mensaje;
    DTFecha  fecha;

public:
    DTComentario();
    DTComentario(string mensaje, DTFecha fecha);
};

#endif // DTCOMENTARIO_H