#include "ControlComentario.h"
#include "ControlUsuario.h"
#include "ControlPromocion.h"
#include "Comentario.h"
#include "Producto.h"
#include <vector>
#include <string>
//Borrar comentario

vector<Comentario*> ControlComentario::listarComentariosUsuario(string nombreUsuario) {
    vector<Comentario*> comentarios = getUsuario(nombreUsuario)->getComentarios();
    return comentarios;
}

//Borra el comentario y TODAS sus respuestas, NO HACE LA RECONEXION ARBORECENTE. ESO SE HACE ANTES DE LLAMAR LA FORMULA
void ControlComentario::borrarRespuestas(Comentario comentario) {
    auto respuestas = comentario.getRespuestas();
    for(auto i = respuestas.begin(); i!=respuestas.end(); ++i) {
        i->borrarRespuestas();
    }
    i->eliminarNodo(); //Falta por implementar
}

void ControlComentario::eliminarComentario(string mensaje) {
    auto nickUsuarios = listarNicknamesUsuarios();
    bool borrado = false;
    bool ComentEncontrado = false; 
    auto iterUsuario = nickUsuarios.begin();
    Comentario *aBorrar = NULL;
    while((iterUsuario != nickUsuarios.end()) && !(borrado && ComentEncontrado)) {
        auto comentarios = listarComentariosUsuario(*iterUsuario);
        auto iterComent = comentarios.begin();
        while(iterComent != comentarios.end() && !(borrado && ComentEncontrado)) {
            if (!borrado){
                if (iterComent->getSig()->getTexto() == mensaje) {
                aBorrar = iterComent->getSig();
                iterComent->setSig(aBorrar->getSig());
            }
            
                aBorrar->borrarRespuestas();
                getUsuario(*iterUsuario).olvidarComentario(*aBorrar);
                borrado = true;
            } else if (iterComent->getResp()->getTexto() == mensaje) {
                aBorrar = iterComent->getResp();
                iterComent->setRes(aBorrar->getSig());
                aBorrar->borrarRespuestas();
                getUsuario(*iterUsuario).olvidarComentario(*aBorrar);
                borrado = true;
            } else {
                ++iterComent
            }
        }
        if(!borrado) {
            ++iterUsuario;
        }
    }
    if (!borrado) {
        vector<DTProducto> productos = listarProductos();
        auto iterProd = productos.begin()
        while(iterProd != producto.end() && !borrado) {
            if (iterProd->GetPrimerComentario()->getTexto() == mensaje) {
                iterProd->BorrarPrimerComentario();
                getUsuario(*iterUsuario).olvidarComentario(*(iterProd->GetPrimerComentario()));
                borrado = true;
            } else {
                ++iterProd;
            }
        }
    }
    usuarios.clear();
}



//Realizar comentario

//Se listan los clientes desde control usuario

void ControlComentario::seleccionarUsuario(string nombreUsuario){
    this->Comentador = nombreUsuario;
}

vector<string> ControlComentario::listarProductos(){
    vector<string> listaprd;
    ControlPromocion* ContrProm = ControlPromocion::getInstance();
    vector<Producto> Productos = ContrProm->getColeccionProd();
    for (auto it = Productos.begin(); it != Productos.end(); it++){
        listaprd.push_back(it->GetNombre());
    }
    return listaprd;
}

void ControlComentario::seleccionarProducto(string nombreProducto){
    this->Prod = nombreProducto;
}


//Comentario directo
 //Falta por hacer Una funcion en vendedor que nos de acceso a la direccion de un producto buscado segun la clave
void ControlComentario::realizarComentario(string texto, DTFecha fecha){
    
    Comentario* Opinion = new Comentario(texto, fecha);

    //fase de busqueda
    bool foundprod = false;
    bool foundUsua = false;
    ControlUsuario* ContrUsua = ControlUsuario::getInstance();
    ControlPromocion* ContrProm = ControlPromocion::getInstance();

    vector<Producto> Productos = ContrProm->getColeccionProd();
    auto it = Productos.begin();
    while((!found) && (it != Productos.end())){
        if (it->GetNombre() != this->Prod->GetNombre()){
            ++it;
        }else{
            foundprod = true;
        }
        if (it != NULL){                //Por si busqueda falla
            if (it->Foro == NULL){      //Si foro vacio
                it->Foro = Opinion;
            }else{
                it->AgregarComentario(Opinion);
            }
        }
    }           //Ya agregado a el foro del producto
                //agregando a coleccion del usuario
    vector<string> nickUsuarios = ContrUsua->listarNicknamesUsuarios();
    string *Iternick = nickUsuarios.begin();
    while((iterUsuario != nickUsuarios.end() && (this->Comentador != *iterComent))){
        ++iterUsuario
    }
    ContrUsua->getUsuario(*iterUsuario)->addComentario(Opinion); //en teoria consigo un usuario con su nick y hago que guarde el comentario

}

vector<string> HacerListComentarios(Comentario* Comentario , vector<string> Vec){
    Vec.push_back(Comentario->texto);
    HacerListComentarios(Comentario->getResp() , Vec);
    HacerListComentarios(Comentario->getSig() , Vec);
    return Vec;
}
    

vector<string> ControlUsuario::listarComentarios(){
    vector<string> Respuesta;
    /*ControlUsuario* ContrUsua = ControlUsuario::getInstance();
    vector<string> nickUsuarios = ContrUsua->listarNicknamesUsuarios();
    for (string itnick = nickUsuarios.begin(); itnick != nickUsuarios.end(); itnick++) {
        vector<Comentario*> EstosCom = listarComentariosUsuario(itnick);
        for (Comentario* iterComent = EstosCom.begin(); iterComent != EstosCom.end(); iterComent++) {
            Respuesta.push_back(iterComent->getTexto());
        
        }
    }*/ //Funciona pero no se ingresan en orden ni se diferencian los niveles de respuestas

    //Version 2
    ControlPromocion* ContrProm = ControlPromocion::getInstance();
    vector<Producto> Productos = ContrProm->getColeccionProd();
    for (auto iterProd = Productos.begin(); itnick != Productos.end(); itnick++){

        Respuesta = HacerListComentarios(*iterProd.GetPrimerComentario() , Respuesta);
    }

   
}

//Si guarda AResponder = NULL es que el comentario no existia
void elegirComentario(string mensaje){
    //bool found = false;
    Comentario* AResponder = NULL;
    ControlPromocion* ContrProm = ControlPromocion::getInstance();
    vector<Producto> Productos = ContrProm->getColeccionProd();
    auto iterProd = Productos.begin();
    while((AResponder == NULL) && (iterProd != Productos.end())){
        AResponder = *iterProd.GetComentario(mensaje);
    }
    this->AResponder = AResponder;
    
}