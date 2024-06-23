#ifndef ICONTROL_COMPRA_H
#define ICONTROL_COMPRA_H

#include <string>
#include <vector>
#include <unordered_map>
#include "DTDetallesCompra.h"
#include "DTInfoProducto.h"
#include "DTDatosProducto.h"
#include "DTFecha.h"
#include "DTCompra.h"
using namespace std;

class IControlCompra {
public:
    virtual void seleccionarCliente(string nickCliente) = 0;
    virtual bool agregarCantidad(int codigo, int cantidad) = 0;
    virtual bool confirmarCompra() = 0;
    virtual void olvidarCompra() = 0;
    virtual DTDetallesCompra verDetallesCompra() = 0;

    virtual bool elegirVendedor(string nombre) = 0; //retorna true si halló el vendedor
    virtual unordered_map<int, DTProducto> listarProductosVendedorAptos() = 0;
    virtual bool elegirProducto(int IDProducto) = 0; //retorna true si halló el producto
    virtual vector<DTCompra> listarComprasCliente() = 0;
    virtual bool marcarComoEnviado(string nickCliente) = 0; //retorna true si halló el producto del cliente
    virtual ~IControlCompra() = default;
};

#endif