#ifndef CONTROL_USUARIO_H
#define CONTROL_USUARIO_H

#include "IControlUsuario.h"
#include "Vendedor.h"
#include "Usuario.h"
#include "Cliente.h"
#include "DTFecha.h"
#include "DTComentario.h"
#include <vector>
using namespace std;

class ControlUsuario : public IControlUsuario {
public:
    static ControlUsuario* getInstance();
    bool darDeAltaCliente(string nickname, string password, DTFecha fechaNacimiento, string direccion, string ciudad) override;
    bool darDeAltaVendedor(string nickname, string password, DTFecha fechaNacimiento, int rut) override;
    vector<string> listarNicknamesUsuarios() override;
    vector<string> listarNicknamesClientes() override;
    vector<string> listarNicknamesVendedores() override;
    

    Usuario* getUsuario(string nickname);
    Vendedor* getVendedor(string nickname);
    Cliente* getCliente(string nickname);
    vector<Vendedor> getVendedores();
    virtual ~ControlUsuario();

private:
    ControlUsuario();
    static ControlUsuario* instance;
    vector<Cliente> clientes;
    vector<Vendedor> vendedores;
    bool nicknameRepetido(string nickname);

    vector<string> HacerListComentarios();

    string Comentador;
    string* Prod;
    Comentario* AResponder;
};

#endif