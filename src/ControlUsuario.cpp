#include "ControlUsuario.h"
#include "DTExpCliente.h"
#include "DTExpVendedor.h"

ControlUsuario* ControlUsuario::instance = nullptr;

ControlUsuario* ControlUsuario::getInstance() {
    if (instance == nullptr) {
        instance = new ControlUsuario();
    }
    return instance;
}

ControlUsuario::ControlUsuario() {
    clientes = vector<Cliente>();
    vendedores = vector<Vendedor>();
    controlPromocion = ControlPromocion::getInstance();
    controlCompra = ControlCompra::getInstance();
}

DTInfoUsuarios* ControlUsuario::verExpedienteUsuario(string nickUsuario) {
    Usuario* usuario = getUsuario(nickUsuario);
    if (usuario == nullptr) {
        return nullptr;
    }

    Cliente* cliente = dynamic_cast<Cliente*>(usuario);
    if (cliente != nullptr) {
        vector<DTExpCompra> compras = controlCompra->getComprasCliente(nickUsuario);
        return new DTExpCliente(cliente->getNickname(),
                                cliente->getFechaNacimiento(),
                                cliente->getDireccion(),
                                cliente->getCiudad(),
                                cliente->getNroPuerta(),
                                compras);
    }

    Vendedor* vendedor = dynamic_cast<Vendedor*>(usuario);
    if (vendedor != nullptr) {
        vector<DTPromocion> promociones = controlPromocion->getPromocionesVendedor(nickUsuario);
        vector<DTProducto> productos = controlPromocion->getProductosVendedor(nickUsuario);
        return new DTExpVendedor(vendedor->getNickname(),
                                 vendedor->getFechaNacimiento(),
                                 vendedor->getRut(),
                                 promociones,
                                 productos);
    }

    return nullptr;
}

bool ControlUsuario::darDeAltaCliente(string nickname, string password, DTFecha fechaNacimiento, string direccion, string ciudad) {
    if (nicknameRepetido(nickname)) {
        return false;
    }

    Cliente cliente(nickname, password, fechaNacimiento, direccion, ciudad);
    clientes.push_back(cliente);
    return true;
}

bool ControlUsuario::darDeAltaVendedor(string nickname, string password, DTFecha fechaNacimiento, int rut) {
    if (nicknameRepetido(nickname)) {
        return false;
    }

    Vendedor vendedor(nickname, password, fechaNacimiento, rut);
    vendedores.push_back(vendedor);
    return true;
}

bool ControlUsuario::nicknameRepetido(string nickname) {
    for (auto it = clientes.begin(); it != clientes.end(); it++) {
        if (it->getNickname() == nickname) {
            return true;
        }
    }
    for (auto it = vendedores.begin(); it != vendedores.end(); it++) {
        if (it->getNickname() == nickname) {
            return true;
        }
    }

    return false;
}

vector<string> ControlUsuario::listarNicknamesUsuarios() {
    vector<string> nicknames;
    for (auto it = clientes.begin(); it != clientes.end(); it++) {
        nicknames.push_back(it->getNickname());
    }
    for (auto it = vendedores.begin(); it != vendedores.end(); it++) {
        nicknames.push_back(it->getNickname());
    }

    return nicknames;
}

vector<string> ControlUsuario::listarNicknamesClientes() {
    vector<string> nicknames;
    for (auto it = clientes.begin(); it != clientes.end(); it++) {
        nicknames.push_back(it->getNickname());
    }

    return nicknames;
}


vector<string> ControlUsuario::listarNicknamesVendedores() {
    vector<string> nicknames;
    for (auto it = vendedores.begin(); it != vendedores.end(); it++) {
        nicknames.push_back(it->getNickname());
    }

    return nicknames;
}

Usuario* ControlUsuario::getUsuario(string nickname) {
    for (auto it = clientes.begin(); it != clientes.end(); it++) {
        if (it->getNickname() == nickname) {
            return &(*it);
        }
    }
    for (auto it = vendedores.begin(); it != vendedores.end(); it++) {
        if (it->getNickname() == nickname) {
            return &(*it);
        }
    }

    return nullptr;
}

Vendedor* ControlUsuario::getVendedor(string nickname) {
    for (auto it = vendedores.begin(); it != vendedores.end(); it++) {
        if (it->getNickname() == nickname) {
            return &(*it);
        }
    }

    return nullptr;
}

Cliente* ControlUsuario::getCliente(string nickname) {
    for (auto it = clientes.begin(); it != clientes.end(); it++) {
        if (it->getNickname() == nickname) {
            return &(*it);
        }
    }

    return nullptr;
}

vector<Vendedor> ControlUsuario::getVendedores() {
    return vendedores;
}

ControlUsuario::~ControlUsuario() {
    // no hay que hacer nada aca, cuando se llama a este destructor por default
    // se llama al destructor de vector, que llama a cada destructor de cliente y vendedor
}