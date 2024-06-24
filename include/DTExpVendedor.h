#ifndef DTEXP_VENDEDOR_H
#define DTEXP_VENDEDOR_H

#include "DTDataVendedor.h"
#include "DTPromocion.h"
#include "DTProducto.h"
#include "DTFecha.h"
#include <vector>
#include <string>

class DTExpVendedor : public DTDataVendedor {
private:
    vector<DTPromocion> promociones;
    vector<DTProducto> productos;

public:
    DTExpVendedor(string nickname, DTFecha fechaNacimiento, string rut,
                  vector<DTPromocion> promociones, vector<DTProducto> productos);

    vector<DTPromocion> getPromociones() const;
    vector<DTProducto> getProductos() const;
};

#endif