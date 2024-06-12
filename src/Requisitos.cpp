#include "Requisitos.h"

Requisitos::Requisitos(int Minimo, Producto* Producto){
	this->Minimo = Minimo;
	this->Producto = Producto;
}

int Requisitos::GetMinimo(){
	return this->Minimo;
}

Producto* Requisitos::GetProducto(){
	return this->Producto;
}

int Requisitos::getIdprod(){
	return this->Producto->GetId();
}