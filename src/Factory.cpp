#include "Factory.h"
#include "ControlUsuario.h"
#include "ControlPromocion.h"
#include "ControlCompra.h"
#include "ControlSuscripciones.h"

Factory::Factory() {
    controlUsuario = new ControlUsuario();
    controlPromocion = new ControlPromocion();
    controlCompra = new ControlCompra();
    controlSuscripciones = new ControlSuscripciones();
}

IControlUsuario* Factory::getControlUsuario() {
    return controlUsuario;
}

IControlPromocion* Factory::getControlPromocion() {
    return controlPromocion;
}

IControlCompra* Factory::getControlCompra() {
    return controlCompra;
}

IControlSuscripciones* Factory::getControlSuscripciones() {
    return controlSuscripciones;
}