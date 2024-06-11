#include "ControlSuscripciones.h"

ControlSuscripciones* ControlSuscripciones::instance = nullptr;

ControlSuscripciones* ControlSuscripciones::getInstance() {
    if (instance == nullptr) {
        instance = new ControlSuscripciones();
    }
    return instance;
}

ControlSuscripciones::ControlSuscripciones() {
}

vector<string> ControlSuscripciones::getVendedoresNoSuscritos(const string& cliente) {
    return vector<string>();
}

vector<string> ControlSuscripciones::getVendedoresSuscritos(const string& cliente) {
    return vector<string>();
}

void ControlSuscripciones::suscribirACliente(vector<string> vendedores, const string& cliente) {
    return;
}

void ControlSuscripciones::eliminarSuscripciones(vector<string> vendedores, const string& cliente) {
    return;
}

vector<DTNotificacion> ControlSuscripciones::listarNotificaciones(const string& cliente) {
    return vector<DTNotificacion>();
}

ControlSuscripciones::~ControlSuscripciones() {
}