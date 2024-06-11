#ifndef CONTROL_SUSCRIPCIONES_H
#define CONTROL_SUSCRIPCIONES_H

#include <string>
#include <vector>
#include "Cliente.h"
#include "Vendedor.h"
#include "IControlSuscripciones.h"
#include "DTNotificacion.h"
using namespace std;

class ControlSuscripciones : public IControlSuscripciones {
public:
    static ControlSuscripciones* getInstance();
    vector<string> getVendedoresNoSuscritos(const string&) override;
    vector<string> getVendedoresSuscritos(const string&) override;
    void suscribirACliente(vector<string>, const string&) override;
    void eliminarSuscripciones(vector<string>, const string&) override;
    vector<DTNotificacion> listarNotificaciones(const string&) override;
    virtual ~ControlSuscripciones();

private:
    ControlSuscripciones();
    static ControlSuscripciones* instance;
};

#endif