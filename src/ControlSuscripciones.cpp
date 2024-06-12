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

void ControlSuscripciones::suscribirACliente(vector<string> nickVendedores, string nickCliente) {
    Cliente* cliente = controlUsuario->getCliente(nickCliente);
    for (int i = 0; i < nickVendedores.size(); i++) {
        Vendedor* vendedor = controlUsuario->getVendedor(nickVendedores[i]);
        vendedor->agregarObserver(cliente);
    }
    return;
}

void ControlSuscripciones::eliminarSuscripciones(vector<string> nickVendedores, string nickCliente) {
    Cliente* cliente = controlUsuario->getCliente(nickCliente);
    for (int i = 0; i < nickVendedores.size(); i++) {
        Vendedor* vendedor = controlUsuario->getVendedor(nickVendedores[i]);
        vendedor->eliminarObserver(cliente);
    }
    return;
}

vector<DTNotificacion> ControlSuscripciones::listarNotificaciones(string nickCliente) {
    Cliente* cliente = controlUsuario->getCliente(nickCliente);
    vector<DTNotificacion> notificaciones = cliente->listarNotificaciones();
    cliente->limpiarNotificaciones();
    return notificaciones;
}

ControlSuscripciones::~ControlSuscripciones() {
}