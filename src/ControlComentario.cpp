#include "ControlComentario.h"
#include "Comentario.h"
#include "Producto.h"
#include <vector>

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
    
    
    eliminarNodo(); //Falta por implementar
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

void ControlComentario::seleccionarUsuario(string nombreUsuario){
    this->Comentador = nombreUsuario;
}

vector<DTProducto> ControlComentario::listarProductos(){
    vector<DTProducto> Articulos;
    vector<DTProducto> Catalogo;
    for (auto it = vendedores.begin(); it != vendedores.end(); it++) {
        Catalogo = it.listaProductos();
        Articulos.insert(Articulos.end() , Catalogo.begin() , Catalogo.end());
        Catalogo.clear();
    }
    Catalogo.erase();

    return Articulos;
}

void ControlComentario::seleccionarProducto(string nombreProducto){
    this->Prod = nombreProducto;
}