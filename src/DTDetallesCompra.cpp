#include "DTDetallesCompra.h"
#include "DTProducto.h"
#include "DTFecha.h"

DTDetallesCompra::DTDetallesCompra(){
    this->costo = 0;
    this->fecha = DTFecha();
    this->productos = vector<DTProducto>();
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

string DTDetallesCompra::toString() const {
    string result = "";
    result += "Costo: " + to_string(costo) + "\n";
    result += "Fecha: " + fecha.getString() + "\n";
    result += "Productos:\n";

    for (vector<DTProducto>::const_iterator it = productos.begin(); it != productos.end(); ++it) {
        result += "- " + it->toString() + "\n";
    }

    return result;
}