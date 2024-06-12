#ifndef ICONTROL_USUARIO_H
#define ICONTROL_USUARIO_H

#include <string>
#include <vector>
#include "DTFecha.h"
#include "DTComentario.h"

/*
#include "DTComentario.h"
*/
using namespace std;

class IControlUsuario {
public:
    virtual bool darDeAltaCliente(string nickname, string password, DTFecha fechaNacimiento, string direccion, string ciudad) = 0;
    virtual bool darDeAltaVendedor(string nickname, string password, DTFecha fechaNacimiento, int rut) = 0;
    virtual vector<string> listarNicknamesUsuarios() = 0;
    virtual vector<string> listarNicknamesClientes() = 0;
    virtual vector<string> listarNicknamesVendedores() = 0;

    virtual void seleccionarUsuario(string nombreUsuario);
    virtual vector<DTProducto> listarProductos();
    virtual void seleccionarProducto(string nombreProducto);
    virtual void realizarComentario(string texto);
    virtual vector<DTComentario> listarComentarios();
    virtual void elegirComentario(string mensaje);
    virtual void responderComentario(string respuesta);

    virtual ~IControlUsuario() {}
};


#endif