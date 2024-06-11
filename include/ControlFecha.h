#ifndef CONTROL_FECHA_H
#define CONTROL_FECHA_H

#include "IControlFecha.h"

class ControlFecha : public IControlFecha {
public:
    static ControlFecha* getInstance();
    DTFecha getFechaActual() override;
    void setFechaActual(DTFecha fecha) override;
    void agregarDias(int dias) override;
    void agregarMeses(int meses) override;
    void agregarAnios(int anios) override;

private:
    ControlFecha();
    static ControlFecha* instance;
    DTFecha fechaActual;
};

#endif // CONTROL_FECHA_H