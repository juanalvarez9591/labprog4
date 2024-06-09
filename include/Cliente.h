#ifndef CLIENTE_H
#define CLIENTE_H

#include <string>
#include <vector>
#include "DTNotificacion.h"
#include "Usuario.h"
#include "IObserver.h"
#include "DTFecha.h"
#include "DTProducto.h"
using namespace std;

class Cliente: public Usuario, public IObserver {
private:
    string nickname;
    string password;
    DTFecha* fechaNacimiento;
    string calle;
    string ciudad;
    int nroPuerta;
    vector<DTNotificacion> notificaciones;

public:
    Cliente(string nickname, string password, string calle, string ciudad, DTFecha* fecha, int numPuerta, vector<DTNotificacion> notificaciones);
    ~Cliente();
    string getNombre();
    string getPassword();
    DTFecha* getFechaNacimiento();
    string getCalle();
    string getCiudad();
    int getNroPuerta();
    vector<DTNotificacion> getNotificaciones();
    void update(string nickVendedor, string nombrePromocion, vector<DTProducto> productos);  
    void clearNotificaciones();


};

#endif