#include "Producto.h"
#include <iostream>
#include "Comentario.h"

Producto::Producto() {
    this->nombre = "";
    this->descripcion = "";
    this->id = 0;
    this->stock = 0;
    this->precio = 0;
    this->categoria = Categoria::Otro;
    this->vendedor = nullptr;
    this->Foro = nullptr;   
}

Producto::Producto(string nombre, string descripcion, int id, int stock, int precio, Categoria categoria, Vendedor* vendedor) {
    this->nombre = nombre;
    this->descripcion = descripcion;
    this->id = id;
    this->stock = stock;
    this->precio = precio;
    this->categoria = categoria;
    this->vendedor = vendedor;
}

string Producto::getNombre() {
    
    return this->nombre;
}

string Producto::getDescripcion() {
    return this->descripcion;
}

Categoria Producto::getCategoria() {
    return this->categoria;
}

int Producto::getPrecio() {
    return this->precio;
}

int Producto::getId() {
    return this->id;
}

int Producto::getStock() {
    return this->stock;
}

Vendedor* Producto::getVendedor() const {
    return this->vendedor;
}

DTProducto Producto::toDTProducto() const {
    return DTProducto(this->nombre, this->id);
}
    
Comentario* Producto::GetComentarios() {
	return this->Foro;
}

void Producto::SetComentario(Comentario* Nuevaraiz) {
	this->Foro = Nuevaraiz;
}

DTInfoProducto Producto::toDTInfoProducto() const {
    return DTInfoProducto(this->nombre, this->precio, this->stock, this->descripcion, this->vendedor->getNickname(), this->categoria);
}
DTDatosProducto Producto::toDTDatosProducto() const{
    return DTDatosProducto(this->stock, this->nombre, this->precio, this->id);


}


Producto::~Producto() {

}
/*void PrintComentariorec(Comentario *Comentario, int Sangria){
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
}*/

