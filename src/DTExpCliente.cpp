# include "../include/DTExpCliente.h"

DTExpCliente::DTExpCliente(string nickname, DTFecha fecha, string calle, string ciudad, int nroPuerta, vector <DTExpCompra> compras) 
: DTDataCliente ( nickname,  fecha,  calle, ciudad, nroPuerta){
    this->compras = compras;

}
vector <DTExpCompra> DTExpCliente::getCompras(){
    return this-> compras;
}