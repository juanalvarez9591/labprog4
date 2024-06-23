#include "IControlComentario.h"
#include "DTFecha.h"
#include "DTComentario.h"
#include "ControlUsuario.h"
#include "ControlPromocion.h"
#include "ControlSuscripciones.h"
#include <string>
#include <vector>
#include <set>
#include "Producto.h"
#include "Usuario.h"
#include "Comentario.h"

using namespace std;


class ControlComentario : public IControlComentario {
public:
//Borrar Comentario
    static ControlComentario* getInstance();
    
    vector<string> listarComentariosUsuario(string nombreUsuario); //override;

       //Devuelve un set con las respuestas DIRECTAS del comentario
    //set<Comentario> getRespuestas();
    void eliminarComentario(string mensaje);


//Realizar Comentario
    bool seleccionarUsuario(string nombreUsuario); //Devuelve false si no encontró el usuario
    vector<DTProducto> listarProductos();
    bool seleccionarProducto(int IDProducto); //Devuelve false si no encontró el usuario
    void realizarComentario(string texto, DTFecha fecha);
    vector<string> listarComentarios();
    bool elegirComentario(string mensaje); //Devuelve false si no encontró el comentario
    void responderComentario(string respuesta, DTFecha fecha);

    
    virtual ~ControlComentario();

private:
    ControlComentario();
    static ControlComentario* instance;

    //vector<Comentario> Comentarios; //En casos desesperados activar


    Usuario* getUsuarioComentario(string texto);
    vector<string> HacerListComentarios(Comentario* Comentario , vector<string> Vec);
    //string Comentador;
    Usuario* UsuarioSeleccionado;
    //string Prod;
    Producto* ProdSeleccionado;
    Comentario* AResponder;

    ControlUsuario* ContrUsua; // = ControlUsuario::getInstance()
    ControlPromocion* ContrProm ; //= ControlPromocion::getInstance()
};
