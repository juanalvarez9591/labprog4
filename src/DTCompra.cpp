#include "DTCompra.h"
#include "DTFecha.h"

DTCompra::DTCompra(){
    this->nicknameCliente = "";
    this->fechaCompra = DTFecha();

}

DTCompra::DTCompra(string nicknameCliente, DTFecha fechaCompra){
    this->nicknameCliente = nicknameCliente;
    this->fechaCompra = fechaCompra;
}

string DTCompra::getNicknameCliente(){
    return this->nicknameCliente;
}

DTFecha DTCompra::getFechaCompra(){
    return this->fechaCompra;
}