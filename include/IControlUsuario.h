#ifndef ICONTROL_USUARIO_H
#define ICONTROL_USUARIO_H

#include <string>
#include <vector>
#include "DTFecha.h"
#include "DTComentario.h"


using namespace std;

class IControlUsuario {
public:
    virtual bool darDeAltaCliente(string nickname, string password, DTFecha fechaNacimiento, string direccion, string ciudad) = 0;
    virtual bool darDeAltaVendedor(string nickname, string password, DTFecha fechaNacimiento, int rut) = 0;
    virtual vector<string> listarNicknamesUsuarios() = 0;
    virtual vector<string> listarNicknamesClientes() = 0;
    virtual vector<string> listarNicknamesVendedores() = 0;

    virtual void seleccionarUsuario(string nombreUsuario) = 0;
    virtual vector<DTProducto> listarProductos() = 0;
    virtual void seleccionarProducto(string nombreProducto) = 0;
    //virtual void realizarComentario(string texto, DTFecha fecha) = 0;
    virtual vector<string> listarComentarios() = 0;
    //virtual void elegirComentario(string mensaje) = 0;
    //virtual void responderComentario(string respuesta) = 0;

    virtual ~IControlUsuario() {}
};


#endif