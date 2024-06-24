#ifndef ICONTROL_USUARIO_H
#define ICONTROL_USUARIO_H

#include <string>
#include <vector>
#include "DTFecha.h"
#include "DTDataVendedor.h"
#include "DTDataCliente.h"
#include "DTComentario.h"


using namespace std;

class IControlUsuario {
public:
    virtual bool darDeAltaCliente(string nickname, string password, DTFecha fechaNacimiento, int nroPuerta, string calle, string ciudad) = 0;
    virtual bool darDeAltaVendedor(string nickname, string password, DTFecha fechaNacimiento, string rut) = 0;
    virtual vector<string> listarNicknamesUsuarios() = 0;
    virtual vector<string> listarNicknamesClientes() = 0;
    virtual vector<string> listarNicknamesVendedores() = 0;
    virtual vector<DTDataCliente> listarInfoClientes() = 0;
    virtual vector<DTDataVendedor> listarInfoVendedores() = 0;
    virtual DTInfoUsuarios* verExpedienteUsuario(string nickUsuario) = 0;
    virtual ~IControlUsuario(){};
};


#endif