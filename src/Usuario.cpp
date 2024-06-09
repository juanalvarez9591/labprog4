#include "Usuario.h"

Usuario::Usuario(string nickname, string password, DTFecha* fechaNacimiento, vector<Comentario> comentarios){
    this->nickname = nickname;
    this->password = password;
    this->fechaNacimiento = fechaNacimiento;
    this-> comentarios = comentarios;

};
    string Usuario::getNickname(){
        return this->nickname;
    }

    string Usuario::getPassword(){
        return this->password;
    };

    DTFecha* Usuario::getFechaNacimiento(){
        return this->fechaNacimiento;
    };

    vector <DTComentario> Usuario::conseguirComentarios(Usuario user){
        return null;
    };

    void Usuario::olvidarComentario(Comentario){

  
    };

    ~Usuario(){



    };