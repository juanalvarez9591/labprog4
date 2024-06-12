#include "../include/DTComentario.h"

DTComentario::DTComentario()
{
    this->mensaje = "";
}

DTComentario::DTComentario(string mensaje, DTFecha fecha)
{
    this->mensaje = mensaje;
    this->fecha = fecha;
}
