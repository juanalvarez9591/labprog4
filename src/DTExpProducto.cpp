#include "DTExpProducto.h"

DTExpProducto::DTExpProducto(){
    this->codigoProducto = 0;
    this-> cantidadProducto = 0;
    this-> nombreProducto = "";

}
DTExpProducto::DTExpProducto(int codigoProducto, int cantidadProducto, string nombreProducto){
    this->codigoProducto = codigoProducto;
    this->cantidadProducto= cantidadProducto;
    this-> nombreProducto = nombreProducto;
}
int DTExpProducto::getCodigoProducto() const{
    return this->codigoProducto;

}
int DTExpProducto::getCantidadProducto() const{
    return this->cantidadProducto;

}
string DTExpProducto::getNombreProducto()const{
    return this-> nombreProducto;

}
