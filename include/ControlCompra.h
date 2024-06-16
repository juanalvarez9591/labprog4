#ifndef CONTROL_COMPRA_H
#define CONTROL_COMPRA_H

#include <string>
#include <vector>
#include <unordered_map>
#include "DTDetallesCompra.h"
#include "DTInfoProducto.h"
#include "Producto.h"
#include "Compra.h"
#include "Cantidad.h"
#include "DTInfoProducto.h"
#include "DTDetalleProducto.h"
#include "IControlCompra.h"
#include "ControlPromocion.h"
using namespace std;

class ControlCompra : public IControlCompra {

private:
    ControlCompra();
    string clienteEnMemoria;
    //vector<DTDetalleProducto> Lista;
    static ControlCompra* instance;
    unordered_map<int, Compra> compras;
    vector<DTDetalleProducto> dataProducto;
    vector<Producto> productosEnMemoria;

public:
     static ControlCompra* getInstance();
     void seleccionarCliente(string nombreCliente);
     void agregarProducto(int codigo, int cantidad);
     void ConfirmarCompra(DTFecha fecha, int precio);
     vector <DTDetalleProducto> getDataProducto();
     void borrarDataProducto();
     //virtual ~IControlCompra(){};
    

};

#endif