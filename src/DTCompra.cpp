#include "DTCompra.h"
#include "DTFecha.h"

DTCompra::DTCompra() : nicknameCliente(""), fechaCompra(), id(0) {}

DTCompra::DTCompra(string nicknameCliente, DTFecha fechaCompra, int id)
        : nicknameCliente(nicknameCliente), fechaCompra(fechaCompra), id(id) {}

string DTCompra::getNicknameCliente() const {
    return this->nicknameCliente;
}

DTFecha DTCompra::getFechaCompra() const {
    return this->fechaCompra;
}

int DTCompra::getId() const {
    return this->id;
}