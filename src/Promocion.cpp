#include "Promocion.h"

Promocion::Promocion() : nombre(""), descripcion(""), fechaVencimiento(DTFecha()), porcentaje(0), requisitos() {}

Promocion::Promocion(string nombre, string descripcion, DTFecha fechaVencimiento, int porcentaje)
        : nombre(nombre), descripcion(descripcion), fechaVencimiento(fechaVencimiento),
          porcentaje(porcentaje), requisitos() {}

string Promocion::getNombre() {
    return nombre;
}

void Promocion::setNombre(string nombre) {
    this->nombre = nombre;
}

string Promocion::getDescripcion() {
    return descripcion;
}

void Promocion::setDescripcion(string descripcion) {
    this->descripcion = descripcion;
}

DTFecha Promocion::getFechaVencimiento() const {
    return fechaVencimiento;
}

void Promocion::setFechaVencimiento(DTFecha fechaVencimiento) {
    this->fechaVencimiento = fechaVencimiento;
}

int Promocion::getPorcentaje() {
    return porcentaje;
}

void Promocion::setPorcentaje(int porcentaje) {
    this->porcentaje = porcentaje;
}

void Promocion::agregarRequisitos(Requisitos requisito) {
    requisitos.push_back(requisito);
}

void Promocion::eliminarRequisitos(Requisitos requisito) {
    for (int i = 0; i < requisitos.size(); i++) {
        if (requisitos[i] == requisito) {
            requisitos.erase(requisitos.begin() + i);
            break;
        }
    }
}

 const vector<Requisitos>& Promocion::getRequisitos() const {
    return requisitos;
}

DTPromocion Promocion::toDTPromocion() const {
    return DTPromocion(nombre, descripcion, fechaVencimiento, porcentaje);
}