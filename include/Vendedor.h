#ifndef VENDEDOR_H
#define VENDEDOR_H

#include <string>
#include <vector>
#include "Usuario.h"
#include "IObserver.h"

using namespace std;

class Vendedor : public Usuario {
public:
    Vendedor(string nickname, string password, DTFecha fechaNacimiento, int rut);
    void agregarObserver(IObserver* observer);
    void eliminarObserver(IObserver* observer);
    void notificarObservers(std::string message);
    bool estaSuscrito(IObserver* observer);
    string getNickname();

private:
    int rut;
    vector<IObserver*> observers;
};

#endif