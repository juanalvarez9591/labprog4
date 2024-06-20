#include "../include/ControlCompra.h"


    ControlCompra* ControlCompra::instance = NULL;

    ControlCompra::ControlCompra(){
        compras = unordered_map<int, Compra>();
        clienteEnMemoria = NULL;
        //dataProducto = vector<DTDetalleProducto>();
        controlUsuario = ControlUsuario::getInstance();
        controlFecha = ControlFecha::getInstance();
        compraEnProceso = NULL;

        
    }
    ControlCompra* ControlCompra::getInstance(){
        if (instance == NULL){
            instance = new ControlCompra();
        }
        return instance;    
    }


    void ControlCompra::seleccionarCliente(string nombreCliente){//acá creo la instancia de compra.
        clienteEnMemoria= controlUsuario->getCliente(nombreCliente);
        compraEnProceso = new Compra(controlFecha->getFechaActual(), clienteEnMemoria);
    } 
  
    void ControlCompra::agregarCantidad(int codigo, int cantidad){
    
       // Producto* productoElegido = controlPromocion->getProductoByID(codigo);
       Producto * productoElegido = ControlPromocion::getInstance()->getProductoByID(codigo);
        Cantidad* aux = new Cantidad(cantidad, NULL);
        compraEnProceso->agregarCantidad(aux);


    }


    void ControlCompra::olvidarCompra(){
        compraEnProceso = NULL;
        clienteEnMemoria = NULL;

    }
    
    vector <DTDatosProducto> ControlCompra::mostrarDatosProducto(){
        return ControlPromocion::getInstance()->dataProductos();
        //return controlPromocion->dataProductos();

    }

    vector<string> ControlCompra::listarClientes(){

        return controlUsuario->listarNicknamesClientes();

    }
    float ControlCompra::calcularPrecioCompra(vector<DTDetalleProducto> parCompra){
       // return ControlPromocion::getInstance()->calcularPrecioTotal(parCompra);
        return controlPromocion->calcularPrecioTotal(parCompra);
    }


    bool ControlCompra::confirmarCompra(){

        int clave = compras.size() + 1;
    // Agregar la nueva compra al map
        compras.emplace(clave, *compraEnProceso);
        clienteEnMemoria = NULL;
        compraEnProceso = NULL;
         if (compras.find(clave) != compras.end()) {
            return true;
    }else {
        return false;
    }


    }


   // virtual ControlCompra::~IControlCompra(){}