#include "../include/DTDetalleProducto.h"

DTDetalleProducto::DTDetalleProducto(){
this-> codigoProducto = 0;
this-> cantProducto = 0;

}

DTDetalleProducto::DTDetalleProducto(int codigoProducto, int cantProducto){
    this-> codigoProducto = codigoProducto;
    this->cantProducto = cantProducto;

}
int DTDetalleProducto::getCodigoProducto(){
return this->codigoProducto;

}
int DTDetalleProducto::getCantProducto(){
return this->cantProducto;
}