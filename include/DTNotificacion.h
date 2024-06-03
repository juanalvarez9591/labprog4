#ifndef DTNOTIFICACION_H
#define DTNOTIFICACION_H

#include <string>
using namespace std;

class DTNotificacion
{
private:
    string asunto;
    string texto;

public:
    DTNotificacion();
    DTNotificacion(string asunto, string texto);
};

#endif // DTNOTIFICACION_H