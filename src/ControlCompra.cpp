#include "../include/ControlCompra.h"

    ControlCompra* ControlCompra::instance = NULL;

    ControlCompra::ControlCompra(){
        compras = unordered_map<int, Compra>();
        clienteEnMemoria = NULL;
        //dataProducto = vector<DTDetalleProducto>();
        fechaSistema = DTFecha();
        compraEnProceso = NULL;
        
    }
    ControlCompra* ControlCompra::getInstance(){
        if (instance == NULL){
            instance = new ControlCompra();
        }
        return instance;    
    }


    void ControlCompra::seleccionarCliente(string nombreCliente){//acá creo la instancia de compra.
        clienteEnMemoria= ControlUsuario::getInstance()->getCliente(nombreCliente);
        compraEnProceso = new Compra(fechaSistema, clienteEnMemoria);
    } 
  
    void ControlCompra::agregarCantidad(int codigo, int cantidad){
        bool porlasDudas = false;
        Producto* productoElegido = ControlPromocion::getInstance()->getProductoByID(codigo);
        Cantidad* aux = new Cantidad(cantidad, porlasDudas, productoElegido);
        compraEnProceso->agregarCantidad(aux);


    }

  /*  vector <DTDetalleProducto> ControlCompra::getDataProducto(){
        return dataProducto;
    }*/

    void ControlCompra::olvidarCompra(){
        compraEnProceso = NULL;
        clienteEnMemoria = NULL;

    }
    
    vector <DTDatosProducto> ControlCompra::mostrarDatosProducto(){

        return ControlPromocion::getInstance()->dataProductos();

    }

    vector<string> ControlCompra::listarClientes(){

        return ControlUsuario::getInstance()->listarNicknamesClientes();

    }

    void ControlCompra::obtenerFechaSistema(){
        fechaSistema= ControlFecha::getInstance()->getFechaActual();



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