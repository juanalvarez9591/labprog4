
#include "../include/DTDataCliente.h"


DTDataCliente::DTDataCliente(string nickname, DTFecha fecha, string calle, string ciudad, int nroPuerta) : DTInfoUsuarios(nickname, fecha){
    this-> calle = calle;
    this-> ciudad = ciudad;
    this-> nroPuerta = nroPuerta;

}
string DTDataCliente::getCalle(){
    return this->calle;

}

string DTDataCliente::getCiudad(){
    return this->ciudad;
}
int DTDataCliente::getNroPuerta(){
    return this->nroPuerta;
}