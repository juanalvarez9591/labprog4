#ifndef CONTROL_USUARIO_H
#define CONTROL_USUARIO_H

#include "IControlUsuario.h"
#include "Vendedor.h"
#include "Usuario.h"
#include "Cliente.h"
#include "DTFecha.h"
#include "DTExpCliente.h"
#include "DTExpVendedor.h"


#include <vector>

class ControlUsuario : public IControlUsuario {
public:
    static ControlUsuario* getInstance();

    bool darDeAltaCliente(string nickname, string password, DTFecha fechaNacimiento, int nroPuerta,  string calle, string ciudad) override;

    bool darDeAltaVendedor(string nickname, string password, DTFecha fechaNacimiento, string rut) override;
    vector<string> listarNicknamesUsuarios() override;
    vector<string> listarNicknamesClientes() override;
    vector<string> listarNicknamesVendedores() override;
    Usuario* getUsuario(string nickname);
    Vendedor* getVendedor(string nickname);
    Cliente* getCliente(string nickname);
    vector<Vendedor> getVendedores();
    vector<DTDataCliente> listarInfoClientes() override;
    vector<DTDataVendedor> listarInfoVendedores() override;
    DTInfoUsuarios* verExpedienteUsuario(string nickUsuario) override;

    virtual ~ControlUsuario();

private:
    ControlUsuario();
    static ControlUsuario* instance;
    vector<Cliente> clientes;
    vector<Vendedor> vendedores;
    bool nicknameRepetido(string nickname);
};



#endif