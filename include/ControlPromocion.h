#ifndef CONTROL_PROMOCION_H
#define CONTROL_PROMOCION_H

#include <string>
#include <vector>
#include "DTProducto.h"
#include "DTDetalleProducto.h"
#include "Promocion.h"
#include "Producto.h"
#include "Requisitos.h"
#include "ControlUsuario.h"
#include "Vendedor.h"
#include "DTFecha.h"
#include "IControlPromocion.h"
using namespace std;

class ControlPromocion public: IControlPromocion {

private:
    string nombre;
    string descripcion;
    DTFecha fechaVencimiento;
    float porcentaje;
    vector<DTDetalleProducto> requerimientos;

    //vector<Producto> Productos;

public:
     vector<Producto> getColeccionProd();
     void datosPromocion(const string&,const string&, date, float) override;
     vector<DTProducto> productosAsociadosVendedor(const string) override;
     void agregarProductos(int, int) override;
     void confirmarPromocion() override;
     bool validacionFecha(DTFecha fecha) override;
     virtual ~ControlCompra();

};

#endif