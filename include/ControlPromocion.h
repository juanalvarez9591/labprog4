#ifndef CONTROL_PROMOCION_H
#define CONTROL_PROMOCION_H

#include <string>
#include <vector>
#include <set>
#include <unordered_map>
#include "DTProducto.h"
#include "DTFecha.h"
#include "DTPromocion.h"
#include "DTInfoProducto.h"
#include "IControlPromocion.h"
#include "Producto.h"
#include "Promocion.h"
#include "Requisitos.h"

class ControlUsuario;
class ControlFecha;
class Vendedor;

using namespace std;

class ControlPromocion : public IControlPromocion {
public:
    static ControlPromocion* getInstance();
    set<string> listarNicknameVendedores();
    bool elegirVendedor(string nickVendedor);
    bool ingresarProducto(string nombre, string descripcion, float precio, int stock, string categoria);
    vector<DTProducto> listarProductos();
    DTInfoProducto verInfoProducto(int idProducto);
    void ingresarDatosPromocion(string nombre, string descripcion, DTFecha fechaVencimiento, int porcentaje);
    vector<DTProducto> verProductosVendedorEnMemoria();
    vector<DTProducto> verProductosVendedor(string nickUsuario);
    void agregarProductoPromocion(int idProducto, int cantidad);
    void confirmarPromocion();
    set<DTPromocion> listarPromocionesVigentes();
    vector<DTInfoProducto> consultarProductosPromocion(string nombrePromocion);
    bool productoEnPromocion(int idProducto);
    virtual ~ControlPromocion();
    vector<DTDatosProducto> listarDataProductos();
    Producto* getProductoByID(int idProducto);
    vector<Requisitos> obtenerRequisitosPromocion(string nombre);
    vector<DTPromocion> verPromocionesVendedor(string nickVendedor);
    float calcularPrecioTotal(int codigoProducto, int cantidad);

private:
    ControlPromocion();
    static ControlPromocion* instance;
    ControlUsuario* controlUsuario;
    ControlFecha* controlFecha;
    unordered_map<int, Producto> productos;
    unordered_map<string, Promocion> promociones;
    Vendedor* vendedorEnMemoria;
    Promocion promocionEnMemoria;
};

#endif