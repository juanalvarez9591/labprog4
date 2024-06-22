#ifndef DTDATA_CLIENTE_H
#define DTDATA_CLIENTE_H

#include "DTInfoUsuarios.h"
#include <string>

class DTDataCliente : public DTInfoUsuarios
{
private:
    string direccion;
    string ciudad;

public:
    DTDataCliente();
    DTDataCliente(string nickname, DTFecha fecha, string direccion, string ciudad);
    string getDireccion();
    string getCiudad();
    virtual ~DTDataCliente() override;
};

#endif