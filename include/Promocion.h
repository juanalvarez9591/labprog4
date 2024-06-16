#ifndef PROMOCION_H
#define PROMOCION_H

#include <string>
#include <vector>
#include "Requisitos.h"
#include "DTFecha.h"
#include "DTPromocion.h"

using namespace std;

class Promocion {
private:
    string nombre;
    string descripcion;
    DTFecha fechaVencimiento;
    int porcentaje;
    vector<Requisitos> requisitos;

public:
    Promocion();
    Promocion(string nombre, string descripcion, DTFecha fechaVencimiento, int porcentaje);

    string getNombre();
    void setNombre(string nombre);

    string getDescripcion();
    void setDescripcion(string descripcion);

    DTFecha getFechaVencimiento() const;
    void setFechaVencimiento(DTFecha fechaVencimiento);

    int getPorcentaje();
    void setPorcentaje(int porcentaje);

    void agregarRequisitos(Requisitos requisito);
    void eliminarRequisitos(Requisitos requisito);
    vector<Requisitos> getRequisitos();

    DTPromocion toDTPromocion() const;
};

#endif