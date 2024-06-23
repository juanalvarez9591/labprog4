#ifndef DTDETALLES_COMPRA_H
#define DTDETALLES_COMPRA_H

#include <string>
#include <vector>
#include "DTProducto.h"
#include "DTFecha.h"
using namespace std;

class DTDetallesCompra
{
private:
    float costo;
    DTFecha fecha;
    vector<DTProducto> productos;

public:
    DTDetallesCompra();
    DTDetallesCompra(float costo, DTFecha fecha, vector<DTProducto> productos);
    float getCosto();
    DTFecha getFecha();
    vector<DTProducto> getProductos();
    string toString() const;
};

#endif 