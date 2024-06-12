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
    void update(string message) override;
    string getNickname() override;
    vector<DTNotificacion> listarNotificaciones();
    void limpiarNotificaciones();
private:
    string direccion;
    string ciudad;
    vector<DTNotificacion> notificaciones;
};
#endif