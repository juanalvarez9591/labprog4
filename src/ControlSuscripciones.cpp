#include "ControlSuscripciones.h"
#include "ControlUsuario.h"

ControlSuscripciones* ControlSuscripciones::instance = nullptr;

ControlSuscripciones* ControlSuscripciones::getInstance() {
    if (instance == nullptr) {
        instance = new ControlSuscripciones();
    }
    return instance;
}

ControlSuscripciones::ControlSuscripciones() {
    controlUsuario = ControlUsuario::getInstance();
}

vector<string> ControlSuscripciones::getVendedoresNoSuscritos(string nickCliente) {
    Usuario* usuario = controlUsuario->getUsuario(nickCliente);
    vector<string> vendedoresNoSuscritos;
    vector<Vendedor> vendedores = controlUsuario->getVendedores();

    for (int i = 0; i < vendedores.size(); i++) {
        if (!vendedores[i].estaSuscrito(usuario)) {
            vendedoresNoSuscritos.push_back(vendedores[i].getNickname());
        }
    }

    return vendedoresNoSuscritos;
}

vector<string> ControlSuscripciones::getVendedoresSuscritos(string nickCliente) {
    Usuario* usuario = controlUsuario->getUsuario(nickCliente);
    vector<string> vendedoresSuscritos;
    vector<Vendedor> vendedores = controlUsuario->getVendedores();

    for (int i = 0; i < vendedores.size(); i++) {
        if (vendedores[i].estaSuscrito(usuario)) {
            vendedoresSuscritos.push_back(vendedores[i].getNickname());
        }
    }

    return vendedoresSuscritos;
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