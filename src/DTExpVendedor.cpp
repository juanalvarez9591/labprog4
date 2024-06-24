#include "DTExpVendedor.h"
#include "ControlFecha.h"

DTExpVendedor::DTExpVendedor(string nickname, DTFecha fecha, string rut, vector <DTPromocion> promociones, vector <DTProducto> productos)
: DTDataVendedor(nickname, fecha, rut){
    this-> promociones = promociones;
    this->productos = productos;

}
vector<DTPromocion> DTExpVendedor::getPromociones() const {

DTFecha fechaActual = ControlFecha::getInstance()->getFechaActual();
vector<DTPromocion> promocionesVigentes;
 for (const auto& promocion : promociones) {
        if (promocion.getFechaVencimiento() >= fechaActual) {
            promocionesVigentes.push_back(promocion);
        }
    }

    return promocionesVigentes;
}
vector<DTProducto> DTExpVendedor::getProductos() const {
    return this->productos;
}
