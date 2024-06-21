#ifndef DTCOMPRA_H
#define DTCOMPRA_H

#include <string>
#include "DTFecha.h"
using namespace std;

class DTCompra 
{
private:
    string nicknameCliente;
    DTFecha fechaCompra;

public:
    DTCompra();
    DTCompra(string nicknameCliente, DTFecha fechaCompra);
    string getNicknameCliente();
    DTFecha getFechaCompra();
};

#endif 