
#include "Comentario.h"
#include "DTComentario.h"
#include "DTFecha.h"

using namespace std;

Comentario::Comentario(string texto, DTFecha fecha){
	this->texto = texto;
	this->fecha = fecha;
	this->Sigcomentario = NULL;
	this->Respuesta = NULL;
}

/* //Libera el DTfecha asociado, hay que hacer delete aparte
void Comentario::Liberar(){
	//LiberarFecha(this->fecha);
	delete this->fecha;
}*/

//Devuelve un set con las respuestas DIRECTAS del comentario
set<Comentario*> Comentario::getRespuestas() {
	set<Comentario*> respuestas;
	Comentario* i = this->Respuesta;
	while(i != NULL) {
		respuestas.insert(i);
		i = i->Sigcomentario;
	}
	return respuestas;
}

void Comentario::eliminarNodo() {
	delete this;
}

//Borra el comentario y TODAS sus respuestas, NO HACE LA RECONEXION ARBORECENTE. ESO SE HACE ANTES DE LLAMAR LA FORMULA
void Comentario::borrarRespuestas() {
    auto respuestas = this->getRespuestas();
    for(auto i = respuestas.begin(); i!=respuestas.end(); ++i) {
        (*i)->borrarRespuestas();
    }
    this->eliminarNodo();
}

//Busca recursivamente un mensaje y lo borra
//PRE: el mensaje buscado NO es el actual
bool Comentario::eliminarNodoPosterior(string mensaje) {
		Comentario *aBorrar;
		bool borrado;
		if ((this->Sigcomentario != NULL) && (this->Sigcomentario->texto == mensaje)) {
			aBorrar = this->Sigcomentario;
			this->Sigcomentario = this->Sigcomentario->Sigcomentario;
			aBorrar->borrarRespuestas();
			borrado = true;
		} else if ((this->Respuesta != NULL) && (this->Respuesta->texto == mensaje)) {
			aBorrar = this->Respuesta;
			this->Respuesta = this->Respuesta->Sigcomentario;
			aBorrar->borrarRespuestas();
			borrado = true;
		} else {
			borrado = this->Sigcomentario->eliminarNodoPosterior(mensaje);
			if(!borrado) {
				borrado = this->Respuesta->eliminarNodoPosterior(mensaje);
			}
		}
		return borrado;
}

void Comentario::AgregarRespuesta(Comentario *respuesta) {
	if (this->Respuesta == NULL) {
		this->Respuesta = respuesta;
	} else {
		Comentario *iterComent = this->Respuesta;
		while (iterComent->Sigcomentario != NULL) {
			iterComent = iterComent->Sigcomentario;
		}
		iterComent->Sigcomentario = respuesta;
	}
}

//Devuelve el puntero a la primera respuesta
Comentario* Comentario::getResp(){
	return this->Respuesta;
}

Comentario* Comentario::getSig(){
	return this->Sigcomentario;
}

void Comentario::setSig(Comentario* Sig){
	this->Sigcomentario = Sig;
}
void Comentario::setRes(Comentario* Res){
	this->Respuesta = Res;
}

string Comentario::getTexto(){
	return this->texto;
}

DTComentario Comentario::getDTComentario(){
	return DTComentario(this->texto, this->fecha);
}

bool Comentario::UltimoDelNivel(){
	return (this->Sigcomentario == NULL);
}

/*void Comentario::PrintComentario(){
	cout << this->texto << endl;
}*/

Comentario* Comentario::ComentarioEnForo(Comentario *It, string Text){
    if (It == NULL){
        return NULL;
    }else{
        if (It->texto == Text){
            return It;

        }else{
            Comentario *Catalejo = ComentarioEnForo(It->Sigcomentario, Text);
            if (Catalejo != NULL){
                return Catalejo;

            }else{
                Catalejo = ComentarioEnForo(It->Respuesta, Text);
                return Catalejo;
        }
        }
    }
}