#ifndef DTNOTIFICACION_H
#define DTNOTIFICACION_H

#include <string>
#include <vector>
#include "DTInfoProducto.h"
using namespace std;

class DTNotificacion
{
private:
    string nombrePromo;
    string nickVendedor;
    vector<DTInfoProducto> productosPromocion;

public:
    DTNotificacion();
    DTNotificacion(string nombrePromo, string nickVendedor, vector<DTInfoProducto> productos);
    string toString() const;
};

#endif // DTNOTIFICACION_H