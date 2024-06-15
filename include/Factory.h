#ifndef FACTORY_H
#define FACTORY_H

#include "IControlUsuario.h"
#include "IControlFecha.h"
#include "IControlSuscripciones.h"
#include "IControlPromocion.h"

class Factory {
public:
    static IControlUsuario* getControlUsuario();
    static IControlFecha* getControlFecha();
    static IControlSuscripciones* getControlSuscripciones();
    static IControlPromocion* getControlPromocion();
};

#endif