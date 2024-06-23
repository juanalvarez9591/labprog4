#ifndef COMPRA_H
#define COMPRA_H

#include <string>
#include <vector>
#include "Cliente.h"
#include "DTFecha.h"
#include "Cantidad.h"
#include "DTExpCompra.h"
#include "DTExpProducto.h"

using namespace std;

class Compra {
public:
    Compra(DTFecha fechaCompra, Cliente* cliente);
    void agregarCantidad(Cantidad* cantidad);
    void eliminarCantidad(Cantidad* cantidad);
    DTFecha getFechaCompra();
    vector<Cantidad*>& getCantidades();
    DTExpCompra toDTExpCompra() const;
    DTCompra toDTCompra();
    Cliente* getCliente() const;
private:
    DTFecha fechaCompra;
    int costo;
    vector<Cantidad*> cantidades;
    Cliente* cliente;
};

#endif