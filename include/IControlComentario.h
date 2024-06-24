#ifndef ICONTROL_COMENTARIO_H
#define ICONTROL_COMENTARIO_H

#include <string>
#include <vector>
#include "DTFecha.h"
#include "DTProducto.h"

using namespace std;

class IControlComentario {
public:
    virtual void seleccionarUsuario(string nickUsuario) = 0;
    virtual void seleccionarProducto(int codigoProducto) = 0;
    virtual bool realizarComentario(string texto) = 0;
    virtual string listarComentarios() = 0;
    virtual bool elegirComentario(string texto) = 0;
    virtual bool responderComentario(string texto) = 0;
    virtual bool eliminarComentario() = 0;

    virtual ~IControlComentario() {}
};

#endif // ICONTROL_COMENTARIO_H