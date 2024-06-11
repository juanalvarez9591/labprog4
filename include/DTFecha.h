#ifndef DTFECHA_H
#define DTFECHA_H

#include <string>
using namespace std;

class DTFecha
{
private:
    int dia, mes, anio;

public:
    DTFecha();
    DTFecha(int dia, int mes, int anio);
    string getString();
    bool operator>=(const DTFecha &F) const;
    int getDia() const;
    int getMes() const;
    int getAnio() const;
};

#endif // DTFECHA_H