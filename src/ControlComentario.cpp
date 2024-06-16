#include "ControlComentario.h"
#include "Comentario.h"
#include "Producto.h"
#include <vector>

//Borrar comentario

vector<Comentario*> ControlComentario::listarComentariosUsuario(string nombreUsuario) {
    vector<Comentario*> comentarios = getUsuario(nombreUsuario)->getComentarios();
    return comentarios;
}

Usuario* ControlComentario::getUsuarioComentario(string texto) {
    ControlUsuario* ControlUsuario = ControlUsuario::getInstance();
    vector<string> nicks = ControlUsuario->listarNicknamesUsuarios();
    Usuario* aEncontrar = NULL;
    string *iterNick = nicks.begin();
    while((iterNick != nicks.end()) && (aEncontrar == NULL)) {
        vector<Comentario> comentarios = ControlUsuario->getUsuario(*iterNick)->getComentarios();
        Comentario *iterComent = comentarios.begin();
        while(iterComent != comentarios.end() && (aEncontrar == NULL)) {
            if (iterComent->getTexto() == texto) {
                aEncontrar = ControlUsuario->getUsuario(*iterNick);
            }
            ++iterComent;
        } 
        ++iterNick;
    }
    return aEncontrar;
}

void ControlComentario::eliminarComentario(string mensaje) {
    ControlUsuario* CtrlUsuario = ControlUsuario::getInstance();
    ControlPromocion* CtrlPromo = ControlPromocion::getInstance();
    Comentario *aBorrar;
    Usuario* autor = CtrlUsuario->getUsuarioComentario(mensaje); //Guardamos el que escribió el comentario
    vector<Producto> productos = CtrlPromo->getColeccionProd();
    auto iterProd = productos.begin()
        while(iterProd != producto.end() && !borrado) {
            Comentario *iterComent = iterProd->GetPrimerComentario()
            if (iterComent->getTexto() == mensaje) {
                autor->olvidarComentario(*(iterProd->GetPrimerComentario()));
                iterProd->BorrarPrimerComentario();
                borrado = true;
            } else if (iterComent->getSig()->getTexto() == mensaje){
                aBorrar = iterComent->getSig();
                iterComent->setSig(iterComent->getSig()->getSig());
                autor->olvidarComentario(*aBorrar);
                aBorrar->borrarRespuestas();
                borrado = true;
            } else if (iterComent->getResp()->getTexto() == mensaje) {
                aBorrar = iterComent->getResp();
                iterComent->setRes(iterComent->getResp()->getSig());
                autor->olvidarComentario(*aBorrar);
                aBorrar->borrarRespuestas();
                borrado = true;
            } else {
                borrado = iterComent->getSig()->eliminarNodoPosterior(mensaje);
                if(!borrado) {
                    borrado = iterComent->getResp()->eliminarNodoPosterior(mensaje);
                }
            }
            ++iterProd;
        }
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