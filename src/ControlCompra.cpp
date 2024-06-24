#include "ControlCompra.h"
#include "ControlPromocion.h"
#include "ControlUsuario.h"
#include "ControlFecha.h"
#include "DTExpCliente.h"
#include "Compra.h"


ControlCompra* ControlCompra::instance = nullptr;

ControlCompra::ControlCompra() {
    controlUsuario = ControlUsuario::getInstance();
    controlFecha = ControlFecha::getInstance();
    controlPromocion = ControlPromocion::getInstance();

    compras = unordered_map<int, Compra*>();
    clienteEnMemoria = nullptr;
    compraEnProceso = nullptr;

    vendedorEnMemoria = nullptr;
    productoEnMemoria = nullptr;
    comprasEnMemoria = vector<int>();
}

ControlCompra* ControlCompra::getInstance() {
    if (instance == nullptr) {
        instance = new ControlCompra();
    }
    return instance;
}

void ControlCompra::seleccionarCliente(string nickCliente) {
    clienteEnMemoria = controlUsuario->getCliente(nickCliente);
    compraEnProceso = new Compra(controlFecha->getFechaActual(), clienteEnMemoria);
}

bool ControlCompra::agregarCantidad(int codigo, int cantidad) {
    if (compraEnProceso == nullptr) {
        return false;
    }

    Producto* productoElegido = controlPromocion->getProductoByID(codigo);
    if (productoElegido == nullptr) {
        return false;
    }

    if (cantidad <= 0 || cantidad > productoElegido->getStock()) {
        return false;
    }

    vector<Cantidad*>& cantidades = compraEnProceso->getCantidades();
    for (vector<Cantidad*>::iterator it = cantidades.begin(); it != cantidades.end(); ++it) {
        if ((*it)->getProducto() == productoElegido) {
            int newCantidad = (*it)->getCantidad() + cantidad;
            if (newCantidad <= productoElegido->getStock()) {
                (*it)->setCantidad(newCantidad);
                return true;
            } else {
                return false;
            }
        }
    }

    Cantidad* aux = new Cantidad(cantidad, productoElegido);
    compraEnProceso->agregarCantidad(aux);
    return true;
}

void ControlCompra::olvidarCompra() {
    if (compraEnProceso != nullptr) {
        delete compraEnProceso;
        compraEnProceso = nullptr;
    }
    clienteEnMemoria = nullptr;
}

bool ControlCompra::confirmarCompra() {
    if (compraEnProceso == nullptr) {
        return false;
    }
    int clave = compras.size() + 1;
    vector<Cantidad*>& cantidades = compraEnProceso->getCantidades();
    vector<Requisitos> requisitosCompra;

    for (vector<Cantidad*>::iterator it = cantidades.begin(); it != cantidades.end(); ++it) {
        Producto* producto = (*it)->getProducto();
        int cantidadComprada = (*it)->getCantidad();
        requisitosCompra.push_back(Requisitos(cantidadComprada, producto));
        producto->actualizarStock(cantidadComprada);
    }

    float costoTotal = controlPromocion->calcularPrecioTotal(requisitosCompra);

    compraEnProceso->setCosto(costoTotal);

    compras[clave] = compraEnProceso;
    clienteEnMemoria = nullptr;
    compraEnProceso = nullptr;
    return true;
}

DTDetallesCompra ControlCompra::verDetallesCompra() {
    if (compraEnProceso == nullptr) {
        return DTDetallesCompra();
    }

    vector<DTProducto> productosCompra;
    vector<Cantidad*>& cantidades = compraEnProceso->getCantidades();
    vector<Requisitos> requisitosCompra;

    for (vector<Cantidad*>::iterator it = cantidades.begin(); it != cantidades.end(); ++it) {
        Producto* producto = (*it)->getProducto();
        int cantidad = (*it)->getCantidad();
        requisitosCompra.push_back(Requisitos(cantidad, producto));
        productosCompra.push_back(producto->toDTProducto());
    }

    float costoTotal = controlPromocion->calcularPrecioTotal(requisitosCompra);

    DTFecha fechaCompra = compraEnProceso->getFechaCompra();

    return DTDetallesCompra(costoTotal, fechaCompra, productosCompra);
}

DTExpCliente ControlCompra::verComprasCliente(string nickCliente) {
    Cliente* cliente = controlUsuario->getCliente(nickCliente);
    if (cliente == nullptr) {
        return DTExpCliente();
    }

    vector<DTExpCompra> comprasCliente;

    for (unordered_map<int, Compra*>::iterator it = compras.begin(); it != compras.end(); ++it) {
        Compra* compra = it->second;
        if (compra->getCliente() == cliente) {
            comprasCliente.push_back(compra->toDTExpCompra());
        }
    }

    return DTExpCliente(
            cliente->getNickname(),
            cliente->getFechaNacimiento(),
            cliente->getNroPuerta(),
            cliente->getCalle(),
            cliente->getCiudad(),
            comprasCliente);
}

bool ControlCompra::elegirVendedor(string nickVendedor) {
    Vendedor* vendedor = controlUsuario->getVendedor(nickVendedor);
    if (vendedor != nullptr) {
        vendedorEnMemoria = vendedor;
        return true;
    }
    return false;
}

vector<DTProducto> ControlCompra::listarProductosAptosDelVendedor() {
    vector<DTProducto> productosConEnvioPendiente;

    if (vendedorEnMemoria == nullptr) {
        return productosConEnvioPendiente;
    }

    vector<DTProducto> productosVendedor = controlPromocion->verProductosVendedor(vendedorEnMemoria->getNickname());

    for (vector<DTProducto>::iterator it = productosVendedor.begin(); it != productosVendedor.end(); ++it) {
        Producto* producto = controlPromocion->getProductoByID(it->getId());
        bool tieneEnvioPendiente = false;

        for (unordered_map<int, Compra*>::iterator compraIt = compras.begin(); compraIt != compras.end(); ++compraIt) {
            Compra* compra = compraIt->second;
            vector<Cantidad*>& cantidades = compra->getCantidades();
            for (vector<Cantidad*>::iterator cantidadIt = cantidades.begin(); cantidadIt != cantidades.end(); ++cantidadIt) {
                if ((*cantidadIt)->getProducto() == producto && !(*cantidadIt)->getEnviado()) {
                    tieneEnvioPendiente = true;
                    break;
                }
            }
            if (tieneEnvioPendiente) break;
        }

        if (tieneEnvioPendiente) {
            productosConEnvioPendiente.push_back(DTProducto(it->getNombre(), it->getId()));
        }
    }

    return productosConEnvioPendiente;
}

bool ControlCompra::elegirProducto(int id) {
    productoEnMemoria = controlPromocion->getProductoByID(id);
    return productoEnMemoria != nullptr;
}

vector<DTCompra> ControlCompra::listarComprasCliente() {
    vector<DTCompra> comprasCliente;
    comprasEnMemoria.clear();
    int id = 1;

    for (unordered_map<int, Compra*>::iterator it = compras.begin(); it != compras.end(); ++it) {
        Compra* compra = it->second;
        vector<Cantidad*>& cantidades = compra->getCantidades();

        for (vector<Cantidad*>::iterator cantIt = cantidades.begin(); cantIt != cantidades.end(); ++cantIt) {
            if ((*cantIt)->getProducto() == productoEnMemoria && !(*cantIt)->getEnviado()) {
                DTFecha fechaCompra = compra->getFechaCompra();
                string nicknameCliente = compra->getCliente()->getNickname();
                DTCompra dtCompra(nicknameCliente, fechaCompra, id);
                comprasCliente.push_back(dtCompra);
                comprasEnMemoria.push_back(it->first);
                id++;
                break;
            }
        }
    }

    return comprasCliente;
}

bool ControlCompra::marcarComoEnviado(int codigo) {
    if (codigo > 0 && codigo <= comprasEnMemoria.size()) {
        int compraId = comprasEnMemoria[codigo - 1];
        Compra* compra = compras[compraId];
        vector<Cantidad*>& cantidades = compra->getCantidades();

        for (vector<Cantidad*>::iterator it = cantidades.begin(); it != cantidades.end(); ++it) {
            if ((*it)->getProducto() == productoEnMemoria) {
                (*it)->setEnviado(true);
                return true;
            }
        }
    }
    return false;
}

ControlCompra::~ControlCompra() {
    for (auto& pair : compras) {
        delete pair.second;
    }
    delete compraEnProceso;
}