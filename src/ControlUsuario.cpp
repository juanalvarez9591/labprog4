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
                
            }
        }
    }
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
        Producto* Prod = getProducto(Prod); //FUNCION POR HACER, NO COPILAR!!!!
        if (Prod != NULL){
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
    if (Prod != NULL){
        Prod.AgregarComentario(Opinion);
    }
}
    

vector<DTComentario> ControlUsuario::listarComentarios(){

    Producto* Prod = NULL;
    auto it = vendedores.begin();
    while((it != vendedores.end()) && (Prod == NULL)){
        Prod = getProducto(Prod); //FUNCION POR HACER, NO COPILAR!!!!
        if (Prod == NULL){
            it = it +1;
        }else{
            //Prod->PrintTodosCoenarios();
        }
    }


}

ControlUsuario::~ControlUsuario() {
    // no hay que hacer nada aca, cuando se llama a este destructor por default
    // se llama al destructor de vector, que llama a cada destructor de cliente y vendedor
}