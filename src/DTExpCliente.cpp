#include "DTExpCliente.h"
#include <sstream>

DTExpCliente::DTExpCliente(): DTDataCliente(){

}

DTExpCliente::DTExpCliente(string nickname, DTFecha fechaNacimiento, int nroPuerta, string calle, string ciudad, vector<DTExpCompra> compras)
        : DTDataCliente(nickname, fechaNacimiento, nroPuerta, calle, ciudad) {
            this->compras = compras;
        }

vector<DTExpCompra> DTExpCliente::getCompras() const {
    return compras;
}

string DTExpCliente::getInfoCompras() const{
    ostringstream ss;
    ss << "Información de compras:" << endl;
    for (const auto& compra : compras) {
        ss << "Costo: $" << to_string(compra.getCosto()) << endl;
        ss << "Fecha de compra: " << compra.getFecha().getString() << endl;
        ss << "Productos:" << endl;
        vector<DTExpProducto> productos = compra.getProductos();
        for (const auto& producto : productos) {
            ss << " - Código: " << producto.getCodigoProducto() << ", Nombre: " << producto.getNombreProducto() << ", Cantidad: " << producto.getCantidadProducto() << endl;
        }
        ss << endl;
    }
    return ss.str();

}

DTExpCliente::~DTExpCliente() {
}