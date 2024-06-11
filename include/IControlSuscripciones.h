#ifndef ICONTROL_SUSCRIPCIONES_H
#define ICONTROL_SUSCRIPCIONES_H

#include <string>
#include <vector>
#include "DTNotificacion.h"
using namespace std;


class IControlSuscripciones {
public:
    virtual vector<string> getVendedoresNoSuscritos(string nickCliente) = 0;
    virtual vector<string> getVendedoresSuscritos(string nickCliente) = 0;
    virtual void suscribirACliente(vector<string>, const string&) = 0; 
    virtual void eliminarSuscripciones(vector<string>, const string&) = 0; 
    virtual vector<DTNotificacion> listarNotificaciones(const string&) = 0;
    virtual ~IControlSuscripciones() = default;
};
#endif