#ifndef DTDATOS_PRODUCTO_H
#define DTDATOS_PRODUCTO_H

#include <string>

using namespace std;

class DTDatosProducto {
private:
    int stock;
    string nombreProducto;
    int precio;
    int codigoProducto;

public:
    DTDatosProducto(int stock, string nombreProducto, int precio, int codigoProducto);
    string toString() const;
    int getCodigo() const;
    int getStock() const;
    int getPrecio() const;
    string getNombre() const;
};

#endif