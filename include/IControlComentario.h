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

    virtual bool seleccionarUsuario(string nombreUsuario) = 0; //Devuelve false si no encontró el usuario
    virtual vector<DTProducto> listarProductos() = 0;
    virtual bool seleccionarProducto(int IDProducto) = 0; //Devuelve false si no encontró el producto
    virtual void realizarComentario(string texto, DTFecha fecha) = 0;
    virtual vector<string> listarComentarios() = 0;
    virtual bool elegirComentario(string mensaje) = 0; //Devuelve false si no encontró el comentario
    virtual void responderComentario(string respuesta, DTFecha fecha) = 0;

    virtual ~IControlComentario() {}
};

#endif