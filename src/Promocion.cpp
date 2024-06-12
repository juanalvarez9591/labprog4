#include "Promocion.h"

Promocion::Promocion(string nombre, string descripcion, string fechaVencimiento, float porcentaje)
        : nombre(nombre), descripcion(descripcion), fechaVencimiento(fechaVencimiento),
          porcentaje(porcentaje) {}

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

string Promocion::getFechaVencimiento() {
    return fechaVencimiento;
}

void Promocion::setFechaVencimiento(string fechaVencimiento) {
    this->fechaVencimiento = fechaVencimiento;
}

float Promocion::getPorcentaje() {
    return porcentaje;
}

void Promocion::setPorcentaje(float porcentaje) {
    this->porcentaje = porcentaje;
}

void Promocion::addRequisitos(Requisitos requisito) {
    requisitos.push_back(requisito);
}

void Promocion::removeRequisitos(Requisitos requisito) {
    for (int i = 0; i < requisitos.size(); i++) {
        if (requisitos[i] == requisito) {
            requisitos.erase(requisitos.begin() + i);
            break;
        }
    }
}

vector<Requisitos> Promocion::getRequisitos() {
    return requisitos;
}