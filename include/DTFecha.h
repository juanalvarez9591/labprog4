#ifndef DTFECHA_H
#define DTFECHA_H

#include <string>
using namespace std;

class DTFecha
{
private:
    int dia, mes, anio;

public:
    DTFecha(); // Making it public if you intend to create instances without parameters
    DTFecha(int dia, int mes, int anio);
    string getString();
    bool operator>=(const DTFecha &F) const;
};

#endif // DTFECHA_H