#include "ControlPromocion.h"
#include "ControlUsuario.h"
#include "ControlFecha.h"
#include "DTPromocion.h"
#include "DTInfoProducto.h"
#include "DTProducto.h"
#include "Categoria.h"

ControlPromocion* ControlPromocion::instance = nullptr;

ControlPromocion* ControlPromocion::getInstance() {
    if (instance == nullptr) {
        instance = new ControlPromocion();
    }
    return instance;
}

ControlPromocion::ControlPromocion() {
    controlUsuario = ControlUsuario::getInstance();
    controlFecha = ControlFecha::getInstance();

    productos = vector<Producto>();
    promociones = vector<Promocion>();
    requisitos = vector<Requisitos>();

    Vendedor* vendedorEnMemoria = nullptr;
    Promocion* promocionEnMemoria = nullptr;
}

set<string> ControlPromocion::listarNicknameVendedores() {
    vector<Vendedor> vendedores = controlUsuario->getVendedores();
    set<string> nicknames;
    for (int i = 0; i < vendedores.size(); i++) {
        nicknames.insert(vendedores[i].getNickname());
    }
    return nicknames;
}

bool ControlPromocion::elegirVendedor(string nickVendedor) {
    Vendedor* vendedorElegido = controlUsuario->getVendedor(nickVendedor);
    this->vendedorEnMemoria = vendedorElegido;
    return vendedorElegido != nullptr;
}

void ControlPromocion::ingresarProducto(string nombre, string descripcion, float precio, int stock, string categoria) {
    if (this->vendedorEnMemoria == nullptr) {
        return;
    }

    Categoria cat = fromString(categoria);

    int codigoProducto = productos.size() + 1;

    Producto producto = Producto(nombre, descripcion, codigoProducto, stock, precio, cat, this->vendedorEnMemoria);

    productos.push_back(producto);

    vendedorEnMemoria = nullptr;
}

vector<DTProducto> ControlPromocion::listarProductos() {
    vector<DTProducto> dtProductos;
    for (int i = 0; i < productos.size(); i++) {
        Producto producto = productos[i];
        DTProducto dtProducto = producto.toDTProducto();
        dtProductos.push_back(dtProducto);
    }
    return dtProductos;
}

DTInfoProducto ControlPromocion::verInfoProducto(int idProducto) {
    for (int i = 0; i < productos.size(); i++) {
        Producto producto = productos[i];
        if (producto.getId() == idProducto) {
            return producto.toDTInfoProducto();
        }
    }
    return DTInfoProducto();
}


void ControlPromocion::ingresarDatosPromocion(string nombre, string descripcion, DTFecha fechaVencimiento, int porcentaje) {
    Promocion promocion = Promocion(nombre, descripcion, fechaVencimiento, porcentaje);
    this->promocionEnMemoria = &promocion;
    return;
}

vector<DTProducto> ControlPromocion::verProductosVendedor() {
    vector<DTProducto> dtProductos;
    for (int i = 0; i < productos.size(); i++) {
        Producto producto = productos[i];
        if (producto.getVendedor() == this->vendedorEnMemoria) {
            DTProducto dtProducto = producto.toDTProducto();
            dtProductos.push_back(dtProducto);
        }
    }
    return dtProductos;
}

// la validacion de que entre un idProducto valido la vamos a hacer desde el main segun lo que devuelve vector<DTProducto> ControlPromocion::verProductosVendedor()
// esto si seria responsabilidad del main, es un prerequisito para llamar a este metodo
void ControlPromocion::agregarProductoPromocion(int idProducto, int cantidad) {
    for (int i = 0; i < productos.size(); i++) {
        Producto producto = productos[i];
        if (producto.getId() == idProducto) {
            Requisitos requisito = Requisitos(cantidad, &producto);
            this->promocionEnMemoria->agregarRequisitos(requisito);
            return;
        }
    }
}

void ControlPromocion::confirmarPromocion() {
    if (promocionEnMemoria == nullptr) {
        return;
    }
    promociones.push_back(*promocionEnMemoria);

    // Como todos los productos de la promocion son del mismo vendedor, tomamos el primer requisito
    Vendedor* vendedor = promocionEnMemoria->getRequisitos()[0].getProducto()->getVendedor();

    string nombrePromo = promocionEnMemoria->getNombre();
    string nickVendedor = vendedor->getNickname();
    vector<int> codigosProductos;
    for (int i = 0; i < promocionEnMemoria->getRequisitos().size(); i++) {
        Requisitos requisito = promocionEnMemoria->getRequisitos()[i];
        codigosProductos.push_back(requisito.getProducto()->getId());
    }
    DTNotificacion notificacion(nombrePromo, nickVendedor, codigosProductos);

    vendedor->notificarObservers(notificacion);

    promocionEnMemoria = nullptr;
}

vector<DTInfoProducto> ControlPromocion::consultarProductosPromocion(string nombrePromocion) {
    vector<DTInfoProducto> dtInfoProductos;
    for (int i = 0; i < promociones.size(); i++) {
        if (promociones[i].getNombre() == nombrePromocion) {
            vector<Requisitos> requisitos = promociones[i].getRequisitos();
            for (int j = 0; j < requisitos.size(); j++) {
                Producto* producto = requisitos[j].getProducto();
                DTInfoProducto dtInfoProducto = producto->toDTInfoProducto();
                dtInfoProductos.push_back(dtInfoProducto);
            }
            break;
        }
    }
    return dtInfoProductos;
}

vector<DTPromocion> ControlPromocion::listarPromocionesVigentes() {
    vector<DTPromocion> dtPromociones;
    DTFecha fechaActual = controlFecha->getFechaActual();
    for (int i = 0; i < promociones.size(); i++) {
        if (promociones[i].getFechaVencimiento() >= fechaActual) {
            DTPromocion dtPromocion = promociones[i].toDTPromocion();
            dtPromociones.push_back(dtPromocion);
        }
    }
    return dtPromociones;
}

vector <DTInfoProducto> ControlPromocion::infoProductos(){

    


}

ControlPromocion::~ControlPromocion() {
}