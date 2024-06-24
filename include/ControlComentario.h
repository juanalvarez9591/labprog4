#ifndef CONTROL_COMENTARIO_H
#define CONTROL_COMENTARIO_H

#include <string>
#include <vector>
#include "ComentarioArbol.h"
#include "IControlComentario.h"

using namespace std;

class ControlUsuario;
class ControlPromocion;
class ControlFecha;

class ControlComentario : public IControlComentario {
public:
    static ControlComentario* getInstance();
    ~ControlComentario();

    void seleccionarUsuario(string nickUsuario) override;
    void seleccionarProducto(int codigoProducto) override;
    bool realizarComentario(string texto) override;
    string listarComentarios() override;
    bool elegirComentario(string texto) override;
    bool responderComentario(string texto) override;
    bool eliminarComentario(string texto) override;
    string listarComentariosProducto(int codigoProducto) override;
    string listarComentariosDeUsuario(string nickUsuario) override;


private:
    ControlComentario();
    static ControlComentario* instance;

    ControlUsuario* controlUsuario;
    ControlPromocion* controlPromocion;
    ControlFecha* controlFecha;

    string usuarioEnMemoria;
    int productoEnMemoria;
    string comentarioEnMemoria;

    vector<ComentarioArbol*> arboles;
    ComentarioArbol* buscarArbol(int codigoProducto);
    string listarComentariosRecursivo(ComentarioNodo* nodo, int nivel);
    ComentarioNodo* comentarioNodoEnMemoria;
};

#endif // CONTROL_COMENTARIO_H