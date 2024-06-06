#include "Comentario.h"
#include "DTComentario.h"
#include "DTFecha.h"

Comentario Comentario(std::string autor, std::string texto){
	this->autor = autor;
	this->texto = texto;
	this->date = getDTFechaNow();
	this->Sigcomenario = NULL;
	this->Respuesta = NULL;
}

//Libera la el DTfecha asociado, hay que hacer delete aparte
void Liberar(){
	LiberarFecha(this->date);
}

//Devuelve el puntero a la primera respuesta
Comentario* borrarRespuestas(){
	return this->Respuesta;
}

Comentario* getResp(){
	return this->Respuesta;
}

Comentario* getSig(){
	return this->Sigcomenario;
}


string obtenerTexto(){

	return this->texto;
}

DTComentario getDTComentario(){
	return DTComentario(this->autor , this->texto);
}