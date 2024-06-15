#ifndef CONTROL_PROMOCION_H
#define CONTROL_PROMOCION_H

#include <string>
#include <vector>
#include <set>
#include "DTProducto.h"
#include "DTFecha.h"
#include "DTPromocion.h"
#include "DTInfoProducto.h"
#include "IControlPromocion.h"
#include "Producto.h"
#include "Promocion.h"
#include "Requisitos.h"

using namespace std;

class ControlPromocion : public IControlPromocion {
public:
    static ControlPromocion* getInstance();

    set<string> listarNicknameVendedores();
    void elegirVendedor(string nickVendedor);
    void ingresarProducto(string nombre, string descripcion, float precio, int stock, string categoria);
    set<DTProducto> listarProductos();
    DTInfoProducto verInfoProducto(int idProducto);
    void ingresarDatosPromocion(string nombre, string descripcion, DTFecha fechaVencimiento, int porcentaje);
    set<DTProducto> verProductosVendedor();
    void agregarProductoPromocion(int idProducto, int cantidad);
    void confirmarPromocion();
    set<DTPromocion> listarPromocionesVigentes();
    set<DTInfoProducto> consultarProductosPromocion(string nombrePromocion);
    virtual ~ControlPromocion();
private:
    ControlPromocion();
    static ControlPromocion* instance;
    vector<Producto> productos;
    vector<Promocion> promociones;
    vector<Requisitos> requisitos;
    ControlUsuario* controlUsuario;
};

#endif