#ifndef USUARIO_H
#define USUARIO_H

#include <string>
#include <vector>
#include "DTFecha.h"
#include "Comentario.h"
using namespace std;

class Usuario {
public:
    Usuario(string nickname, string password, DTFecha fechaNacimiento);
    string getNickname() const;
    string getPassword() const;
    DTFecha getFechaNacimiento() const;
    virtual ~Usuario() = default;
    string getNickname();
    void addComentario(Comentario* c);
    void olvidarComentario(Comentario* c);
    vector<Comentario*> getComentarios();
    vector<Comentario*> comentarios; //capaz que es private o protected

protected:
    string nickname;
    string password;
    DTFecha fechaNacimiento;
};

#endif