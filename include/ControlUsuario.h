#ifndef CONTROL_USUARIO_H
#define CONTROL_USUARIO_H

#include "IControlUsuario.h"
#include "Vendedor.h"
#include "Usuario.h"
#include "Cliente.h"
#include <vector>
#include "Comentario.h"
using namespace std;

class ControlUsuario : public IControlUsuario {
public:
    
     bool darDeAltaCliente(const string&, const string&, Date, const string&,const string&) override;
     bool darDeAltaVendedor(const string&,const string&, Date, int) override;
     vector<string> listarNicknamesUsuarios() override;
     vector<string> listarClientes() override;
     vector<DTComentario> listarComentariosUsuario(const string& nickname) override;
     void eliminarComentario(Comentario comentario) override;
     vector<string> listarNicknameVendedores() override;
     vector<string> ListaNicknamesVendedores(const string& nickname) override;
     void SeleccionarVendedores( const string& nickname, vector<string>) override;
     Usuario BuscarPorNick(const string& nickname) override;
     virtual ~ControlUsuario();

private:
    vector<Cliente> clientes;
    vector<Vendedor> vendedores;
};

#endif