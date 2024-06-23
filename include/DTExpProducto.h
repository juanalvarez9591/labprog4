#ifndef DTEXP_PRODUCTO_H
#define DTEXP_PRODUCTO_H

#include <string>
using namespace std;

class DTExpProducto {
private:
    int codigoProducto;
    int cantidadProducto;
    string nombreProducto;
    bool enviado;

public:
    DTExpProducto();
    DTExpProducto(int codigoProducto, int cantidadProducto, string nombreProducto, bool enviado);
    int getCodigoProducto() const;
    int getCantidadProducto() const;
    string getNombreProducto() const;
    bool getEnviado() const;
};

#endif