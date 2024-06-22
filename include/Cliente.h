#ifndef CLIENTE_H
#define CLIENTE_H

#include <string>
#include <vector>
#include "Usuario.h"
#include "DTNotificacion.h"
#include "IObserver.h"
using namespace std;

class Cliente: public Usuario, public IObserver {
public:
    Cliente(string nickname, string password, DTFecha fechaNacimiento,int nroPuerta, string calle, string ciudad);
    void update(DTNotificacion notificacion) override;
    string getNickname() const;
    DTFecha getFechaNacimiento() const;
    string getCalle() const;
    string getCiudad() const;
    int getNroPuerta() const;
    vector<DTNotificacion> listarNotificaciones();
    void limpiarNotificaciones();
private:
    string ciudad, calle;
    int nroPuerta;
    vector<DTNotificacion> notificaciones;
};
#endif