#ifndef DTDETALLESCOMPRA_H
#define DTDETALLESCOMPRA_H

#include <string>
#include <vector>
#include "DTFecha.h"
#include "DTProducto.h"
using namespace std;

class DTDetallesCompra
{
private:
    float costo;
    DTFecha fecha;
    vector<DTProducto> productos;

public:
    DTNotificacion();
    DTNotificacion(float costo, DTFecha fecha,vector<DTProducto> productos);
};

#endif // DTNOTIFICACION_H