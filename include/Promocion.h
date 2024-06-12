#ifndef PROMOCION_H
#define PROMOCION_H

#include <string>
#include <vector>
#include "Requisitos.h"

using namespace std;

class Promocion {
private:
    string nombre;
    string descripcion;
    string fechaVencimiento;
    float porcentaje;
    vector<Requisitos> requisitos;

public:
    Promocion(string nombre, string descripcion, string fechaVencimiento, float porcentaje);

    string getNombre();
    void setNombre(string nombre);

    string getDescripcion();
    void setDescripcion(string descripcion);

    string getFechaVencimiento();
    void setFechaVencimiento(string fechaVencimiento);

    float getPorcentaje();
    void setPorcentaje(float porcentaje);

    void addRequisitos(Requisitos requisito);
    void removeRequisitos(Requisitos requisito);
    vector<Requisitos> getRequisitos();
};

#endif