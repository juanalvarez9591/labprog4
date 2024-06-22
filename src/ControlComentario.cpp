#include "ControlComentario.h"
#include "Comentario.h"
#include "Producto.h"
#include <vector>
#include <iostream> //para debugeo

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
    vector<string> nicks = this->ContrUsua->listarNicknamesUsuarios();
    Usuario* aEncontrar = nullptr;
    auto iterNick = nicks.begin();
    while((iterNick != nicks.end()) && (aEncontrar == nullptr)) {
        vector<Comentario*> comentarios = this->ContrUsua->getUsuario(*iterNick)->getComentarios();
        auto iterComent = comentarios.begin();
        while(iterComent != comentarios.end() && (aEncontrar == nullptr)) {
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
    if (autor != nullptr){
        cout << "encontre: " << autor->getNickname() << endl;
    }
    
    bool borrado = false;
    vector<DTProducto> Productos = this->ContrProm->listarProductos();
    auto iterProd = Productos.begin();
        while(iterProd != Productos.end() && !borrado) {
            cout << "Revisando: " << iterProd->getNombre() << endl;
            Comentario *iterComent = ContrProm->getProductoByID(iterProd->getId())->GetComentarios();
            if (iterComent == nullptr){
                //return true   //posible transformacion de la funcion a bool
            }else if (iterComent->getTexto() == mensaje) {
                aBorrar = ContrProm->getProductoByID(iterProd->getId())->GetComentarios();
                autor->olvidarComentario(aBorrar);
                ContrProm->getProductoByID(iterProd->getId())->SetComentario(aBorrar->getSig());
                aBorrar->borrarRespuestas();

                borrado = true;
            }else if ((iterComent->getSig() != nullptr) && (iterComent->getSig()->getTexto() == mensaje)){
                aBorrar = iterComent->getSig();
                iterComent->setSig(iterComent->getSig()->getSig());
                autor->olvidarComentario(aBorrar);
                aBorrar->borrarRespuestas();
                borrado = true;
            }else if ((iterComent->getResp() != nullptr) && (iterComent->getResp()->getTexto() == mensaje)) {
                aBorrar = iterComent->getResp();
                iterComent->setRes(iterComent->getResp()->getSig());
                autor->olvidarComentario(aBorrar);
                aBorrar->borrarRespuestas();
                borrado = true;
            }else {
                if (iterComent->getSig() != nullptr){
                    borrado = iterComent->getSig()->eliminarNodoPosterior(mensaje);
                }
                
                if((!borrado) && (iterComent->getResp() != nullptr)) {
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
    if ((this->ProdSeleccionado != nullptr) && (this->UsuarioSeleccionado != nullptr)){
        Comentario* Opinion = new Comentario(texto, fecha);
        Comentario* aux = this->ProdSeleccionado->GetComentarios();   //AgregarComentario(Opinion)
        if (aux == nullptr){
            //cout << "aux apunta a null?: " << aux << endl;
            this->ProdSeleccionado->SetComentario(Opinion);
        }else{
            //cout << "aux apunta a: " << aux << endl;
            while(aux->getSig() != nullptr){
                aux = aux->getSig();
            }
            aux->setSig(Opinion);
        }
        this->UsuarioSeleccionado->addComentario(Opinion);
    }
    
   
}

vector<string> ControlComentario::HacerListComentarios(Comentario* Comentario , vector<string> Vec){
    if (Comentario != nullptr){
        
    Vec.push_back(Comentario->getTexto());
    Vec = HacerListComentarios(Comentario->getResp() , Vec);
                /*if (Comentario->getResp() != nullptr){
                    cout << "El Primer hijo de: " << Comentario->getTexto() << " es: " << Comentario->getResp()->getTexto() << endl;
                }*/
        
    Vec = HacerListComentarios(Comentario->getSig() , Vec);
                /*if (Comentario->getSig() != nullptr){
                    cout << "El Primer hermano de: " << Comentario->getTexto() << " es: " << Comentario->getSig()->getTexto() << endl;
                }*/
    }
        
    return Vec;
}
    

vector<string> ControlComentario::listarComentarios(){
    
    vector<string> Respuesta;

                                                                    
    //Funciona pero no se ingresan en orden ni se diferencian los niveles de respuestas

                            //Version 2
                            /*vector<DTProducto> Productos = this->ContrProm->listarProductos();
                            for (auto iterProd = Productos.begin(); iterProd != Productos.end(); iterProd++){

                                Respuesta = HacerListComentarios(this->ContrProm->getProductoByID(iterProd->getId()).GetComentarios() , Respuesta);
                            
                            }*/
    Respuesta = HacerListComentarios(this->ProdSeleccionado->GetComentarios() , Respuesta);
   
   return Respuesta;
}

//Si guarda AResponder = nullptr es que el comentario no existia
void ControlComentario::elegirComentario(string mensaje){

    /*Comentario* AResponder = nullptr;
    vector<DTProducto> Productos = this->ContrProm->listarProductos();
    auto iterProd = Productos.begin();
    while((AResponder == nullptr) && (iterProd != Productos.end())){
        AResponder = getProductoByID(iterProd->getId())->GetComentario(mensaje);
    }
    this->AResponder = AResponder;*/
        Comentario* AResponder = nullptr;
    vector<DTProducto> Productos = this->ContrProm->listarProductos();
    auto iterProd = Productos.begin();

    while((AResponder == nullptr) && (iterProd != Productos.end())){

        AResponder = this->ContrProm->getProductoByID(iterProd->getId())->GetComentarios()->ComentarioEnForo(mensaje);
        ++iterProd;
    }

    this->AResponder = AResponder;
}

void ControlComentario::responderComentario(string respuesta, DTFecha fecha){

    if ((this->UsuarioSeleccionado != nullptr) && (this->AResponder != nullptr))
    {
        Comentario* Opinion = new Comentario(respuesta, fecha);
        vector<string> nickUsuarios = this->ContrUsua->listarNicknamesUsuarios();
        auto iterUsuario = nickUsuarios.begin();
        while((iterUsuario != nickUsuarios.end() && (this->UsuarioSeleccionado != this->ContrUsua->getUsuario(*iterUsuario)))){
           
            ++iterUsuario;
        }
        this->ContrUsua->getUsuario(*iterUsuario)->addComentario(Opinion); //en teoria consigo un usuario con su nick y hago que guarde el comentario

        if (this->AResponder->getResp() == nullptr){
            this->AResponder->setRes(Opinion);
        }else{
            Comentario* aux = this->AResponder->getResp();
            while(aux->getSig() != nullptr){
                    aux = aux->getSig();
                }
                aux->setSig(Opinion);
            }
                        //cout << "siguiente del elegido: " << AResponder->getResp()->getTexto() << endl;
    }
        
}