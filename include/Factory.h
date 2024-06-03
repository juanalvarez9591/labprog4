#ifndef FACTORY_H
#define FACTORY_H

#include "IControlUsuario.h"
#include "IControlPromocion.h"
#include "IControlCompra.h"
#include "IControlSuscripciones.h"

class Factory {
public:
    Factory();

    IControlUsuario* getControlUsuario();
    IControlPromocion* getControlPromocion();
    IControlCompra* getControlCompra();
    IControlSuscripciones* getControlSuscripciones();

private:
    IControlUsuario* controlUsuario;
    IControlPromocion* controlPromocion;
    IControlCompra* controlCompra;
    IControlSuscripciones* controlSuscripciones;
};

#endif