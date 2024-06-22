#ifndef FACTORY_H
#define FACTORY_H

#include "IControlUsuario.h"
#include "IControlFecha.h"
#include "IControlSuscripciones.h"
#include "IControlComentario.h"
#include "IControlPromocion.h"
#include "IControlCompra.h"

class Factory {
public:
    static IControlUsuario* getControlUsuario();
    static IControlFecha* getControlFecha();
    static IControlSuscripciones* getControlSuscripciones();
    static IControlPromocion* getControlPromocion();
    static IControlCompra* getControlCompra();
    static IControlComentario* getControlComentario();
};

#endif