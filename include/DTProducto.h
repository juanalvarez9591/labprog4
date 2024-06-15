#ifndef DTPRODUCTO_H
#define DTPRODUCTO_H

#include <string>

using namespace std;

class DTProducto{

private:
    string Nombre;
    int Id;

public:
    DTProducto();
    DTProducto(string Nombre, int Id);
    string getNombre();
    int getId();
};

#endif