#include "Requisitos.h"

Requisitos(int Minimo, Producto* Producto){
	this->Minimo = Minimo;
	this->Producto = Producto;
}

int GetMinimo(){
	return this->Minimo;
}

Producto* GetProducto(){
	return this->Producto;
}

int getIdprod(){
	return this->Producto->GetId();
}