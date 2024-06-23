#include "DTExpVendedor.h"

DTExpVendedor::DTExpVendedor(string nickname, DTFecha fecha, string rut, vector <DTPromocion> promociones, vector <DTProducto> productos)
: DTDataVendedor(nickname, fecha, rut){
    this-> promociones = promociones;
    this->productos = productos;

}
vector<DTPromocion> DTExpVendedor::getPromociones() const {
    return this->promociones;
}
vector<DTProducto> DTExpVendedor::getProductos() const {
    return this->productos;
}
