#ifndef DTDATA_CLIENTE_H
#define DTDATA_CLIENTE_H

#include "DTInfoUsuarios.h"
#include <string>

class DTDataCliente 
{
private:
    string calle, ciudad, nickname;
    int nroPuerta;
    DTFecha fechaNacimiento;

public:
    DTDataCliente();
    DTDataCliente(string nickname, DTFecha fechaNacimiento, int nroPuerta,  string calle, string ciudad);
    string getCalle() const;
    string getCiudad() const;
    string getNickname() const;
    int getNroPuerta() const; 
    DTFecha getFechaNacimiento() const;
    virtual ~DTDataCliente();

};

#endif