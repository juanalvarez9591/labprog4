#ifndef DTPROMOCION_H
#define DTPROMOCION_H

#include "DTFecha.h"
#include <string>
using namespace std;

class DTPromocion {
private:
    string nombre;
    string descripcion;
    DTFecha fechaVencimiento;
    int porcentaje;

public:
    DTPromocion();
    DTPromocion(string nombre, string descripcion, DTFecha fechaVencimiento, int porcentaje);
    string getNombre() const;
    string getDescripcion() const;
    DTFecha getFechaVencimiento() const;
    bool operator<(const DTPromocion& other) const;
    int getPorcentaje() const;
};

#endif