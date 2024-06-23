#include "Compra.h"
#include "DTExpCompra.h"
#include "DTExpProducto.h"

Compra::Compra(DTFecha fechaCompra, Cliente* cliente) {
    this->fechaCompra = fechaCompra;
    this->costo = 0;
    this->cliente = cliente;
    this->cantidades = vector<Cantidad*>();
}

Cliente* Compra::getCliente() const {
    return this->cliente;
}

DTExpCompra Compra::toDTExpCompra() const {
    vector<DTExpProducto> dtProductos;
    float totalCosto = 0;

    for (vector<Cantidad*>::const_iterator it = cantidades.begin(); it != cantidades.end(); ++it) {
        Cantidad* cantidad = *it;
        Producto* producto = cantidad->getProducto();
        int cantidadProducto = cantidad->getCantidad();
        float costoProducto = producto->getPrecio() * cantidadProducto;

        dtProductos.push_back(DTExpProducto(
                producto->getId(),
                cantidadProducto,
                producto->getNombre(),
                cantidad->getEnviado()
        ));

        totalCosto += costoProducto;
    }

    return DTExpCompra(totalCosto, fechaCompra, dtProductos);
}
DTFecha Compra::getFechaCompra() {
    return this->fechaCompra;
}

void Compra::setCosto(float newCosto) {
    this->costo = newCosto;
}

void Compra::agregarCantidad(Cantidad* cantidad) {
    this->cantidades.push_back(cantidad);
}

void Compra::eliminarCantidad(Cantidad* cantidad) {
    for (auto it = this->cantidades.begin(); it != this->cantidades.end(); ++it) {
        if (*it == cantidad) {
            this->cantidades.erase(it);
            break;
        }
    }
}

vector<Cantidad*>& Compra::getCantidades() {
    return this->cantidades;
}