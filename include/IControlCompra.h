#ifndef ICONTROL_COMPRA_H
#define ICONTROL_COMPRA_H

#include <string>
#include <vector>
#include "DTDetallesCompra"
#include "DTInfoProducto.h"
using namespace std;

class IControlCompra {
public:
    virtual void seleccionarCliente(const string&) = 0;
    virtual vector <DTInfoProducto> mostrarDatosProducto() = 0;
    virtual void agregarProducto(int, int) = 0;
    virtual DTDetallesCompra DetallesCompra() = 0;
    virtual void ConfirmarCompra() = 0;
    virtual ~IControlCompra(){};

};

#endif