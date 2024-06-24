#ifndef CONTROL_COMENTARIO_H
#define CONTROL_COMENTARIO_H

#include "IControlComentario.h"
#include "ControlUsuario.h"
#include "ControlPromocion.h"
#include "Usuario.h"
#include "Producto.h"
#include "Comentario.h"

class ControlComentario : public IControlComentario {
private:
    static ControlComentario* instance;
    ControlComentario();

    ControlUsuario* ContrUsua;
    ControlPromocion* ContrProm;
    Usuario* UsuarioSeleccionado;
    Producto* ProdSeleccionado;
    Comentario* AResponder;

public:
    static ControlComentario* getInstance();
    virtual ~ControlComentario();

    vector<string> listarComentariosUsuario(string nombreUsuario) override;
    void eliminarComentario(string mensaje) override;

    bool seleccionarUsuario(string nombreUsuario) override;
    vector<DTProducto> listarProductos() override;
    bool seleccionarProducto(int IDProducto) override;
    void realizarComentario(string texto, DTFecha fecha) override;
    vector<string> listarComentarios() override;
    bool elegirComentario(string mensaje) override;
    void responderComentario(string respuesta, DTFecha fecha) override;
};

#endif // CONTROL_COMENTARIO_H