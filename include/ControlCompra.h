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
#include "DTExpCliente.h"
#include "IControlCompra.h"

class ControlPromocion;
class ControlUsuario;
class ControlFecha;

using namespace std;

class ControlCompra : public IControlCompra {
private:
    ControlCompra();
    static ControlCompra* instance;
    ControlUsuario* controlUsuario;
    ControlFecha* controlFecha;
    ControlPromocion* controlPromocion;

    unordered_map<int, Compra*> compras;
    Cliente* clienteEnMemoria;
    Compra* compraEnProceso;

public:
    static ControlCompra* getInstance();
    void seleccionarCliente(string nickCliente) override;
    bool agregarCantidad(int codigo, int cantidad) override;
    bool confirmarCompra() override;
    void olvidarCompra() override;
    DTExpCliente verComprasCliente(string nickCliente);
    DTDetallesCompra verDetallesCompra() override;
    virtual ~ControlCompra();
};

#endif