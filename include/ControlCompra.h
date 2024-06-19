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
#include "ControlUsuario.h"
#include "ControlFecha.h"

using namespace std;

class ControlCompra : public IControlCompra {

private:
    ControlCompra();
    Cliente* clienteEnMemoria;
    static ControlCompra* instance;
    unordered_map<int, Compra> compras;
   // vector<DTDetalleProducto> dataProducto;
    DTFecha fechaSistema;
    Compra* compraEnProceso;

public:
     static ControlCompra* getInstance();
     void seleccionarCliente(string nombreCliente);
     void agregarCantidad(int codigo, int cantidad);
     bool confirmarCompra();
     vector <DTDetalleProducto> getDataProducto();
    // void borrarDataProducto();
     vector <DTDatosProducto> mostrarDatosProducto();
     //virtual ~IControlCompra(){};
     vector<string> listarClientes();
     void obtenerFechaSistema();
     void olvidarCompra();
    

};

#endif