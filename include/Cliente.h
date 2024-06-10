#ifndef CLIENTE_H
#define CLIENTE_H

#include <string>
#include <vector>
#include "Usuario.h"
#include "DTNotificacion.h"
#include "IObserver.h"
using namespace std;

class Cliente: public Usuario {
public:
    Cliente(string nickname, string password, DTFecha fechaNacimiento, string direccion, string ciudad);
    void agregarObserver(IObserver* observer);
    void eliminarObserver(IObserver* observer);
    void notificarObservers(std::string message);

private:
    string direccion;
    string ciudad;
    vector<DTNotificacion> notificaciones;
};
#endif
