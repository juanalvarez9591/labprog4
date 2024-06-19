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
    virtual void agregarCantidad(int codigo, int cantidad) = 0;
    virtual bool confirmarCompra() = 0;
    virtual vector <DTDatosProducto> mostrarDatosProducto() = 0;
    virtual ~IControlCompra(){};
    virtual vector<string> listarClientes() = 0;
    virtual void obtenerFechaSistema() = 0;
    virtual void olvidarCompra() = 0;
    //virtual vector<DTDetalleProducto> getDataProducto() = 0; 


};

#endif