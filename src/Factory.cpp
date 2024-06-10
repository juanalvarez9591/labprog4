#include "Factory.h"
#include "ControlUsuario.h"
#include "ControlFecha.h"
/*#include "ControlPromocion.h"
#include "ControlCompra.h"
#include "ControlSuscripciones.h"*/

IControlUsuario* Factory::controlUsuario = nullptr;
IControlFecha* Factory::controlFecha = nullptr;
/*
    IControlPromocion* Factory::controlPromocion = nullptr;
    IControlCompra* Factory::controlCompra = nullptr;
    IControlSuscripciones* Factory::controlSuscripciones = nullptr;
*/


IControlUsuario* Factory::getControlUsuario() {
    if (controlUsuario == nullptr) {
        controlUsuario = new ControlUsuario();
    }
    return controlUsuario;
}

IControlFecha* Factory::getControlFecha() {
    if (controlFecha == nullptr) {
        controlFecha = new ControlFecha();
    }
    return controlFecha;
}

/*

IControlPromocion* Factory::getControlPromocion() {
    if (controlPromocion == nullptr) {
        controlPromocion = new ControlPromocion();
    }
    return controlPromocion;
}

IControlCompra* Factory::getControlCompra() {
    if (controlCompra == nullptr) {
        controlCompra = new ControlCompra();
    }
    return controlCompra;
}

IControlSuscripciones* Factory::getControlSuscripciones() {
    if (controlSuscripciones == nullptr) {
        controlSuscripciones = new ControlSuscripciones();
    }
    return controlSuscripciones;
}*/
