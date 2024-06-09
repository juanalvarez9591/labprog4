#include "../include/Cliente.h"

    Cliente::Cliente(string nickname, string password, string calle, string ciudad, DTFecha* fecha, int numPuerta, vector<DTNotificacion> notificaciones) :
    Usuario(nickname,password,fecha, null){

        this->calle = calle;
        this->ciudad = ciudad;
        this->nroPuerta = numPuerta;
        this->notificaciones = notificaciones;
    }
    ~Cliente(){

    };

    string Cliente::getNombre(){
        return this->getNickname();
    };
    string Cliente::getPass(){
        return this->getPassword();
    };
    DTFecha* Cliente::getNacimiento(){
        return this->getFechaNacimiento();
    

    };
    string Cliente::getCalle(){
        return this->calle;
    };
    string Cliente::getCiudad(){
        return this->ciudad;
    };

    int Cliente::getNroPuerta(){
        return this->nroPuerta;
    };

    vector<DTNotificacion> Cliente::getNotificaciones()[
        return this->notificaciones;
    ];


    void Cliente::update(string nickVendedor, string nombrePromocion, vector<DTProducto> productos){

    };  

    void Cliente::clearNotificaciones(){

    };