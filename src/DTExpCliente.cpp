#include "DTExpCliente.h"

DTExpCliente::DTExpCliente(string nickname, DTFecha fechaNacimiento, string direccion, string ciudad, vector<DTExpCompra> compras)
        : DTDataCliente(nickname, fechaNacimiento, direccion, ciudad), compras(compras) {}

vector<DTExpCompra> DTExpCliente::getCompras() const {
    return compras;
}