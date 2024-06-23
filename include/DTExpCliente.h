#ifndef DTEXP_CLIENTE_H
#define DTEXP_CLIENTE_H

#include "DTDataCliente.h"
#include "DTExpCompra.h"
#include <vector>
#include <string>


class DTExpCliente : public DTDataCliente {
private:
    vector<DTExpCompra> compras;

public:
    DTExpCliente();
    DTExpCliente(string nickname, DTFecha fechaNacimiento, int nroPuerta,string calle, string ciudad, vector<DTExpCompra> compras);
    vector<DTExpCompra> getCompras() const;
    virtual ~DTExpCliente() override;
};

#endif