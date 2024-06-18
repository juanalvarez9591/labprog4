#include "../include/ControlCompra.h"

    ControlCompra* ControlCompra::instance = NULL;

    ControlCompra::ControlCompra(){
        compras = unordered_map<int, Compra>();
        clienteEnMemoria = "";
        dataProducto = vector<DTDetalleProducto>();
        productosEnMemoria = vector<Producto>() ;
        
    }
     ControlCompra* ControlCompra::getInstance(){
        if (instance == NULL){
            instance = new ControlCompra();
        }
        return instance;
    }


    void ControlCompra::seleccionarCliente(string nombreCliente){
        clienteEnMemoria = nombreCliente;


    } 
  
    void ControlCompra::agregarProducto(int codigo, int cantidad){
        dataProducto.push_back(DTDetalleProducto(codigo, cantidad));


    }
    vector <DTDetalleProducto> ControlCompra::getDataProducto(){
        return dataProducto;
    }
    void ControlCompra::borrarDataProducto(){
        dataProducto.clear();
    }

        
    void ControlCompra::ConfirmarCompra(DTFecha fecha, int precio){
        Compra nuevaCompra(fecha, precio);
        for (auto it = dataProducto.begin(); it != dataProducto.end(); ++it) {
             int cantidad = it->getCantProducto();
            bool enviado = false;
            Producto* producto = nullptr;
            Cantidad* nuevaCantidad = new Cantidad(cantidad, enviado, producto);
            nuevaCompra.agregarCantidad(nuevaCantidad);
        } 
        int clave = compras.size() + 1;

    // Agregar la nueva compra al map
        compras.emplace(clave, move(nuevaCompra));

    }
    




   // virtual ControlCompra::~IControlCompra(){}