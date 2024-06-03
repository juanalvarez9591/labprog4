#ifndef ICONTROL_USUARIO_H
#define ICONTROL_USUARIO_H

#include <string>
#include <vector>
#include "DTComentario.h"
#include "Cliente.h"
#include "Vendedor.h"
#include "Comentario.h"

class IControlUsuario {
public:
    virtual void darDeAltaCliente(Cliente cliente) = 0;
    virtual void darDeAltaVendedor(Vendedor vendedor) = 0;
    virtual std::vector<std::string> listarNicknamesUsuarios() = 0;
    virtual std::vector<DTComentario> listarComentariosUsuario(const std::string& nickname) = 0;
    virtual void eliminarComentario(Comentario comentario) = 0;
};

#endif