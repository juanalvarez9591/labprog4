
#include "Producto.h"
#include "Comentario.h"

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


void Restock(int envio){
	this->stock = this->stock + envio;
}



DTProducto GetDTProducto(){
	DTProducto salida = DTProducto(this->Nombre, this->Id);
	return salida;
}

Comentario* Producto::GetComentarios() {
	return this->Foro;
}

void Producto::SetComentario(Comentario* Nuevaraiz) {
	this->Foro = Nuevaraiz;
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
		if (It->getResp() == NULL){
			It->setRes(Comentario);
		}else{
			It = It.getResp();
			while(It.getSig != NULL){
				It = It.getSig;
			}
			It.setSig(Comentario);
		}
	}
}

void PrintComentariorec(Comentario *Comentario, int Sangria){
	for (int i = 0; i < Sangria; i++){
		cout << "> > ";
	}
	Comentario->PrintComentario();
}

void PrintTodosComentariosAux(Comentario *Comentario, int Sangria){
	PrintComentariorec(Comentario, Sangria);
	PrintTodosComentariosAux(Comentario->getResp(), Sangria+1 );
	PrintTodosComentariosAux(Comentario->getSig(), Sangria);
}

void PrintTodosComentarios(){
	if (this->Foro != NULL){
		PrintTodosComentariosAux(this->Foro, 1);
	}
}

~Producto(){
	if (Foro != NULL)
	{
		//Voy a ver como borrar un comentario primero
	}
}
