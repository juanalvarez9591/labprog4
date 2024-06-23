#include <iostream>
#include <string>
#include "Factory.h"
#include "IControlUsuario.h"
#include "IControlPromocion.h"
#include "IControlFecha.h"
#include "DTFecha.h"
#include "DTInfoProducto.h"
#include "DTPromocion.h"
#include "DTProducto.h"
using namespace std;

void cargarDatosDePrueba(IControlUsuario* controlUsuario, IControlSuscripciones* controlSuscripciones, IControlPromocion* controlPromocion, IControlComentario* controlComentario) {
    controlUsuario->darDeAltaVendedor("vendedor1", "password1", DTFecha(1, 1, 1990), 123456789012);
    controlUsuario->darDeAltaVendedor("vendedor2", "password2", DTFecha(2, 2, 1991), 234567890123);
    controlUsuario->darDeAltaCliente("cliente1", "password3", DTFecha(3, 3, 1992), "direccion1", "ciudad1");

    vector<string> vendedores = {"vendedor1", "vendedor2"};
    controlSuscripciones->suscribirACliente(vendedores, "cliente1");

    controlPromocion->elegirVendedor("vendedor1");  
    controlPromocion->ingresarProducto("Producto 1", "Descripcion 1", 1000, 10, "electrodomesticos");
    controlPromocion->ingresarProducto("Producto 2", "Descripcion 2", 2000, 20, "electrodomesticos");
    controlPromocion->ingresarDatosPromocion("Promocion 1", "Descripcion 1", DTFecha(1, 1, 2022), 10);
    controlPromocion->agregarProductoPromocion(1, 1);
    controlPromocion->agregarProductoPromocion(2, 1);
    controlPromocion->confirmarPromocion();

//Para probar comentario
    controlComentario->seleccionarUsuario("vendedor1");
    controlComentario->seleccionarProducto(1);
    controlComentario->realizarComentario("¿La camiseta azul esta disponible en talla M?", DTFecha(1,6,2024));

    controlComentario->seleccionarUsuario("vendedor2");
    controlComentario->seleccionarProducto(1);
    controlComentario->elegirComentario("¿La camiseta azul esta disponible en talla M?");
    controlComentario->responderComentario("Si, tenemos la camiseta azul en talla M", DTFecha(1,6,2024));


    /*controlComentario->seleccionarUsuario("juan87");
    controlComentario->seleccionarProducto(1);
    controlComentario->realizarComentario("¿La camiseta azul esta disponible en talla M?", DTFecha(1,6,2024));

    controlComentario->seleccionarUsuario("carlos78");
    controlComentario->seleccionarProducto(1);
    controlComentario->elegirComentario("¿La camiseta azul esta disponible en talla M?")
    controlComentario->responderComentario("Si, tenemos la camiseta azul en talla M", DTFecha(1,6,2024)); //no se si está bien crear la misma fecha dos veces
    
    controlComentario->seleccionarUsuario("laura");
    controlComentario->seleccionarProducto(1);
    controlComentario->elegirComentario("Si, tenemos la camiseta azul en talla M")
    controlComentario->responderComentario("¿Es de buen material? Me preocupa la durabilidad.", DTFecha(2,6,2024));

    controlComentario->seleccionarUsuario("juan87");
    controlComentario->seleccionarProducto(1);
    controlComentario->elegirComentario("¿Es de buen material? Me preocupa la durabilidad.")
    controlComentario->responderComentario("He comprado antes y la calidad es buena.", DTFecha(2,6,2024));

    controlComentario->seleccionarUsuario("natalia");
    controlComentario->seleccionarProducto(1);
    controlComentario->realizarComentario("¿Como es el ajuste? ¿Es ajustada o holgada?", DTFecha(2,6,2024));

    controlComentario->seleccionarUsuario("laura");
    controlComentario->seleccionarProducto(2);
    controlComentario->realizarComentario("¿Cual es la resolucion del Televisor LED?", DTFecha(2,6,2024));

    controlComentario->seleccionarUsuario("ana23");
    controlComentario->seleccionarProducto(2);
    controlComentario->elegirComentario("¿Cual es la resolucion del Televisor LED?")
    controlComentario->responderComentario("El televisor LED tiene una resolucion de 4K UHD.", DTFecha(2,6,2024));    

    controlComentario->seleccionarUsuario("pablo10");
    controlComentario->seleccionarProducto(2);
    controlComentario->realizarComentario("¿Tiene soporte para HDR10?", DTFecha(3,6,2024));

    controlComentario->seleccionarUsuario("ana23");
    controlComentario->seleccionarProducto(2);
    controlComentario->elegirComentario("¿Tiene soporte para HDR10?")
    controlComentario->responderComentario("Si, soporta HDR10.", DTFecha(3,6,2024));

    controlComentario->seleccionarUsuario("natalia");
    controlComentario->seleccionarProducto(3);
    controlComentario->realizarComentario("¿La chaqueta de cuero es resistente al agua?", DTFecha(3,6,2024));

    controlComentario->seleccionarUsuario("carlos78");
    controlComentario->seleccionarProducto(3);
    controlComentario->elegirComentario("¿La chaqueta de cuero es resistente al agua?")
    controlComentario->responderComentario("No, la chaqueta de cuero no es resistente al agua", DTFecha(3,6,2024));
    */

    cout << "Datos de prueba cargados exitosamente" << endl;


}

void promocionesHandler(IControlPromocion* controlPromocion) {
    char choice;
    string nickVendedor, nombre, descripcion, categoria;
    int idProducto, precio, stock, porcentaje, cantidad;
    DTFecha fechaVencimiento;

    do {
        cout << "Promociones:" << endl;
        cout << "1. Listar nicknames de vendedores" << endl;
        cout << "2. Elegir vendedor" << endl;
        cout << "3. Ingresar producto" << endl;
        cout << "4. Listar productos" << endl;
        cout << "5. Ver info de producto" << endl;
        cout << "6. Ingresar datos de promocion" << endl;
        cout << "7. Ver productos del vendedor" << endl;
        cout << "8. Agregar producto a promocion" << endl;
        cout << "9. Confirmar promocion" << endl;
        cout << "10. Listar promociones vigentes" << endl;
        cout << "11. Consultar productos de promocion" << endl;
        cout << "12. Volver al menu principal" << endl;
        cout << "Ingresa tu opcion: ";
        cin >> choice;

        switch (choice) {
            case '2':
                cout << "Ingresa el nickname del vendedor: ";
                cin >> nickVendedor;
                if (controlPromocion->elegirVendedor(nickVendedor)) {
                    cout << "Vendedor elegido exitosamente" << endl;
                } else {
                    cout << "Error al elegir vendedor" << endl;
                }
                break;
            case '3':
                cout << "Ingresa el nombre del producto: ";
                cin.ignore();
                getline(cin, nombre);
                cout << "Ingresa la descripcion del producto: ";
                getline(cin, descripcion);
                cout << "Ingresa el precio del producto: ";
                cin >> precio;
                cout << "Ingresa el stock del producto: ";
                cin >> stock;
                cout << "Ingresa la categoria del producto: ";
                cin >> categoria;
                if (controlPromocion->ingresarProducto(nombre, descripcion, precio, stock, categoria)) {
                    cout << "Producto ingresado exitosamente" << endl;
                } else {
                    cout << "Error al ingresar el producto, ya se encuentra en otra promocion" << endl;
                }
                break;
            case '5':
                cout << "Ingresa el ID del producto: ";
                cin >> idProducto;
                {
                    DTInfoProducto infoProducto = controlPromocion->verInfoProducto(idProducto);
                    cout << infoProducto.toString() << endl;
                }
                break;
            case '6':
                cout << "Ingresa el nombre de la promocion: ";
                cin.ignore();
                getline(cin, nombre);
                cout << "Ingresa la descripcion de la promocion: ";
                getline(cin, descripcion);
                cout << "Ingresa la fecha de vencimiento (formato: dd mm aaaa): ";
                int dia, mes, anio;
                cin >> dia >> mes >> anio;
                fechaVencimiento = DTFecha(dia, mes, anio);
                cout << "Ingresa el porcentaje de descuento: ";
                cin >> porcentaje;
                controlPromocion->ingresarDatosPromocion(nombre, descripcion, fechaVencimiento, porcentaje);
                cout << "Datos de promocion ingresados exitosamente" << endl;
                break;
            case '7':
            {
                vector<DTProducto> productos = controlPromocion->verProductosVendedor();
                cout << "Productos del vendedor:" << endl;
                for (const DTProducto& producto : productos) {
                    cout << "- " << producto.getNombre() << " (ID: " << producto.getId() << ")" << endl;
                }
            }
                break;
            case '8':
                cout << "Ingresa el ID del producto: ";
                cin >> idProducto;
                cout << "Ingresa la cantidad a agregar: ";
                cin >> cantidad;
                controlPromocion->agregarProductoPromocion(idProducto, cantidad);
                cout << "Producto agregado a la promocion exitosamente" << endl;
                break;
            case '9':
                controlPromocion->confirmarPromocion();
                cout << "Promocion confirmada exitosamente" << endl;
                break;
            case '1':
            {
                vector<DTPromocion> promociones = controlPromocion->listarPromocionesVigentes();
                cout << "Promociones vigentes:" << endl;
                for (const DTPromocion& promocion : promociones) {
                    cout << "- " << promocion.getNombre() << " (Vencimiento: " << promocion.getFechaVencimiento().getString() << ")" << endl;
                }
            }
                break;
            case '4':
                cout << "Ingresa el nombre de la promocion: ";
                cin.ignore();
                getline(cin, nombre);
                {
                    vector<DTInfoProducto> productosPromocion = controlPromocion->consultarProductosPromocion(nombre);
                    cout << "Productos de la promocion:" << endl;
                    for (const DTInfoProducto& producto : productosPromocion) {
                        cout << "- " << producto.toString() << endl;
                    }
                }
                break;
            case '12':
                break;
            default:
                cout << "Opcion invalida, intenta de nuevo" << endl;
        }

        cout << "Presiona enter para continuar..." << endl;
        cin.ignore();
        cin.get();
    } while (choice != '12');
}

void fechaSistemaHandler(IControlFecha* controlFecha) {
    DTFecha currentDate = controlFecha->getFechaActual();
    cout << "La fecha actual del sistema es: " << currentDate.getString() << endl;

    char choice;
    int value;

    do {
        cout << "Modificar fecha del sistema:" << endl;
        cout << "1. Agregar dias" << endl;
        cout << "2. Agregar meses" << endl;
        cout << "3. Agregar anios" << endl;
        cout << "4. Volver al menu principal" << endl;
        cout << "Enter your choice: ";
        cin >> choice;

        switch (choice) {
            case '1':
                cout << "Ingresa el numero de dias a avanzar (o retroceder): ";
                cin >> value;
                controlFecha->agregarDias(value);
                break;
            case '2':
                cout << "Ingresa el numero de meses a avanzar (o retroceder): ";
                cin >> value;
                controlFecha->agregarMeses(value);
                break;
            case '3':
                cout << "Ingresa el numero de anios a avanzar (o retroceder): ";
                cin >> value;
                controlFecha->agregarAnios(value);
                break;
            case '4':
                break;
            default:
                cout << "Opcion invalida, intenta de nuevo" << endl;
        }

        currentDate = controlFecha->getFechaActual();
        cout << "Fecha del sistema actualizada: " << currentDate.getString() << endl;

        cout << "Presiona enter para continuar..." << endl;
        cin.ignore();
        cin.get();

    } while (choice != '4');
}

void suscripcionesHandler(IControlSuscripciones* controlSuscripciones) {
    char choice;
    string nickCliente;

    do {
        cout << "Suscripciones:" << endl;
        cout << "1. Ver vendedores no suscritos" << endl;
        cout << "2. Ver vendedores suscritos" << endl;
        cout << "3. Suscribir a vendedores" << endl;
        cout << "4. Eliminar suscripciones" << endl;
        cout << "5. Listar notificaciones" << endl;
        cout << "6. Volver al menu principal" << endl;
        cout << "Ingresa tu opcion: ";
        cin >> choice;

        switch (choice) {
            case '1':
                cout << "Ingresa el nickname del cliente: ";
                cin >> nickCliente;
                {
                    vector<string> vendedoresNoSuscritos = controlSuscripciones->getVendedoresNoSuscritos(nickCliente);
                    cout << "Vendedores no suscritos:" << endl;
                    for (const string& vendedor : vendedoresNoSuscritos) {
                        cout << "- " << vendedor << endl;
                    }
                }
                break;
            case '2':
                cout << "Ingresa el nickname del cliente: ";
                cin >> nickCliente;
                {
                    vector<string> vendedoresSuscritos = controlSuscripciones->getVendedoresSuscritos(nickCliente);
                    cout << "Vendedores suscritos:" << endl;
                    for (const string& vendedor : vendedoresSuscritos) {
                        cout << "- " << vendedor << endl;
                    }
                }
                break;
            case '3':
            {
                vector<string> nickVendedores;
                string vendedor;
                cout << "Ingresa el nickname del cliente: ";
                cin >> nickCliente;
                cout << "Ingresa los nicknames de los vendedores (ingresa 'fin' para terminar):" << endl;
                cin.ignore(); 
                while (getline(cin, vendedor) && vendedor != "fin") {
                    if (vendedor.find(' ') != string::npos) {
                        cout << "Los nicknames no pueden contener espacios. Intenta de nuevo." << endl;
                    } else {
                        nickVendedores.push_back(vendedor);
                    }
                }
                controlSuscripciones->suscribirACliente(nickVendedores, nickCliente);
                cout << "Suscripcion realizada con exito" << endl;
            }
                break;
            case '4':
            {
                vector<string> nickVendedores;
                string vendedor;
                cout << "Ingresa el nickname del cliente: ";
                cin >> nickCliente;
                cout << "Ingresa los nicknames de los vendedores a eliminar (ingresa 'fin' para terminar):" << endl;
                while (cin >> vendedor && vendedor != "fin") {
                    nickVendedores.push_back(vendedor);
                }
                controlSuscripciones->eliminarSuscripciones(nickVendedores, nickCliente);
                cout << "Suscripciones eliminadas con exito" << endl;
            }
                break;
            case '5':
                cout << "Ingresa el nickname del cliente: ";
                cin >> nickCliente;
                {
                    vector<DTNotificacion> notificaciones = controlSuscripciones->listarNotificaciones(nickCliente);
                    cout << "Notificaciones:" << endl;
                    for (const DTNotificacion& notificacion : notificaciones) {
                        cout << "- " << notificacion.toString() << endl;
                    }
                }
                break;
            case '6':
                break;
            default:
                cout << "Opcion invalida, intenta de nuevo" << endl;
        }

        cout << "Presiona enter para continuar..." << endl;
        cin.ignore();
        cin.get();
    } while (choice != '6');
}


void realizarCompra(IControlFecha* controlFecha, IControlCompra* controlCompra) {
    string nickname;
    vector<string> nicknamesClientes = controlCompra->listarClientes();
    vector <DTDatosProducto> datosProducto = controlCompra->mostrarDatosProducto();
    vector<DTDetalleProducto> parCompra;  
    char choice;
    char confirmar;
    int codigo;
    int cantidad;
    DTFecha currentDate = controlFecha->getFechaActual();

    
    cout << "Los clientes son:" << endl;
    for (auto it = nicknamesClientes.begin(); it != nicknamesClientes.end(); ++it){
        cout << "-" << *it << endl;

    }
    
    cout << "Escriba el nombre del cliente que desea elegir: "; 
    cin.ignore();
    getline(cin, nickname);
    if (nickname.find(' ') != string::npos) {
        cout << "Los nicknames no pueden contener espacios. Intenta de nuevo." << endl;
        return;
    } 

    controlCompra->seleccionarCliente(nickname);//ACÁ SE CREA LA INSTANCIA DE COMPRA Y SE GUARDA EN MEMORIA EN EL CONTROLADOR

    // hasta acá sería seleccionarCliente(string), cuando se confirme la compra, se deberá crear una relación entre el cliente seleccionado y la compra????

    cout << "Los productos son: " << endl;
    for (auto it = datosProducto.begin(); it != datosProducto.end(); ++it){
         
       cout << it->toString() << endl;
    } // hasta acá mostrarDatosProducto():set(DTDatosProducto)

    cout << "¿Desea agregar un producto a la compra? (y/n): ";
    cin >> choice;
    if (choice != 'y'){
        return;
        }
    while (choice == 'y'){
        cout << "Ingrese el código del producto que desea comprar: ";
        cin >> codigo;
        cout << codigo << endl;//
        for (auto it = parCompra.begin(); it != parCompra.end(); ++it) {
                if (it->getCodigoProducto() == codigo) {
                 cout << "ERROR: Producto ya agregado a la compra anteriormente." << endl;
                 return;
                }
        }
        cout << "Ingrese la cantidad que desea comprar: ";
        cin >> cantidad; 
        bool encontrado = false;
        auto it = datosProducto.begin();
        while (!encontrado && it != datosProducto.end()){
            if (codigo == it->getCodigo()){
                encontrado = true;
                if (cantidad > it->getStock()){
                    cout << "La cantidad no puede exceder el stock." << endl;
                    return;
                }
            }
            ++it;

        }
        controlCompra->agregarCantidad(codigo, cantidad);
        parCompra.push_back(DTDetalleProducto(codigo, cantidad));
        cout << "¿Desea agregar un producto a la compra? (y/n): ";
        cin >> choice;
    } // hasta acá sería el loop de agregarProducto(codigoProducto:int, cantidadAComprar: int), le cambio el nombre a agregarCantidad para que tenga más sentido
  
    cout << "Detalle de la compra: " << endl;
    cout << "Fecha: " << currentDate.getString() << endl;

    for (auto it = parCompra.begin(); it != parCompra.end(); ++it){
        for (auto itProducto = datosProducto.begin(); itProducto != datosProducto.end(); ++itProducto) {
            if (it->getCodigoProducto() == itProducto->getCodigo()) {
                cout << "Producto: " << itProducto->getNombre() << ", Cantidad: " << it->getCantProducto() << ", Precio por unidad: " << itProducto->getPrecio() << endl;
                break;
            }
        }
    }
   
    //esto no anda
    float precioTotal = controlCompra->calcularPrecioCompra(parCompra);

    cout << "Precio total luego de descuentos: " << to_string(precioTotal) << endl;
    cout << "Desea confirmar la compra? (y/n): ";
    cin >> confirmar;
    if (confirmar != 'y'){
         controlCompra->olvidarCompra();
        return;
    } else {
        bool aux = controlCompra->confirmarCompra(); 
        if (aux){
            cout << "Compra realizada con éxito!" << endl;
        } else{
            cout << "ERROR: No se pudo realizar la compra." << endl;
        }


    }


}

void usuarioHandler(IControlUsuario* controlUsuario) {
    char choice;
    string nickname, password, direccion, ciudad;
    int dia, mes, anio, rut;

    do {
        cout << "Usuarios:" << endl;
        cout << "1. Dar de alta cliente" << endl;
        cout << "2. Dar de alta vendedor" << endl;
        cout << "3. Listar nicknames de usuarios" << endl;
        cout << "4. Listar nicknames de clientes" << endl;
        cout << "5. Listar nicknames de vendedores" << endl;
        cout << "6. Volver al menu principal" << endl;
        cout << "Ingresa tu opcion: ";
        cin >> choice;

        switch (choice) {
            case '1':
                cout << "Ingresa el nickname: ";
                cin.ignore();
                getline(cin, nickname);
                if (nickname.find(' ') != string::npos) {
                    cout << "Los nicknames no pueden contener espacios. Intenta de nuevo." << endl;
                    break;
                }
                cout << "Ingresa la contraseña: ";
                cin >> password;
                if (password.length() <= 6) {
                    cout << "La contraseña debe tener más de 6 caracteres. Intenta de nuevo." << endl;
                    break;
                }
                cout << "Ingresa la fecha de nacimiento (formato: dd mm aaaa): ";
                cin >> dia >> mes >> anio;
                cout << "Ingresa la direccion: ";
                cin.ignore();
                getline(cin, direccion);
                cout << "Ingresa la ciudad: ";
                getline(cin, ciudad);
                if (controlUsuario->darDeAltaCliente(nickname, password, DTFecha(dia, mes, anio), direccion, ciudad)) {
                    cout << "Cliente dado de alta exitosamente" << endl;
                } else {
                    cout << "Error al dar de alta al cliente" << endl;
                }
                break;
            case '2':
                cout << "Ingresa el nickname: ";
                cin >> nickname;
                if (nickname.find(' ') != string::npos) {
                    cout << "Los nicknames no pueden contener espacios. Intenta de nuevo." << endl;
                    break;
                }
                cout << "Ingresa la contraseña: ";
                cin >> password;
                if (password.length() <= 6) {
                    cout << "La contraseña debe tener más de 6 caracteres. Intenta de nuevo." << endl;
                    break;
                }
                cout << "Ingresa la fecha de nacimiento (formato: dd mm aaaa): ";
                cin >> dia >> mes >> anio;
                cout << "Ingresa el RUT (12 digitos): ";
                cin >> rut;
                if (rut < 10000000 || rut > 99999999) {
                    cout << "El RUT debe tener exactamente 12 digitos. Intenta de nuevo." << endl;
                    break;
                }
                if (controlUsuario->darDeAltaVendedor(nickname, password, DTFecha(dia, mes, anio), rut)) {
                    cout << "Vendedor dado de alta exitosamente" << endl;
                } else {
                    cout << "Error al dar de alta al vendedor" << endl;
                }
                break;
            case '3':
            {
                vector<string> nicknamesUsuarios = controlUsuario->listarNicknamesUsuarios();
                cout << "Nicknames de usuarios:" << endl;
                for (const string& nickname : nicknamesUsuarios) {
                    cout << "- " << nickname << endl;
                }
            }
                break;
            case '4':
            {
                vector<string> nicknamesClientes = controlUsuario->listarNicknamesClientes();
                cout << "Nicknames de clientes:" << endl;
                for (const string& nickname : nicknamesClientes) {
                    cout << "- " << nickname << endl;
                }
            }
                break;
            case '5':
            {
                vector<string> nicknamesVendedores = controlUsuario->listarNicknamesVendedores();
                cout << "Nicknames de vendedores:" << endl;
                for (const string& nickname : nicknamesVendedores) {
                    cout << "- " << nickname << endl;
                }
            }
                break;
            case '6':
                break;
            default:
                cout << "Opcion invalida, intenta de nuevo" << endl;
        }

        cout << "Presiona enter para continuar..." << endl;
        cin.ignore();
        cin.get();
    } while (choice != '6');
}

void ComentarioHandler(IControlComentario* controlComentario, IControlPromocion* controlPromocion, IControlUsuario* controlUsuario, IControlFecha* controlFecha) {
        char choice;
        vector<string> usuarios = controlUsuario->listarNicknamesUsuarios();
        string usuarioElegido;
        string texto;
        bool sinError;
        do {
        cout << "Comentarios:" << endl;
        cout << "1. Dejar comentario" << endl;
        cout << "2. Eliminar comentario" << endl;
        cout << "0. Volver al menú principal" << endl;
        cin >> choice;
        switch (choice) {
            case '0':{ 
                break;
                }  
            case '1':{
                DTFecha fechaActual = controlFecha->getFechaActual();
                int productoElegido;
                string comentarioElegido;
                char alt;
                    //Primero listamos todos los usuarios y el administrador elige el que escribirá el comentario:
                if (usuarios.empty()){
                    cout << "No hay usuarios cargados, Intenta cargar algunos antes" << endl;
                    break;
                }else{
                    cout << "¿Quién escribirá el comentario? " << endl;
                    for(auto iterUsuario = usuarios.begin(); iterUsuario != usuarios.end(); ++iterUsuario) {
                        cout << *iterUsuario << endl;
                    }
                    cin >> usuarioElegido;
                    sinError = controlComentario->seleccionarUsuario(usuarioElegido);
                    if(!sinError) {
                        cout << "Usuario no encontrado, intenta de nuevo. Recuerda que tienes que respetar mayúsculas" << endl;
                        break;
                    }
                    //Ahora listamos todos los productos y el admin elige sobre cuál se escribira el comentario:
                    cout << "¿Sobre qué producto quieres comentar?" << endl;
                    vector<DTProducto> productos = controlPromocion->listarProductos();
                    if (productos.empty()){
                        cout << "Ups, parece que no tenemos productos, vuelve luego" << endl;
                        break;
                    }else{
                        for(auto iterProd = productos.begin(); iterProd != productos.end(); ++iterProd) {
                            cout << "Nombre: " << iterProd->getNombre() << endl;
                            cout << "ID: " << iterProd->getId() << endl;
                        }
                        cout << "Ingresa el ID del producto que quieras" << endl;
                        cin >> productoElegido;
                        //Luego preguntamos si quiere comentar un producto o responder otro comentario:
                        sinError = controlComentario->seleccionarProducto(productoElegido);
                        if(!sinError) {
                            cout << "Producto no encontrado, intenta de nuevo" << endl;
                            break;
                        }
                        cout << "¿Comentar sobre el producto o responder otro comentario?" << endl;
                        cout << "1. Comentar sobre el producto" << endl;
                        cout << "2. Responder un comentario" << endl;
                        cin >> alt;
                        switch (alt) {
                            case '1':{
                                cout << "Escribe el comentario:" << endl;
                                cin.ignore();
                                getline(cin, texto);
                                controlComentario->realizarComentario(texto, fechaActual);
                                cout << "¡Comentario creado con éxito!" << endl;
                                break;
                            }
                            case '2':{
                                //Acá se listan todos los comentarios y se elige cuál responder:
                                vector<string> comentarios = controlComentario->listarComentarios();
                                if (comentarios.empty()){
                                    cout << "Este producto no tiene comentarios actualmente" << endl;
                                    break;
                                }else{
                                    cout << "¿Qué comentario quieres responder?" << endl;
                                    for(auto iterComent = comentarios.begin(); iterComent != comentarios.end(); ++iterComent) {
                                        cout << *iterComent << endl;                                
                                    }
                                    cin.ignore();
                                    getline(cin, comentarioElegido);
                                    sinError = controlComentario->elegirComentario(comentarioElegido);
                                    if (!sinError) {
                                        cout << "No se encontró el comentario, asegurate de haberlo escrito correctamente" << endl;
                                        break;
                                    }
                                    //Y ahora escribe la respuesta:
                                    cout << "Escribe la respuesta:" << endl;
                                    getline(cin, texto);
                                    controlComentario->responderComentario(texto, fechaActual);
                                    cout << "¡Comentario creado con éxito!" << endl;
                                    break;
                                }
                            }
                        }
                        break;
                    }
                }
            }
            case '2':{
                //Primero listamos todos los usuarios y el administrador elige que escribió el comentario que queremos borrar:
                
                if (usuarios.empty()){
                    cout << "No hay usuarios cargados, Intenta cargar algunos antes" << endl;
                    break;
                }else{
                    cout << "Selecciona el usuario cuyo comentario quieres borrar:" << endl;
                    for(auto iterUsuario = usuarios.begin(); iterUsuario != usuarios.end(); ++iterUsuario) {
                        cout << *iterUsuario << endl;
                    }
                    cin >> usuarioElegido;
                    sinError = controlComentario->seleccionarUsuario(usuarioElegido);
                    if (!sinError) {
                        cout << "Usuario no encontrado, intenta de nuevo. Recuerda que tienes que respetar mayúsculas" << endl;
                        break;
                    }
                    //Ahora se listan todos los comentarios del usuario elegido:
                    vector<string> comentarios = controlComentario->listarComentariosUsuario(usuarioElegido);
                    if (comentarios.empty()){
                        cout << "Este usuario no tiene comentarios por el momento" << endl;
                        break;
                    }else{
                        cout << "¿Qué comentario quieres eliminar?" << endl;
                        for(auto iterComent = comentarios.begin(); iterComent != comentarios.end(); ++iterComent) {
                            cout << *iterComent << endl;
                        }
                        cin.ignore();
                        getline(cin, texto);
                        sinError = controlComentario->elegirComentario(texto);
                        if (!sinError) {
                            cout << "No se encontró el comentario, asegurate de haberlo escrito correctamente" << endl;
                            break;
                        }
                        controlComentario->eliminarComentario(texto);
                        cout << "¡Comentario eliminado con éxito!" << endl;
                        break;
                    }
                }
            }
            default:{
                cout << "Opcion invalida, intenta de nuevo" << endl;
            }
        }
        } while (choice != '0');
}

int main() {
    char choice;

    Factory *factory = new Factory();
    IControlUsuario *controlUsuario = factory->getControlUsuario();
    IControlSuscripciones *controlSuscripciones = factory->getControlSuscripciones();
    IControlPromocion *controlPromocion = factory->getControlPromocion();
    IControlFecha *controlFecha = factory->getControlFecha();
    IControlCompra *controlCompra = factory->getControlCompra();
    IControlComentario *controlComentario = factory->getControlComentario();



    do {
        system("clear");
        cout << "Mercado Finger - Equipo 72" << endl;
        cout << "1. Ver y modificar fecha del sistema" << endl;
        cout << "2. Suscripciones" << endl;
        cout << "3. Usuarios" << endl;
        cout << "4. Promociones" << endl;
        cout << "5. Cargar datos de prueba" << endl;
        cout << "6. Realizar Compra" << endl;
        cout << "7. Comentarios" << endl;
        cout << "8. Salir" << endl;
        cout << "Ingresa tu opcion: ";
        cin >> choice;

            switch (choice) {
            case '1':
                fechaSistemaHandler(controlFecha);
                break;
            case '2':
                suscripcionesHandler(controlSuscripciones);
                break;
            case '3':
                usuarioHandler(controlUsuario);
                break;
            case '4':
                promocionesHandler(controlPromocion);
                break;
            case '5':
                cargarDatosDePrueba(controlUsuario, controlSuscripciones, controlPromocion, controlComentario);
                break;
            case '6':
                //realizarCompra(controlCompra, controlPromocion, controlUsuario);
            case '7':
                ComentarioHandler(controlComentario, controlPromocion, controlUsuario, controlFecha);
            case '8':
                cout << "Saliendo..." << endl;
                break;
            case '9':
                //realizarCompra(controlFecha, controlCompra);
            default:
                cout << "Opcion invalida, intenta de nuevo" << endl;
        }

        cout << "Presiona enter para continuar..." << endl;
        cin.ignore();
        cin.get();
    } while (choice != '8');

    return 0;
}
            
            