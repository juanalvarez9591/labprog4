#ifndef USUARIO_H
#define USUARIO_H

#include <vector>
#include <string>
#include <Comentario.h>
#include <DTFecha.h>
#include <DTComentario.h>
using namespace std;

class Usuario {
private:
    string nickname;
    string password;
    DTFecha* fechaNacimiento;
    vector <Comentario> comentarios;

public:
    Usuario(string nickname, string password, DTFecha* fechaNacimiento, vector<Comentario> comentarios);
    string getNickname();
    string getPassword();
    DTFecha* getFechaNacimiento();
    vector <DTComentario> conseguirComentarios(Usuario user);
    void olvidarComentario(Comentario);
    ~Usuario();


    
};

#endif