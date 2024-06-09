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
    vector<DTInfoProducto> productos;

public:
    DTNotificacion();
    DTNotificacion(string nombrePromo, vector<DTInfoProducto> productos);
};

#endif // DTNOTIFICACION_H