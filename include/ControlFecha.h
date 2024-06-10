#ifndef CONTROL_FECHA_H
#define CONTROL_FECHA_H

#include "IControlFecha.h"

class ControlFecha : public IControlFecha {
public:
    DTFecha getFechaActual() override;
    void setFechaActual(DTFecha fecha) override;
    void agregarDias(int dias) override;
    void agregarMeses(int meses) override;
    void agregarAnios(int anios) override;

private:
    ControlFecha();
    DTFecha fechaActual;

    friend class Factory;
};

#endif // CONTROL_FECHA_H