#include "Producto.h"

Producto(string Nombre, string Descripcion, int Id, int stock, int precio, CatProducto Categoria){
	this->Nombre = Nombre;
	this->Descripcion = Descripcion;
	this->Foro = NULL;
	this->Id = Id;
	this->stock = stock;
	this->precio = precio;
	this->Categoria = Categoria;
}

string GetNombre() {
	return this->Nombre;
}

string GetDescripcion(){
	return this->Descripcion;
}

CatProducto GetCategoria(){
	return this->Categoria;
}

int GetPrecio(){
	return this->precio;
}

int GetStock(){
	return this->stock;	
}

bool RestarAStock(int Vendidos){
	if (Vendidos <= this->stock)
	{
		this->stock = this->stock - Vendidos;
		return true;
	}else{
		return false;
	}
	
}

/*
void Restock(int envio){
	this->stock = this->stock + envio;
}
*/

DTProducto GetDTProducto(){
	//Volver a esto cuando haga DTProducto
}

Comentario GetComentario(string Text){
	//
}

void AgregarComentario(Comentario *Comenario){
	//
}

void AgregarRespuesta(Comentario *Comentario, string Text){
	//
}

~Producto(){
	if (Foro != NULL)
	{
		//Voy a ver como borrar un comentario primero
	}
}