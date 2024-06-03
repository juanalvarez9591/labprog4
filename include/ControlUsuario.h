#ifndef CONTROL_USUARIO_H
#define CONTROL_USUARIO_H

#include "IControlUsuario.h"
#include <vector>
#include "Comentario.h"

class ControlUsuario : public IControlUsuario {
public:
    void darDeAltaCliente(Cliente cliente) override;
    void darDeAltaVendedor(Vendedor vendedor) override;
    std::vector<std::string> listarNicknamesUsuarios() override;
    std::vector<DTComentario> listarComentariosUsuario(const std::string& nickname) override;
    void eliminarComentario(Comentario comentario) override;

private:
    std::vector<Cliente> clientes;
    std::vector<Vendedor> vendedores;
};

#endif