#ifndef CONTROL_SUSCRIPCIONES_H
#define CONTROL_SUSCRIPCIONES_H

#include <string>
#include <vector>
#include "Cliente.h"
#include "Vendedor.h"
#include "IControlSuscripciones.h"
#include "ControlUsuario.h"
#include "DTNotificacion.h"
using namespace std;

class ControlSuscripciones : public IControlSuscripciones {
public:
    static ControlSuscripciones* getInstance();
    vector<string> getVendedoresNoSuscritos(string nickCliente) override;
    vector<string> getVendedoresSuscritos(string nickCliente) override;
    void suscribirACliente(vector<string> nickVendedores, string nickCliente) override;
    void eliminarSuscripciones(vector<string> nickVendedores, string nickCliente) override;
    vector<DTNotificacion> listarNotificaciones(string nickCliente) override;
    virtual ~ControlSuscripciones();

private:
    ControlSuscripciones();
    static ControlSuscripciones* instance;
    ControlUsuario* controlUsuario;
};

#endif