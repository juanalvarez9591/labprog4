#include "ControlUsuario.h"
#include "ControlPromocion.h"
#include "ControlCompra.h"
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
   // controlPromocion = ControlPromocion::getInstance();
  //  controlCompra = ControlCompra::getInstance();
}

DTInfoUsuarios ControlUsuario::verExpedienteUsuario(string nickUsuario) {
  /*  Usuario* usuario = getUsuario(nickUsuario);
    if (usuario == nullptr) {
        return DTInfoUsuarios();
    }

    Cliente* cliente = dynamic_cast<Cliente*>(usuario);
    if (cliente != nullptr) {
        DTExpCliente expCliente = controlCompra->verComprasCliente(nickUsuario);
        return expCliente;
    }

    Vendedor* vendedor = dynamic_cast<Vendedor*>(usuario);
    if (vendedor != nullptr) {
        vector<DTPromocion> promociones = controlPromocion->verPromocionesVendedor(nickUsuario);
        vector<DTProducto> productos = controlPromocion->verProductosVendedor(nickUsuario);
        return DTExpVendedor(vendedor->getNickname(),
                                 vendedor->getFechaNacimiento(),
                                 vendedor->getRut(),
                                 promociones,
                                 productos);
    }

    return DTInfoUsuarios();*/
}

bool ControlUsuario::darDeAltaCliente(string nickname, string password, DTFecha fechaNacimiento, int nroPuerta, string calle, string ciudad) {
    if (nicknameRepetido(nickname)) {
        return false;
    }

    Cliente cliente(nickname, password, fechaNacimiento, nroPuerta, calle, ciudad);
    clientes.push_back(cliente);
    return true;
}

bool ControlUsuario::darDeAltaVendedor(string nickname, string password, DTFecha fechaNacimiento, string rut) {
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


vector<DTDataCliente> ControlUsuario::listarInfoClientes() {
    vector<DTDataCliente> dataClientes;
    string calle, ciudad, nickname;
    int nroPuerta;
    DTFecha fechaNacimiento;
    for (auto it = clientes.begin(); it != clientes.end(); ++it){
        nroPuerta = it->getNroPuerta();
        calle = it->getCalle();
        ciudad = it->getCiudad();
        nickname = it->getNickname();
        fechaNacimiento = it->getFechaNacimiento();
        dataClientes.push_back(DTDataCliente(nickname, fechaNacimiento, nroPuerta, calle, ciudad));
    }

    return dataClientes;


}

vector<DTDataVendedor> ControlUsuario::listarInfoVendedores() {
    vector<DTDataVendedor> dataVendedores;
    string  nickname;
    DTFecha fechaNacimiento;
    string rut;
    for (auto it = vendedores.begin(); it !=vendedores.end(); ++it){
        nickname = it->getNickname();
        fechaNacimiento = it->getFechaNacimiento();
        rut = it->getRut();
        dataVendedores.push_back(DTDataVendedor(nickname, fechaNacimiento, rut));
    }

    return dataVendedores;

}





ControlUsuario::~ControlUsuario() {
    // no hay que hacer nada aca, cuando se llama a este destructor por default
    // se llama al destructor de vector, que llama a cada destructor de cliente y vendedor
}