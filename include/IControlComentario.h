#ifndef ICONTROL_COMENTARIO_H
#define ICONTROL_COMENTARIO_H

#include <string>
#include <vector>
#include "DTFecha.h"
#include "DTProducto.h"

class IControlComentario {
public:
    
    virtual vector<string> listarComentariosUsuario(string nombreUsuario) = 0;
    virtual void eliminarComentario(string mensaje) = 0;

    virtual void seleccionarUsuario(string nombreUsuario) = 0;
    virtual vector<string> listarProductos() = 0;
    virtual void seleccionarProducto(string nombreProducto) = 0;
    virtual void realizarComentario(string texto, DTFecha fecha) = 0;
    virtual vector<string> listarComentarios() = 0;
    virtual void elegirComentario(string mensaje) = 0;
    virtual void responderComentario(string respuesta, DTFecha fecha) = 0;

    virtual ~IControlComentario() {}
};

#endif