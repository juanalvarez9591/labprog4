#include "ControlFecha.h"

ControlFecha* ControlFecha::instance = nullptr;

ControlFecha* ControlFecha::getInstance() {
    if (instance == nullptr) {
        instance = new ControlFecha();
    }
    return instance;
}

ControlFecha::ControlFecha() {
    fechaActual = DTFecha(1, 1, 2024);
}

DTFecha ControlFecha::getFechaActual() {
    return fechaActual;
}

void ControlFecha::setFechaActual(DTFecha fecha) {
    fechaActual = fecha;
}

void ControlFecha::agregarDias(int dias) {
    int newDia = fechaActual.getDia() + dias;
    int newMes = fechaActual.getMes();
    int newAnio = fechaActual.getAnio();

    while (newDia <= 0) {
        newMes--;
        if (newMes == 0) {
            newMes = 12;
            newAnio--;
        }
        newDia += 31;
    }

    while (newDia > 31) {
        newDia -= 31;
        newMes++;
        if (newMes > 12) {
            newMes = 1;
            newAnio++;
        }
    }

    fechaActual = DTFecha(newDia, newMes, newAnio);
}

void ControlFecha::agregarMeses(int meses) {
    int newMes = fechaActual.getMes() + meses;
    int newAnio = fechaActual.getAnio();

    while (newMes <= 0) {
        newMes += 12;
        newAnio--;
    }

    while (newMes > 12) {
        newMes -= 12;
        newAnio++;
    }

    fechaActual = DTFecha(fechaActual.getDia(), newMes, newAnio);
}

void ControlFecha::agregarAnios(int anios) {
    int newAnio = fechaActual.getAnio() + anios;
    fechaActual = DTFecha(fechaActual.getDia(), fechaActual.getMes(), newAnio);
}