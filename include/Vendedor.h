#ifndef VENDEDOR_H
#define VENDEDOR_H

#include <string>
#include <vector>
#include "Usuario.h"
#include "IObserver.h"
#include "DTNotificacion.h"

using namespace std;

class Vendedor : public Usuario {
public:
    Vendedor(string nickname, string password, DTFecha fechaNacimiento, string rut);
    void agregarObserver(IObserver* observer);
    void eliminarObserver(IObserver* observer);
    void notificarObservers(DTNotificacion notificacion);
    bool estaSuscrito(IObserver* observer);
    string getRut();
private:
    string rut;
    vector<IObserver*> observers;
};

#endif