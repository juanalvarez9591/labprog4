#ifndef DTDATA_VENDEDOR_H
#define DTDATA_VENDEDOR_H

#include "DTInfoUsuarios.h"
#include "DTFecha.h"
#include <string>

using namespace std;

class DTDataVendedor {
private:

    string nickname, rut;
    DTFecha fechaNacimiento;

public:
    DTDataVendedor(string nickname, DTFecha fechaNacimiento, string rut);
    string getRut() const;
    string getNickname() const;
    DTFecha getFechaNacimiento() const;
};

#endif