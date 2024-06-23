#include "DTFecha.h"

DTFecha::DTFecha()
{
    dia = 0;
    mes = 0;
    anio = 0;
}

DTFecha::DTFecha(int dia, int mes, int anio)
{
    this->dia = dia;
    this->mes = mes;
    this->anio = anio;
}

bool DTFecha::operator>=(const DTFecha &F) const
{
    return (anio >= F.anio && mes >= F.mes && dia >= F.dia);
}

string DTFecha::getString() const {
    return to_string(this->dia) + "/" + to_string(this->mes) + "/" + to_string(this->anio);
}

int DTFecha::getDia() const
{
    return dia;
}

int DTFecha::getMes() const
{
    return mes;
}

int DTFecha::getAnio() const
{
    return anio;
}