#ifndef ICONTROL_FECHA_H
#define ICONTROL_FECHA_H

#include "DTFecha.h"

class IControlFecha {
public:
    virtual DTFecha getFechaActual() = 0;
    virtual void setFechaActual(DTFecha fecha) = 0;
    virtual void agregarDias(int dias) = 0;
    virtual void agregarMeses(int meses) = 0;
    virtual void agregarAnios(int anios) = 0;
    virtual ~IControlFecha() {}
};

#endif // ICONTROL_FECHA_H