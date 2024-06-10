#include "../include/DTNotificacion.h"

DTNotificacion::DTNotificacion() {
    this->nombrePromo = "";
    this->nickVendedor = "";
    this->productosPromocion = vector<DTInfoProducto>();
}

DTNotificacion::DTNotificacion(string nombrePromo, string nickVendedor, vector<DTInfoProducto> productos) {
    this->nombrePromo = nombrePromo;
    this->nickVendedor = nickVendedor;
    this->productosPromocion = productos;
}