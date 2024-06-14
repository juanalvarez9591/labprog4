#include "ControlUsuario.h"
#include "Comentario.h"
#include "Producto.h"

ControlUsuario* ControlUsuario::instance = nullptr;

ControlUsuario* ControlUsuario::getInstance() {
    if (instance == nullptr) {
        instance = new ControlUsuario();
    }
    return instance;
}

ControlUsuario::ControlUsuario() {
    clientes = vector<Cliente>();
    vendedores = vector<Vendedor>();
}

bool ControlUsuario::darDeAltaCliente(string nickname, string password, DTFecha fechaNacimiento, string direccion, string ciudad) {
    if (nicknameRepetido(nickname)) {
        return false;
    }

    Cliente cliente(nickname, password, fechaNacimiento, direccion, ciudad);
    clientes.push_back(cliente);
    return true;
}

bool ControlUsuario::darDeAltaVendedor(string nickname, string password, DTFecha fechaNacimiento, int rut) {
    if (nicknameRepetido(nickname)) {
        return false;
    }

    Vendedor vendedor(nickname, password, fechaNacimiento, rut);
    vendedores.push_back(vendedor);
    return true;
}

bool ControlUsuario::nicknameRepetido(string nickname) {
    for (auto it = clientes.begin(); it != clientes.end(); it++) {
        if (it->getNickname() == nickname) {
            return true;
        }
    }
    for (auto it = vendedores.begin(); it != vendedores.end(); it++) {
        if (it->getNickname() == nickname) {
            return true;
        }
    }

    return false;
}

vector<string> ControlUsuario::listarNicknamesUsuarios() {
    vector<string> nicknames;
    for (auto it = clientes.begin(); it != clientes.end(); it++) {
        nicknames.push_back(it->getNickname());
    }
    for (auto it = vendedores.begin(); it != vendedores.end(); it++) {
        nicknames.push_back(it->getNickname());
    }

    return nicknames;
}

vector<string> ControlUsuario::listarNicknamesClientes() {
    vector<string> nicknames;
    for (auto it = clientes.begin(); it != clientes.end(); it++) {
        nicknames.push_back(it->getNickname());
    }

    return nicknames;
}

vector<string> ControlUsuario::listarNicknamesVendedores() {
    vector<string> nicknames;
    for (auto it = vendedores.begin(); it != vendedores.end(); it++) {
        nicknames.push_back(it->getNickname());
    }

    return nicknames;
}

Usuario* ControlUsuario::getUsuario(string nickname) {
    for (auto it = clientes.begin(); it != clientes.end(); it++) {
        if (it->getNickname() == nickname) {
            return &(*it);
        }
    }
    for (auto it = vendedores.begin(); it != vendedores.end(); it++) {
        if (it->getNickname() == nickname) {
            return &(*it);
        }
    }

    return nullptr;
}

vector<Comentario*> ControlUsuario::listarComentariosUsuario(string nombreUsuario) {
    vector<Comentario*> comentarios = getUsuario(nombreUsuario)->getComentarios();
    return comentarios;
}

void ControlUsuario::eliminarComentario(string mensaje) {
    auto nickUsuarios = listarNicknamesUsuarios();
    bool borrado = false; //adaptar fors a while
    auto iterUsuario = nickUsuarios.begin();
    while((iterUsuario != nickUsuarios.end()) && !borrado) {
        auto comentarios = listarComentariosUsuario(*iterUsuario);
        auto iterComent = comentarios.begin();
        while(iterComent != comentarios.end() && !borrado) {
            Comentario *aBorrar = NULL;
            if (iterComent->getSig()->getTexto() == mensaje) {
                aBorrar = iterComent->getSig();
                iterComent->setSig(aBorrar->getSig());
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

Vendedor* ControlUsuario::getVendedor(string nickname) {
    for (auto it = vendedores.begin(); it != vendedores.end(); it++) {
        if (it->getNickname() == nickname) {
            return &(*it);
        }
    }

    return nullptr;
}

Cliente* ControlUsuario::getCliente(string nickname) {
    for (auto it = clientes.begin(); it != clientes.end(); it++) {
        if (it->getNickname() == nickname) {
            return &(*it);
        }
    }

    return nullptr;
}

vector<Vendedor> ControlUsuario::getVendedores() {
    return vendedores;
}


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

//Comentario directo
 //Falta por hacer Una funcion en vendedor que nos de acceso a la direccion de un producto buscado segun la clave
void ControlUsuario::realizarComentario(string texto, DTFecha fecha){
    
    Comentario* Opinion = new Comentario(texto, fecha);

    //fase de busqueda
    bool found = false;
    auto it = vendedores.begin();
    while((it != vendedores.end()) && !found){
        Producto* Product = it->getProducto(Product); //FUNCION POR HACER, NO COPILAR!!!! DEVUELVE UN PUNTERO A EL PRODUCTO CON EL MISMO NOMBRE, DESDE VENDEDOR, si no hay devuelve NULL
        if (Product != NULL){
            found = true;
        }else{
            it = it +1;
        }
    }
                                                            /*for (auto it = vendedores.begin(); it != vendedores.end(); it++) {

                                                                if (it->getNickname() == nickname) {
                                                                    return true;
                                                                }*/

    //fase de ensablaje
    if (Product != NULL){
        Product.AgregarComentario(Opinion);

        //FALTA AGREGAR A LA COLECCION INTERNA DEL VENDEDOR
    }
}


vector<string> HacerListComentarios(Comentario* Comentario , vector<string> Vec){
    Vec.push_back(Comentario->texto);
    HacerListComentarios(Comentario->getResp() , Vec);
    HacerListComentarios(Comentario->getResp() , Vec);
    return Vec;
}
    

vector<string> ControlUsuario::listarComentarios(){
    vector<string> Respuesta;
    Producto* Product = NULL;
    auto it = vendedores.begin();
    while((it != vendedores.end()) && (Product == NULL)){
        Product = it->getProducto(Product); //FUNCION POR HACER, NO COPILAR!!!!
        if (Product == NULL){
            it = it +1;
        }
    }
    if (Product != NULL){
        Respuesta = HacerListComentarios(Product->Foro, Respuesta);
    }

    return Respuesta;
}

void elegirComentario(string mensaje){
    Producto* Product = NULL;
    auto it = vendedores.begin();
    while((it != vendedores.end()) && (Product == NULL)){
        Product = it->getProducto(Product); //FUNCION POR HACER, NO COPILAR!!!!
        if (Product == NULL){
            it = it +1;
        }
    }
    if (Product == NULL){
        break;
    }else{
        this->Prod = Estecomentario(Product , mensaje);
    }
    
}

ControlUsuario::~ControlUsuario() {
    // no hay que hacer nada aca, cuando se llama a este destructor por default
    // se llama al destructor de vector, que llama a cada destructor de cliente y vendedor
}