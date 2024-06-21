#ifndef CONTROL_COMPRA_H
#define CONTROL_COMPRA_H

#include <string>
#include <vector>
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
    //DTFecha fechaActual;
    //float costo;
    static ControlCompra* instance;
    vector <Compra> compras;
    

public:
     static ControlCompra* getInstance();
     void seleccionarCliente(string nombreCliente);
     vector <DTInfoProducto> mostrarDatosProducto() ;
     void agregarProducto(int, int) ;
     DTDetallesCompra DetallesCompra() ;
     void ConfirmarCompra();
     //virtual ~IControlCompra(){};
     //vector<string> listarClientes();

};

#endif