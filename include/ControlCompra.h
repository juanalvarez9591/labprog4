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
#include "ControlUsuario.h"
#include "ControlPromocion.h"
#include "ControlFecha.h"


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
    Vendedor* vendedorEnMemoria;
    Compra* compraEnProceso;
    Producto* productoEnMemoria;
    vector<int> comprasEnMemoria;


public:
    static ControlCompra* getInstance();
    void seleccionarCliente(string nickCliente) override;
    bool agregarCantidad(int codigo, int cantidad) override;
    bool confirmarCompra() override;
    void olvidarCompra() override;
    DTExpCliente verComprasCliente(string nickCliente);
    DTDetallesCompra verDetallesCompra() override;
    bool elegirVendedor(string nickVendedor) override;
    vector<DTProducto> listarProductosAptosDelVendedor() override;
    bool elegirProducto(int id) override;
    vector<DTCompra> listarComprasCliente() override;
    bool marcarComoEnviado(int codigo) override;
    virtual ~ControlCompra();
};


#endif