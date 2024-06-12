#include "Comentario.h"
#include "DTComentario.h"
#include "DTFecha.h"

Comentario::Comentario(std::string texto){
	this->texto = texto;
	this->date = getDTFechaNow();
	this->Sigcomenario = NULL;
	this->Respuesta = NULL;
}

//Libera la el DTfecha asociado, hay que hacer delete aparte
void Comentario::Liberar(){
	LiberarFecha(this->date);
}

//Devuelve un set con las respuestas DIRECTAS del comentario
set<Comentario> Comentario::getRespuestas() {
	std::set<Comentario> respuestas; //capaz que tendría que ser un set de punteros a Comentario en vez de comentarios no se
	Comentario* i = this->Respuesta;
	while(i != NULL) {
		respuestas.insert(i);
		i = i->Sigcomenario;
	}
	return respuestas;
}

//Tiene que borrar TODAS las respuestas del comentario
void Comentario::borrarRespuestas(){
	auto respuestas = getRespuestas();
	for(auto i = respuestas.begin(); i!=respuestas.end(); ++i) {
		i->borrarRespuestas();
	}
	eliminarComentario(this->texto); //creo que está mal llamada
}

//Devuelve el puntero a la primera respuesta
Comentario* Comentario::getResp(){
	return this->Respuesta;
}

Comentario* Comentario::getSig(){
	return this->Sigcomenario;
}

void Comentario::setSig(Comentario* Sig){
	this->Sig = Sig;
}
void Comentario::setRes(Comentario* Res){
	this->Res = Res;
}

string Comentario::getTexto(){
	return this->texto;
}

DTComentario Comentario::getDTComentario(){
	return DTComentario(this->texto, this->fecha);
}