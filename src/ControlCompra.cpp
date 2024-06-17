#include "../include/ControlCompra.h"

    ControlCompra* ControlCompra::instance = NULL;

    ControlCompra::ControlCompra(){
        compras = vector<Compra>();
        

    }
     ControlCompra* ControlCompra::getInstance(){
        if (instance == NULL){
            instance = new ControlCompra();
        }
        return instance;
    }
   /* vector<string> ControlCompra::listarClientes(){




    }*/

    void ControlCompra::seleccionarCliente(string nombreCliente){
        clienteEnMemoria = nombreCliente;


    } 
    vector <DTInfoProducto> ControlCompra::mostrarDatosProducto() {



    }
    void ControlCompra::agregarProducto(int, int){


    } 
    DTDetallesCompra ControlCompra::DetallesCompra(){


    } 
    void ControlCompra::ConfirmarCompra(){


    } 
   // virtual ControlCompra::~IControlCompra(){}