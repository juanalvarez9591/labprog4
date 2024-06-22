#include "ControlComentario.h"
#include "Comentario.h"
#include "Producto.h"
#include <vector>

//Funciones basicas controlador
ControlComentario* ControlComentario::instance = nullptr;

ControlComentario* ControlComentario::getInstance() {
    if (instance == nullptr) {
        instance = new ControlComentario();
    }
    return instance;
}

ControlComentario::ControlComentario() {
    ContrUsua = ControlUsuario::getInstance();
    ContrProm = ControlPromocion::getInstance();  
}

ControlComentario::~ControlComentario() {
    // no hay que hacer nada aca, cuando se llama a este destructor por default
    // se llama al destructor de vector, que llama a cada destructor de cliente y vendedor
}


//Borrar comentario

vector<string> ControlComentario::listarComentariosUsuario(string nombreUsuario) {
    vector<Comentario*> comentariosUsuario = this->ContrUsua->getUsuario(nombreUsuario)->getComentarios();
    vector<string> comentarios;
    for(auto iter = comentariosUsuario.begin(); iter != comentariosUsuario.end(); ++iter) {
        comentarios.push_back((*iter)->getTexto());
    }
    return comentarios;
}

Usuario* ControlComentario::getUsuarioComentario(string texto) {
    //ControlUsuario* ControlUsuario = ControlUsuario::getInstance();
    vector<string> nicks = this->ContrUsua->listarNicknamesUsuarios();
    Usuario* aEncontrar = NULL;
    auto iterNick = nicks.begin();
    while((iterNick != nicks.end()) && (aEncontrar == NULL)) {
        vector<Comentario*> comentarios = this->ContrUsua->getUsuario(*iterNick)->getComentarios();
        auto iterComent = comentarios.begin();
        while(iterComent != comentarios.end() && (aEncontrar == NULL)) {
            if ((*iterComent)->getTexto() == texto) {
                aEncontrar = this->ContrUsua->getUsuario(*iterNick);
            }
            ++iterComent;
        } 
        ++iterNick;
    }
    return aEncontrar;
}

void ControlComentario::eliminarComentario(string mensaje) {
    Comentario *aBorrar;
    Usuario* autor = getUsuarioComentario(mensaje); //Guardamos el que escribió el comentario
    bool borrado = false;
    vector<DTProducto> Productos = this->ContrProm->listarProductos();
    auto iterProd = Productos.begin();
        while(iterProd != Productos.end() && !borrado) {
            Comentario *iterComent = ContrProm->getProductoByID(iterProd->getId())->GetComentarios();
            if (iterComent->getTexto() == mensaje) {
                autor->olvidarComentario(ContrProm->getProductoByID(iterProd->getId())->GetComentarios());
                Comentario* Primero = ContrProm->getProductoByID(iterProd->getId())->GetComentarios();
                ContrProm->getProductoByID(iterProd->getId())->SetComentario(Primero->getSig());
                Primero->borrarRespuestas();

                borrado = true;
            }else if (iterComent->getSig()->getTexto() == mensaje){
                aBorrar = iterComent->getSig();
                iterComent->setSig(iterComent->getSig()->getSig());
                autor->olvidarComentario(aBorrar);
                aBorrar->borrarRespuestas();
                borrado = true;
            }else if (iterComent->getResp()->getTexto() == mensaje) {
                aBorrar = iterComent->getResp();
                iterComent->setRes(iterComent->getResp()->getSig());
                autor->olvidarComentario(aBorrar);
                aBorrar->borrarRespuestas();
                borrado = true;
            }else {
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
    //this->Comentador = nombreUsuario;
    this->UsuarioSeleccionado = this->ContrUsua->getUsuario(nombreUsuario);
}

vector<DTProducto> ControlComentario::listarProductos(){
                                                                /*vector<DTProducto> Articulos;
                                                                vector<DTProducto> Catalogo;
                                                                for (auto it = vendedores.begin(); it != vendedores.end(); it++) {
                                                                    Catalogo = it.listaProductos();
                                                                    Articulos.insert(Articulos.end() , Catalogo.begin() , Catalogo.end());
                                                                    Catalogo.clear();
                                                                }
                                                                Catalogo.erase();*/

    return this->ContrProm->listarProductos();
}

/*void ControlComentario::seleccionarProducto(string nombreProducto){
    this.Prod = nombreProducto;
}*/

void ControlComentario::seleccionarProducto(int IDProducto){
    this->ProdSeleccionado = this->ContrProm->getProductoByID(IDProducto);
}



//Comentario directo
 //Falta por hacer Una funcion en vendedor que nos de acceso a la direccion de un producto buscado segun la clave
void ControlComentario::realizarComentario(string texto, DTFecha fecha){
    Comentario* Opinion = new Comentario(texto, fecha);
    Comentario* aux = this->ProdSeleccionado->GetComentarios();   //AgregarComentario(Opinion)
    if (aux == nullptr){
        this->ProdSeleccionado->SetComentario(Opinion);
    }else{
        while(aux->getSig() != nullptr){
            aux = aux->getSig();
        }
        aux->setSig(Opinion);
    }
    this->UsuarioSeleccionado->addComentario(Opinion);
   
}

vector<string> ControlComentario::HacerListComentarios(Comentario* Comentario , vector<string> Vec){
    Vec.push_back(Comentario->getTexto());
    HacerListComentarios(Comentario->getResp() , Vec);
    HacerListComentarios(Comentario->getSig() , Vec);
    return Vec;
}
    

vector<string> ControlComentario::listarComentarios(){
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
    /*vector<DTProducto> Productos = this->ContrProm->listarProductos();
    for (auto iterProd = Productos.begin(); iterProd != Productos.end(); iterProd++){

        Respuesta = HacerListComentarios(this->ContrProm->getProductoByID(iterProd->getId()).GetComentarios() , Respuesta);
    
    }*/
    Respuesta = HacerListComentarios(this->ProdSeleccionado->GetComentarios() , Respuesta);
   
}

//Si guarda AResponder = NULL es que el comentario no existia
void ControlComentario::elegirComentario(string mensaje){
    /*Comentario* AResponder = NULL;
    vector<DTProducto> Productos = this->ContrProm->listarProductos();
    auto iterProd = Productos.begin();
    while((AResponder == NULL) && (iterProd != Productos.end())){
        AResponder = getProductoByID(iterProd->getId())->GetComentario(mensaje);
    }
    this->AResponder = AResponder;*/
        Comentario* AResponder = NULL;
    vector<DTProducto> Productos = this->ContrProm->listarProductos();
    auto iterProd = Productos.begin();
    while((AResponder == NULL) && (iterProd != Productos.end())){
        AResponder = this->ContrProm->getProductoByID(iterProd->getId())->GetComentarios()->ComentarioEnForo(mensaje);
    }
    this->AResponder = AResponder;
}

void ControlComentario::responderComentario(string respuesta, DTFecha fecha){
    Comentario* Opinion = new Comentario(respuesta, fecha);
    vector<string> nickUsuarios = this->ContrUsua->listarNicknamesUsuarios();
    auto iterUsuario = nickUsuarios.begin();
    while((iterUsuario != nickUsuarios.end() && (this->UsuarioSeleccionado != this->ContrUsua->getUsuario(*iterUsuario)))){
        ++iterUsuario;
    }
    this->ContrUsua->getUsuario(*iterUsuario)->addComentario(Opinion); //en teoria consigo un usuario con su nick y hago que guarde el comentario

    this->AResponder->AgregarRespuesta(Opinion);
}