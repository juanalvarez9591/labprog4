#include "Factory.h"
#include "ControlUsuario.h"
#include "ControlFecha.h"
#include "ControlSuscripciones.h"
#include "ControlPromocion.h"
#include "ControlCompra.h"

IControlUsuario* Factory::getControlUsuario() {
    return ControlUsuario::getInstance();
}

IControlFecha* Factory::getControlFecha() {
    return ControlFecha::getInstance();
}

IControlSuscripciones* Factory::getControlSuscripciones() {
    return ControlSuscripciones::getInstance();
}

IControlPromocion* Factory::getControlPromocion() {
    return ControlPromocion::getInstance();
}

 IControlCompra* Factory::getControlCompra(){
    return ControlCompra::getInstance();
 }

IControlSuscripciones* Factory::getControlComentario() {
    return ControlComentario::getInstance();
}