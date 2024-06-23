#include "ControlCompra.h"
#include "ControlPromocion.h"
#include "ControlUsuario.h"
#include "ControlFecha.h"
#include "DTExpCliente.h"
#include "Compra.h"


ControlCompra* ControlCompra::instance = nullptr;

ControlCompra::ControlCompra() {
    controlUsuario = ControlUsuario::getInstance();
    controlFecha = ControlFecha::getInstance();
    controlPromocion = ControlPromocion::getInstance();

    compras = unordered_map<int, Compra*>();
    clienteEnMemoria = nullptr;
    compraEnProceso = nullptr;
}

ControlCompra* ControlCompra::getInstance() {
    if (instance == nullptr) {
        instance = new ControlCompra();
    }
    return instance;
}



void ControlCompra::seleccionarCliente(string nickCliente) {
    clienteEnMemoria = controlUsuario->getCliente(nickCliente);
    compraEnProceso = new Compra(controlFecha->getFechaActual(), clienteEnMemoria);
}

bool ControlCompra::agregarCantidad(int codigo, int cantidad) {
    if (compraEnProceso == nullptr) {
        return false;
    }

    Producto* productoElegido = controlPromocion->getProductoByID(codigo);
    if (productoElegido == nullptr) {
        return false;
    }

    if (cantidad <= 0 || cantidad > productoElegido->getStock()) {
        return false;
    }

    vector<Cantidad*>& cantidades = compraEnProceso->getCantidades();
    for (vector<Cantidad*>::iterator it = cantidades.begin(); it != cantidades.end(); ++it) {
        if ((*it)->getProducto() == productoElegido) {
            int newCantidad = (*it)->getCantidad() + cantidad;
            if (newCantidad <= productoElegido->getStock()) {
                (*it)->setCantidad(newCantidad);
                return true;
            } else {
                return false;
            }
        }
    }

    Cantidad* aux = new Cantidad(cantidad, productoElegido);
    compraEnProceso->agregarCantidad(aux);
    return true;
}

void ControlCompra::olvidarCompra() {
    if (compraEnProceso != nullptr) {
        delete compraEnProceso;
        compraEnProceso = nullptr;
    }
    clienteEnMemoria = nullptr;
}

bool ControlCompra::confirmarCompra() {
    if (compraEnProceso == nullptr) {
        return false;
    }
    int clave = compras.size() + 1;
    vector<Cantidad*>& cantidades = compraEnProceso->getCantidades();
    for (vector<Cantidad*>::iterator it = cantidades.begin(); it != cantidades.end(); ++it) {
        Producto* producto = (*it)->getProducto();
        int cantidadComprada = (*it)->getCantidad();
        producto->actualizarStock(cantidadComprada);
    }
    compras[clave] = compraEnProceso;
    clienteEnMemoria = nullptr;
    compraEnProceso = nullptr;
    return true;
}

DTDetallesCompra ControlCompra::verDetallesCompra() {
    if (compraEnProceso == nullptr) {
        return DTDetallesCompra();
    }

    float costoTotal = 0;
    vector<DTProducto> productosCompra;
    vector<Cantidad*>& cantidades = compraEnProceso->getCantidades();

    for (vector<Cantidad*>::iterator it = cantidades.begin(); it != cantidades.end(); ++it) {
        Producto* producto = (*it)->getProducto();
        int cantidad = (*it)->getCantidad();

        float precioProducto = controlPromocion->calcularPrecioTotal(producto->getId(), cantidad);

        costoTotal += precioProducto;

        productosCompra.push_back(producto->toDTProducto());
    }

    DTFecha fechaCompra = compraEnProceso->getFechaCompra();

    return DTDetallesCompra(costoTotal, fechaCompra, productosCompra);
}

DTExpCliente ControlCompra::verComprasCliente(string nickCliente) {
    Cliente* cliente = controlUsuario->getCliente(nickCliente);
    if (cliente == nullptr) {
        return DTExpCliente();
    }

    vector<DTExpCompra> comprasCliente;

    for (unordered_map<int, Compra*>::iterator it = compras.begin(); it != compras.end(); ++it) {
        Compra* compra = it->second;
        if (compra->getCliente() == cliente) {
            comprasCliente.push_back(compra->toDTExpCompra());
        }
    }

    return DTExpCliente(
            cliente->getNickname(),
            cliente->getFechaNacimiento(),
            cliente->getNroPuerta(),
            cliente->getCalle(),
            cliente->getCiudad(),
            comprasCliente);
}

bool ControlCompra::elegirVendedor(string nombre){  
    this->vendedorEnMemoria = controlUsuario->getVendedor(nombre);
    return (this->vendedorEnMemoria != nullptr); 
}

unordered_map<int, DTProducto> ControlCompra::listarProductosVendedorAptos(){
    unordered_map<int, DTProducto> productosAptos;
    vector<DTProducto> Catalogo = this->controlPromocion->verProductosVendedor(this->vendedorEnMemoria->getNickname());

    for (vector<DTProducto>::iterator iterprod = Catalogo.begin(); iterprod != Catalogo.end(); ++iterprod) {
        
        for (unordered_map<int, Compra*>::iterator itcompra = compras.begin(); itcompra != compras.end(); ++itcompra) {
            Compra* compra = itcompra->second;
            vector<Cantidad*>& cantidades = compra->getCantidades();

            for (auto itercantidad = cantidades.begin(); itercantidad != cantidades.end(); ++itercantidad){
                bool estadoCompra = (*itercantidad)->getEnviado();
                if (!(estadoCompra) && ((iterprod)->getId() == (*itercantidad)->getProducto()->getId())){
                    int Idprod = (*itercantidad)->getProducto()->getId();
                    if (productosAptos.find(Idprod) != nullptr ){
                        productosAptos.insert({Idprod, (*iterprod) });
                    }
                }
            }
        }
    }
    return productosAptos;
}
//Dado que control promocion busca por el id tuvimos que cambiar a que pase el ID
bool ControlCompra::elegirProducto(int IDProducto){
    this->productoEnMemoria = this->controlPromocion->getProductoByID(IDProducto);
    return (this->productoEnMemoria != nullptr);
}


vector<DTCompra> ControlCompra::listarComprasCliente(){
    vector<DTCompra> Salida;
    for (unordered_map<int, Compra*>::iterator itcompra = compras.begin(); itcompra != compras.end(); ++itcompra) {
        Compra* compraactual = itcompra->second;
        vector<Cantidad*>& cantidades = compraactual->getCantidades();
        for (auto itercantidad = cantidades.begin(); itercantidad != cantidades.end(); ++itercantidad){
                if (itercantidad->getProducto() == this->productoEnMemoria){
                    Salida.push_back(compraactual->toDTCompra());
                }
            }
    }
    return Salida;
}
//getCantidades
//marcarComoEnviado()
void ControlCompra::marcarComoEnviado(string nickCliente){
    int clave = this->compras.size();
    bool foundprod = false;
    int itermap = 0;
    Cliente* clienteElegido = nullptr; 
    while( !(foundprod) && (itermap <= clave)){
        if (this->compras[itermap]->getCliente()->getNickname() == nickCliente){

            vector<Cantidad*>& cantidades = this->compras[itermap]->getCantidades();
            for (auto itercantidad = cantidades.begin(); itercantidad != cantidades.end(); ++itercantidad){
                    if (itercantidad->getProducto() == this->productoEnMemoria){
                        foundprod = true;
                        itercantidad->setEnviado(true);
                    }
                }
        }
            
        
    }
}

ControlCompra::~ControlCompra() {
    for (auto& pair : compras) {
        delete pair.second;
    }
    delete compraEnProceso;
}