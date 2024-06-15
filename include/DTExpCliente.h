#ifndef DTEXP_CLIENTE_H
#define DTEXP_CLIENTE_H

#include "DTDataCliente.h"
#include "DTExpCompra.h"
#include <vector>


class DTExpCliente : public DTDataCliente{
private:
    vector <DTExpCompra> compras;
public: 
    DTExpCliente(string nickname, DTFecha fecha, string calle, string ciudad, int nroPuerta, vector <DTExpCompra> compras);
    vector <DTExpCompra> getCompras();
};
#endif 
