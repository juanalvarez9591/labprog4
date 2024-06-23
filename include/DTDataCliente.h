#ifndef DTDATA_CLIENTE_H
#define DTDATA_CLIENTE_H

#include "DTInfoUsuarios.h"
#include <string>

class DTDataCliente : public DTInfoUsuarios
{
private:
    string calle, ciudad;
    int nroPuerta;
    

public:
    DTDataCliente();
    DTDataCliente(string nickname, DTFecha fechaNacimiento, int nroPuerta,  string calle, string ciudad);
    string getCalle() const;
    string getCiudad() const;
    int getNroPuerta() const; 
    virtual ~DTDataCliente();

};

#endif