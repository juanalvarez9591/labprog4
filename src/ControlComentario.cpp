#include "ControlComentario.h"
#include "Comentario.h"
#include "Producto.h"

//Borrar comentario

vector<string> ControlUsuario::listarComentariosUsuario(string nombreUsuario) {
    vector<string> comentarios;
    auto i = getUsuario(nombreUsuario)->getComentarios();
    for(auto j = i.begin(); j != i.end(); ++j) 
        comentarios.push_back(j->getMensaje());
    return comentarios;
}

void ControlUsuario::eliminarComentario(string mensaje) {
    auto usuarios = listarNicknamesUsuarios();
    for(auto i = usuarios.begin(); i != usuarios.end(); ++i) {
        auto msjComentarios = listarComentariosUsuario(getUsuario(*i));
        for(auto j = msjComentarios.begin(); j != msjComentarios.end(); ++j) {
            if (*j == mensaje) {
                j->borrarRespuestas();
            }
        }
    }
    usuarios.clear();
}

//Realizar comentario

void ControlUsuario::seleccionarUsuario(string nombreUsuario){
    this->Comentador = nombreUsuario;
}

vector<DTProducto> ControlUsuario::listarProductos(){
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

void ControlUsuario::seleccionarProducto(string nombreProducto){
    this->Prod = nombreProducto;
}