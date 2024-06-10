#ifndef REQUISITOS_H
#define REQUISITOS_H

class Requisitos {
public:
    Requisitos(int Minimo, Producto* Producto);

    //No tiene nada complejo, un delete funciona
    ~Requisitos();

    int GetMinimo();

    Producto* GetProducto();
	int getIdprod();

private:
    int Minimo;

    Producto *Producto;
};

#endif