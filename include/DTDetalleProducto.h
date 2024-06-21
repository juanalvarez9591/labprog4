#ifndef DTDETALLE_PRODUCTO_H
#define DTDETALLE_PRODUCTO_H


using namespace std;

class DTDetalleProducto
{
private:
    int codigoProducto;
    int cantProducto;

public:
    DTDetalleProducto();
    DTDetalleProducto(int codigoProducto, int cantProducto);
    int getCodigoProducto();
    int getCantProducto();
};

#endif 