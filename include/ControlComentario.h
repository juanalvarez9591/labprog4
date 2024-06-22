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
    void seleccionarUsuario(string nombreUsuario);
    vector<DTProducto> listarProductos();
    void seleccionarProducto(int IDProducto);
    void realizarComentario(string texto, DTFecha fecha);
    vector<string> listarComentarios();
    void elegirComentario(string mensaje);
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
