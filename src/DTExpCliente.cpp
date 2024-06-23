#include "DTExpCliente.h"

DTExpCliente::DTExpCliente(): DTDataCliente(){

}

DTExpCliente::DTExpCliente(string nickname, DTFecha fechaNacimiento, int nroPuerta, string calle, string ciudad, vector<DTExpCompra> compras)
        : DTDataCliente(nickname, fechaNacimiento, nroPuerta, calle, ciudad) {}

vector<DTExpCompra> DTExpCliente::getCompras() const {
    return compras;
}

DTExpCliente::~DTExpCliente() {
}