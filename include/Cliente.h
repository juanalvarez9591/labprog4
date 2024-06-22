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
    Cliente(string nickname, string password, DTFecha fechaNacimiento, string direccion, string ciudad);
    void update(DTNotificacion notificacion) override;
    vector<DTNotificacion> listarNotificaciones();
    string getNickname() const;
    string getDireccion() const;
    string getCiudad() const;
    void limpiarNotificaciones();
private:
    string direccion;
    string ciudad;
    vector<DTNotificacion> notificaciones;
};
#endif