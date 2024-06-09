#ifndef ICONTROL_USUARIO_H
#define ICONTROL_USUARIO_H

#include <string>
#include <vector>
#include "DTComentario.h"
using namespace std;

class IControlUsuario {
public:
    virtual bool darDeAltaCliente(const string&, const string&, Date, const string&,const string&) = 0;
    virtual bool darDeAltaVendedor(const string&,const string&, Date, int) = 0;
    virtual vector<string> listarNicknamesUsuarios() = 0;
    virtual vector<string> listarClientes() = 0;
    virtual vector<DTComentario> listarComentariosUsuario(const string& nickname) = 0;
    virtual void eliminarComentario(Comentario comentario) = 0;
    virtual vector<string> listarNicknameVendedores() = 0;
    virtual vector<string> ListaNicknamesVendedores(const string& nickname) = 0;
    virtual void SeleccionarVendedores( const string& nickname, vector<string>) = 0;
    virtual ~IControlUsuario(){};



};

#endif