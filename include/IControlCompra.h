#ifndef ICONTROL_COMPRA_H
#define ICONTROL_COMPRA_H

#include <string>
#include <vector>
#include "DTDetallesCompra.h"
#include "DTInfoProducto.h"
#include "DTDatosProducto.h"
#include "DTFecha.h"
using namespace std;

class IControlCompra {
public:
    virtual void seleccionarCliente(string nombreCliente) = 0;
    virtual void agregarProducto(int codigo, int cantidad) = 0;
    virtual void ConfirmarCompra(DTFecha fecha, int precio) = 0;
    virtual ~IControlCompra(){};
    virtual vector <DTDetalleProducto> getDataProducto()= 0;
    virtual void borrarDataProducto()= 0;


};

#endif