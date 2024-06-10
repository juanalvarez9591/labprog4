#include "Comentario.h"
#include "DTComentario.h"
#include "DTFecha.h"

Comentario Comentario(std::string texto){
	this->texto = texto;
	this->date = getDTFechaNow();
	this->Sigcomenario = NULL;
	this->Respuesta = NULL;
}

//Libera la el DTfecha asociado, hay que hacer delete aparte
void Liberar(){
	LiberarFecha(this->date);
}

//Devuelve un set con las respuestas DIRECTAS del comentario
set<Comentario> getRespuestas() {
	std::set<Comentario> respuestas;
	Comentario* i = this->Respuesta;
	while(i != NULL) {
		respuestas.insert(i);
		i = i->Sigcomenario;
	}
	return respuestas;
}

//Tiene que borrar TODAS las respuestas del comentario
void borrarRespuestas(){
	auto respuestas = getRespuestas();
	while (!(respuestas.empty())) {
		Comentario* j = respuestas.begin();
		respuestas.remove(j);
		j->borrarRespuestas();
	}
	eliminarComentario(this->texto);
}

//Devuelve el puntero a la primera respuesta
Comentario* getResp(){
	return this->Respuesta;
}

Comentario* getSig(){
	return this->Sigcomenario;
}

void setSig(Comentario* Sig){
	this->Sig = Sig;
}
void setRes(Comentario* Res){
	this->Res = Res;
}

string obtenerTexto(){
	return this->texto;
}

DTComentario getDTComentario(){
	return DTComentario(this->autor , this->texto);
}