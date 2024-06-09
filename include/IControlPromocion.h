#ifndef ICONTROL_PROMOCION_H
#define ICONTROL_PROMOCION_H

#include <string>
#include <vector>
#include "DTProducto.h"
using namespace std;

class IControlPromocion {
public:
    virtual void datosPromocion(const string&,const string&, date, float) = 0;
    virtual vector<DTProducto> productosAsociadosVendedor(const string&)= 0;
    virtual void agregarProductos(int, int) = 0;
    virtual void confirmarPromocion() = 0;
    virtual ~IControlPromocion(){};

};

#endif