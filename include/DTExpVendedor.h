#ifndef DTEXP_VENDEDOR_H
#define DTEXP_VENDEDOR_H

#include "DTDataVendedor.h"
#include "DTProducto.h"
#include "DTPromocion.h"
#include <vector>
using namespace std;

class DTExpVendedor : public DTDataVendedor{

private:
    vector <DTPromocion> promociones;
    vector <DTProducto> productos;

public: 
    DTExpVendedor(string nickname, DTFecha fecha, int rut, vector <DTPromocion> promociones, vector <DTProducto> productos);
    vector <DTPromocion> getPromociones();
    vector <DTProducto> getProductos();
}
#endif 