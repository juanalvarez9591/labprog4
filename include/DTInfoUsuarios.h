#ifndef DTINFO_USUARIOS_H
#define DTINFO_USUARIOS_H

#include <string>
#include "DTFecha.h"
using namespace std;

class DTInfoUsuarios
{
private:
    string nickname;
    DTFecha fecha;

public:
    DTInfoUsuarios();
    DTInfoUsuarios(string nickname, DTFecha fecha);    
    string getNickname();
    DTFecha getFecha();
};

#endif 