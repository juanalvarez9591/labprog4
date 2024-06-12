#include "DTNotificacion.h"

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

string DTNotificacion::toString() const {
    string notificacionStr = "Notificacion de promocion\n";
    notificacionStr += "Nombre de la promocion: " + nombrePromo + "\n";
    notificacionStr += "Vendedor: " + nickVendedor + "\n";
    notificacionStr += "Productos en promocion:\n";

    for (const DTInfoProducto& producto : productosPromocion) {
        notificacionStr += producto.toString() + "\n";
    }

    return notificacionStr;
}