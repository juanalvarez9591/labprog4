#ifndef DTNOTIFICACION_H
#define DTNOTIFICACION_H

#include <string>
#include <vector>
using namespace std;

class DTNotificacion
{
private:
    string nombrePromo;
    string nickVendedor;
    vector<int> codigosProductos;

public:
    DTNotificacion();
    DTNotificacion(string nombrePromo, string nickVendedor, vector<int> codigosProductos);
    string toString() const;
};

#endif // DTNOTIFICACION_H