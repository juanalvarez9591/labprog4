#include "IControlComentario.h"
#include "DTFecha.h"
#include "DTComentario.h"
#include "ControlUsuario.h"
#include "ControlSuscripciones.h"
#include <string>
#include <vector>


using namespace std;


class ControlComentario : public IControlUsuario {
public:
//Borrar Comentario
    static ControlComentario* getInstance();
    
    vector<string> listarComentariosUsuario(string nombreUsuario) override;

       //Devuelve un set con las respuestas DIRECTAS del comentario
    set<Comentario> getRespuestas();
    void eliminarComentario(string mensaje);


//Realizar Comentario
    void seleccionarUsuario(string nombreUsuario);
    vector<string> listarProductos();
    void seleccionarProducto(string nombreProducto);
    void realizarComentario(string texto, DTFecha fecha);
    vector<string> listarComentarios();
    void elegirComentario(string mensaje);
    void responderComentario(string respuesta, DTFecha fecha);

    
    virtual ~ControlComentario();

private:
    ControlComentario();
    static ControlComentario* instance;

    //vector<Comentario> Comentarios; //En casos desesperados activar



    vector<string> HacerListComentarios(Comentario* Comentario , vector<string> Vec);
    static ControlComentario* instance;
    string Comentador;
    string Prod;
    Comentario* AResponder;
};
