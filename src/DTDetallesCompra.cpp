#include "../include/DTDetallesCompra.h"

DTDetallesCompra::DTDetallesCompra(){
    this-> costo = 0;
    this-> fecha = NULL;
    this-> productos = NULL;
}

DTDetallesCompra::DTDetallesCompra(float costo, DTFecha fecha, vector<DTProducto> productos){
    this->costo = costo;
    this->fecha = fecha;
    this->productos = productos;
}

float DTDetallesCompra::getCosto(){
    return this->costo;

}

DTFecha DTDetallesCompra::getFecha(){
    return this->fecha;
}
vector<DTProducto> DTDetallesCompra::getProductos(){

    return this->productos;
}