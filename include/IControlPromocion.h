#ifndef ICONTROL_PROMOCION_H
#define ICONTROL_PROMOCION_H

#include <string>
#include <vector>
#include <set>
#include "DTProducto.h"
#include "DTFecha.h"
#include "DTPromocion.h"
#include "DTInfoProducto.h"
using namespace std;

class IControlPromocion {
public:
    virtual set<string> listarNicknameVendedores() = 0;
    virtual bool elegirVendedor(string nickVendedor) = 0;
    virtual bool ingresarProducto(string nombre, string descripcion, float precio, int stock, string categoria) = 0;
    virtual vector<DTProducto> listarProductos() = 0;
    virtual DTInfoProducto verInfoProducto(int idProducto) = 0;
    virtual void ingresarDatosPromocion(string nombre, string descripcion, DTFecha fechaVencimiento, int porcentaje) = 0;
    virtual vector<DTProducto> verProductosVendedor() = 0;
    virtual void agregarProductoPromocion(int idProducto, int cantidad) = 0;
    virtual void confirmarPromocion() = 0;
    virtual vector<DTPromocion> listarPromocionesVigentes() = 0;
    virtual vector<DTInfoProducto> consultarProductosPromocion(string nombrePromocion) = 0;

    virtual ~IControlPromocion(){};

};

#endif