#ifndef DTDATA_VENDEDOR_H
#define DTDATA_VENDEDOR_H

#include "DTInfoUsuarios.h"
#include "DTFecha.h"
#include <string>

using namespace std;

class DTDataVendedor : public DTInfoUsuarios {
private:
    string rut;

public:
    DTDataVendedor(string nickname, DTFecha fecha, string rut);
    string getRut();
};

#endif