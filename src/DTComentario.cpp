#include "DTComentario.h"
#include "DTFecha.h"

DTComentario::DTComentario()
{
    this->mensaje = "";
    this->fecha  = DTFecha();
}

DTComentario::DTComentario(string mensaje, DTFecha fecha)
{
    this->mensaje = mensaje;
    this->fecha = fecha;
}

DTFecha DTComentario::getFecha(){
    return this->fecha;

}

string DTComentario::getMensaje(){
        return this->mensaje;
}

