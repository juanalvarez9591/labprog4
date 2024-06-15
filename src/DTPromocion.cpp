#include "DTPromocion.h"
#include "DTFecha.h"

DTPromocion::DTPromocion() {
    this->nombre = "";
    this->descripcion = "";
    this->fechaVencimiento = DTFecha();
    this->porcentaje = 0;
}

DTPromocion::DTPromocion(string nombre, string descripcion, DTFecha fechaVencimiento, int porcentaje) {
    this->nombre = nombre;
    this->descripcion = descripcion;
    this->fechaVencimiento = fechaVencimiento;
    this->porcentaje = porcentaje;
}

string DTPromocion::getNombre() {
    return this->nombre;
}

string DTPromocion::getDescripcion() {
    return this->descripcion;
}

DTFecha DTPromocion::getFechaVencimiento() {
    return this->fechaVencimiento;
}

int DTPromocion::getPorcentaje() {
    return this->porcentaje;
}