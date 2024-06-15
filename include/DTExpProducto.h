#ifndef DTEXP_PRODUCTO_H
#define DTEXP_PRODUCTO_H

#include <string>
using namespace std;

class DTExpProducto{
private:
    int codigoProducto;
    int cantidadProducto;
    string nombreProducto;

public:
    DTExpProducto();
    DTExpProducto(int codigoProducto, int cantidadProducto, string nombreProducto);
    int getCodigoProducto();
    int getCantidadProducto();
    string getNombreProducto();
};

#endif