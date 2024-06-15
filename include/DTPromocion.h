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
    string getNombre();
    string getDescripcion();
    DTFecha getFechaVencimiento();
    int getPorcentaje();
};

#endif