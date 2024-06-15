#ifndef DTDATA_VENDEDOR_H
#define DTDATA_VENDEDOR_H


#include "DTInfoUsuarios.h"
using namespace std;

class DTDataVendedor : public DTInfoUsuarios
{
private:
    int rut;

public:
    DTDataVendedor(string nickname, DTFecha fecha, int rut);
    int getRut();
};

#endif 