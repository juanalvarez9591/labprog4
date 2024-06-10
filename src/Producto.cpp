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

int GetId(){
	return this->Id;	
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
	DTProducto salida = DTProducto(this->Nombre, this->Id);
	return salida;
}

Comentario *Estecomentario(Comentario *It, string Text){
	if (It == NULL){
		return NULL;
	}else{
		if (It.obtenerTexto() == Text){
			return It;

		}else{
			Comentario *Catalejo = Estecomentario(this.getSig(), Text);
			if (Catalejo != NULL){
				return Catalejo;

			}else{
				Catalejo = Estecomentario(this.getResp(), Text);
				return Catalejo;
		}
		}
	}
}

//Retorna un puntero al comentario, o en caso de no estar devuelve NULL
Comentario *GetComentario(string Text){
	Comentario* It = this->Foro;
	if (this->Foro != NULL){
		return Estecomentario(It, Text)
	}else{
		return NULL;
	}
}


void AgregarComentario(Comentario *Comentario){
	if (this->Foro == NULL){
		this->Foro = Comentario;
	}else{
		Comentario* Catalejo = this->Foro;
		while(Catalejo.getSig() != NULL){
			Catalejo = Catalejo.getSig();
		}
		Catalejo.setSig(Comentario);
	}
}

void AgregarRespuesta(Comentario *Comentario, string Text){
	Comentario* It = Estecomentario(this->Foro , Text);
	if (It != NULL){
		if (It.getResp() == NULL){
			It.setRes(Comentario);
		}else{
			It = It.getResp();
			while(It.getSig != NULL){
				It = It.getSig;
			}
			It.setSig(Comentario);
		}
	}
}

~Producto(){
	if (Foro != NULL)
	{
		//Voy a ver como borrar un comentario primero
	}
}