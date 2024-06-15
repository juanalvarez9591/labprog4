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
            it++;
        }else{
            foundprod = true;
        }
        if (it != NULL){                //Por si busqueda falla
            if (it->Foro == NULL){      //Si foro vacio
                it->Foro = Opinion;
            }else{
                it->AgregarComentario(Opinion);
                /*Comentario* iterComent = it->Foro;
                while(iterComent->getSig() != NULL){
                    iterComent = iterComent->getSig();
                }
                iterComent->setSig(Opinion);*/
            }
        }
    }           //Ya agregado a el foro del producto
                //agregando a coleccion del usuario
    vector<Usuario> Usuarios;
    vector<Vendedor> Vendedores = getVendedores();
    
    Usuarios.insert(Usuarios.end(), Vendedores.begin(), Vendedores.end());
    Usuarios.insert(Usuarios.end(), Vendedores.begin(), Vendedores.end());

    /*auto it = vendedores.begin();
    while((it != vendedores.end()) && !found){
        Producto* Product = it->getProducto(Prod); //FUNCION POR HACER, NO COPILAR!!!! DEVUELVE UN PUNTERO A EL PRODUCTO CON EL MISMO NOMBRE, DESDE VENDEDOR, si no hay devuelve NULL
        if (Product != NULL){
            found = true;
        }else{
            it = it +1;
        }
    }

    //fase de ensablaje
    if (Product != NULL){
        Product.AgregarComentario(Opinion);

        //FALTA AGREGAR A LA COLECCION INTERNA DEL VENDEDOR
    }*/
}