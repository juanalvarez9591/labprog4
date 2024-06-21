#include "DTNotificacion.h"

DTNotificacion::DTNotificacion() {
    this->nombrePromo = "";
    this->nickVendedor = "";
    this->codigosProductos = vector<int>();
}

DTNotificacion::DTNotificacion(string nombrePromo, string nickVendedor, vector<int> codigosProductos) {
    this->nombrePromo = nombrePromo;
    this->nickVendedor = nickVendedor;
    this->codigosProductos = codigosProductos;
}

string DTNotificacion::toString() const {
    string notificacionStr = "Notificacion de promocion\n";
    notificacionStr += "Nombre de la promocion: " + nombrePromo + "\n";
    notificacionStr += "Vendedor: " + nickVendedor + "\n";
    notificacionStr += "Productos en promocion:\n";

    for (int i = 0; i < codigosProductos.size(); i++) {
        notificacionStr += "Codigo del producto: " + to_string(codigosProductos[i]) + "\n";
    }

    return notificacionStr;
}