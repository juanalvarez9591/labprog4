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
    int id;

public:
    DTCompra();
    DTCompra(string nicknameCliente, DTFecha fechaCompra, int id);
    string getNicknameCliente() const;
    DTFecha getFechaCompra() const;
    int getId() const;
};

#endif