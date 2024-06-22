#ifndef DTEXP_COMPRA_H
#define DTEXP_COMPRA_H

#include "DTFecha.h"
#include "DTExpProducto.h"
#include <vector>
using namespace std;

class DTExpCompra {
private:
    float costo;
    DTFecha fechaCompra;
    vector<DTExpProducto> productos;

public:
    DTExpCompra();
    DTExpCompra(float costo, DTFecha fechaCompra, vector<DTExpProducto> productos);
    float getCosto();
    DTFecha getFecha();
    vector<DTExpProducto> getProductos();
};

#endif