#ifndef CONTROL_COMPRA_H
#define CONTROL_COMPRA_H

#include <string>
#include <vector>
#include "DTDetallesCompra"
#include "DTInfoProducto.h"
#include "Producto.h"
#include "Compra.h"
#include "Cantidad.h"
#include "DTInfoProducto.h"
#include "DTDetalleProducto.h"
using namespace std;

class IControlCompra {

private:
    string nickname;
    vector<DTDetalleProducto> Lista;
    DTFecha fechaActual;
    float costo;

public:
    virtual void seleccionarCliente(const string&) = 0;
    virtual vector <DTInfoProducto> mostrarDatosProducto() = 0;
    virtual void agregarProducto(int, int) = 0;
    virtual DTDetallesCompra DetallesCompra() = 0;
    virtual void ConfirmarCompra() = 0;
    virtual ~IControlCompra(){};

};

#endif