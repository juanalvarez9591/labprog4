#ifndef FACTORY_H
#define FACTORY_H

#include "IControlUsuario.h"
#include "IControlFecha.h"
#include "IControlSuscripciones.h"
/*#include "IControlPromocion.h"
#include "IControlCompra.h"*/


class Factory {
public:
    static IControlUsuario* getControlUsuario();
    static IControlFecha* getControlFecha();
    /*static IControlPromocion* getControlPromocion();
    static IControlCompra* getControlCompra();*/
    static IControlSuscripciones* getControlSuscripciones();

private:
    static IControlUsuario* controlUsuario;
    static IControlFecha* controlFecha;
    /*static IControlPromocion* controlPromocion;
    static IControlCompra* controlCompra;*/
    static IControlSuscripciones* controlSuscripciones;
};

#endif