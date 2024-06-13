#ifndef DTDATA_CLIENTE_H
#define DTDATA_CLIENTE_H

#include "DTInfoUsuarios.h"

class DTDataCliente : public DTInfoUsuarios
{
private:
    string calle;
    string ciudad;
    int nroPuerta;

public:
    DTDataCliente(string nickname, DTFecha fecha, string calle, string ciudad, int nroPuerta);
    string getCalle();
    string getCiudad();
    int getNroPuerta();
};

#endif 