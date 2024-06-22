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
#include <algorithm>
using namespace std;

void cargarDatosDePrueba(IControlUsuario* controlUsuario, IControlSuscripciones* controlSuscripciones, IControlPromocion* controlPromocion) {
    /*US1 V "ana23", "qwer1234", DTFecha(15,05,1988),  "212345678001"
    US2 V "carlos78", "asdfghj", DTFecha(18,06,1986),    "356789012345"
    US3 V "diegom", "zxcvbn", DTFecha(28,07,1993),  "190123456789"
    US6 V "maria01", "5tgb6yhn", DTFecha(25,03,1985),    "321098765432"
    US10 V "sofia25", "1234asdf", DTFecha(07,12,1983),  "445678901234"

    US4 C "juan87", "1qaz2wsx", DTFecha(20,10,1992), 456, "Av. 18 de Julio",  "Melo"
    US5 C "laura", "3edc4rfv", DTFecha(22,09,1979), 1617, "Rondeau",  "Montevideo"
    US7 C "natalia", "poiuyt", DTFecha(14,04,1982), 2021, "Paysandu",  "Salto"
    US8 C "pablo10", "lkjhgv", DTFecha(30,11,1995),  1819, "Av. Rivera", "Mercedes"
    US9 C "roberto", "mnbvcx", DTFecha(12,08,1990), 1011, "Av. Brasil",  "Montevideo"*/

    controlUsuario->darDeAltaVendedor("ana23", "qwer1234", DTFecha(15,5, 1988), "212345678001");
    controlUsuario->darDeAltaVendedor("carlos78", "asdfghj", DTFecha(18,6,1986), "356789012345");
    controlUsuario->darDeAltaVendedor("diegom", "zxcvbn", DTFecha(28,7,1993),  "190123456789");
    controlUsuario->darDeAltaVendedor("maria01", "5tgb6yhn", DTFecha(25,3,1985),"321098765432");
    controlUsuario->darDeAltaVendedor("sofia25", "1234asdf", DTFecha(7,12,1983),  "445678901234");
    controlUsuario->darDeAltaCliente("juan87", "1qaz2wsx", DTFecha(20,10,1992), 456, "Av. 18 de Julio",  "Melo");
    controlUsuario->darDeAltaCliente("laura", "3edc4rfv", DTFecha(22,9,1979), 1617, "Rondeau",  "Montevideo");
    controlUsuario->darDeAltaCliente("natalia", "poiuyt", DTFecha(14,4,1982), 2021, "Paysandu",  "Salto");
    controlUsuario->darDeAltaCliente("pablo10", "lkjhgv", DTFecha(30,11,1995),  1819, "Av. Rivera", "Mercedes");
    controlUsuario->darDeAltaCliente("roberto", "mnbvcx", DTFecha(12,8,1990), 1011, "Av. Brasil",  "Montevideo");




    controlUsuario->darDeAltaVendedor("vendedor1", "password1", DTFecha(1, 1, 1990), "123456789012");
    controlUsuario->darDeAltaVendedor("vendedor2", "password2", DTFecha(2, 2, 1991), "234567890123");
    controlUsuario->darDeAltaCliente("cliente1", "password3", DTFecha(3, 3, 1992), 123, "18 de Julio ", "ciudad1");

    vector<string> vendedores = {"vendedor1", "vendedor2"};
    controlSuscripciones->suscribirACliente(vendedores, "cliente1");

    controlPromocion->elegirVendedor("vendedor1");  
    controlPromocion->ingresarProducto("Producto 1", "Descripcion 1", 1000, 10, "electrodomesticos");
    controlPromocion->ingresarProducto("Producto 2", "Descripcion 2", 2000, 20, "electrodomesticos");
    controlPromocion->ingresarDatosPromocion("Promocion 1", "Descripcion 1", DTFecha(1, 1, 2022), 10);
    controlPromocion->agregarProductoPromocion(1, 1);
    controlPromocion->agregarProductoPromocion(2, 1);
    controlPromocion->confirmarPromocion();
    cout << "Datos de prueba cargados exitosamente" << endl;
}

void altaDeUsuario(IControlUsuario* controlUsuario){
     char choice;
    string nickname, password, calle, ciudad, rut;
    int dia, mes, anio, nroPuerta;

    
        cout << "Eliga una opción:" << endl;
        cout << "1. Dar de alta cliente" << endl;
        cout << "2. Dar de alta vendedor" << endl;
       
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
                if (password.length() < 6) {
                    cout << "La contraseña debe tener almenos 6 caracteres. Intenta de nuevo." << endl;
                    break;
                }
                cout << "Ingresa la fecha de nacimiento (formato: dd mm aaaa): ";
                cin >> dia >> mes >> anio;
                cout << "Ingresa la calle: ";
                cin.ignore();
                getline(cin, calle);
                cout << "Ingresa el número de puerta: ";
                cin >> nroPuerta;
                cout << "Ingresa la ciudad: ";
                getline(cin, ciudad);
                if (controlUsuario->darDeAltaCliente(nickname, password, DTFecha(dia, mes, anio),nroPuerta, calle, ciudad)) {
                    cout << "Cliente dado de alta exitosamente" << endl;
                } else {
                    cout << "ERROR: nickname ya registrado en el sistema." << endl;
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
                if (password.length() < 6) {
                    cout << "La contraseña debe tener almenos 6 caracteres. Intenta de nuevo." << endl;
                    break;
                }
                cout << "Ingresa la fecha de nacimiento (formato: dd mm aaaa): ";
                cin >> dia >> mes >> anio;
                cout << "Ingresa el RUT (12 digitos): ";
                cin >> rut;
                if (rut.length() != 12 || !all_of(rut.begin(), rut.end(), ::isdigit)) {
                cout << "El RUT debe tener exactamente 12 dígitos y solo contener números. Intenta de nuevo." << endl;
                break;
                }
                if (controlUsuario->darDeAltaVendedor(nickname, password, DTFecha(dia, mes, anio), rut)) {
                    cout << "Vendedor dado de alta exitosamente" << endl;
                } else {
                    cout << "ERROR: nickname ya registrado en el sistema." << endl;
                }
                break;  
                
        }
        

}

void listadoDeUsuarios(IControlUsuario* controlUsuario){
    vector<DTDataCliente> dataCliente = controlUsuario->listarInfoClientes();
    vector<DTDataVendedor> dataVendedor = controlUsuario->listarInfoVendedores();
    
    cout << "Los usuarios son: " << endl;

    for (vector<DTDataCliente>::iterator it = dataCliente.begin(); it != dataCliente.end(); ++it){
        cout << "Nombre: " << it->getNickname() << endl;
        cout << "Fecha de nacimiento: " << it->getFechaNacimiento().getString() << endl;
        cout << "Ciudad: " << it-> getCiudad() <<  endl;
        cout << "Calle: " << it->getCalle() << endl;
        cout << "Número de puerta: " << it->getNroPuerta() << endl;
        cout << endl;
                

    }

    for (vector<DTDataVendedor>::iterator it = dataVendedor.begin(); it != dataVendedor.end(); ++it){
        cout << "Nombre: " << it->getNickname() << endl;
        cout << "Fecha de nacimiento: " << it->getFechaNacimiento().getString() << endl;
        cout << "RUT: " << it->getRut() << endl;
        cout << endl;

    }

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
    string nickname, password, calle, ciudad, rut;
    int dia, mes, anio, nroPuerta;

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
                cout << "Ingresa la calle: ";
                cin.ignore();
                getline(cin, calle);
                cout << "Ingresa el número de puerta: ";
                cin >> nroPuerta;
                cout << "Ingresa la ciudad: ";
                getline(cin, ciudad);
                if (controlUsuario->darDeAltaCliente(nickname, password, DTFecha(dia, mes, anio),nroPuerta,  calle, ciudad)) {
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
                if (rut.length() != 12 || !all_of(rut.begin(), rut.end(), ::isdigit)) {
                cout << "El RUT debe tener exactamente 12 dígitos y solo contener números. Intenta de nuevo." << endl;
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

int main() {
    char choice;

    Factory *factory = new Factory();
    IControlUsuario *controlUsuario = factory->getControlUsuario();
    IControlSuscripciones *controlSuscripciones = factory->getControlSuscripciones();
    IControlPromocion *controlPromocion = factory->getControlPromocion();
    IControlFecha *controlFecha = factory->getControlFecha();
    IControlCompra *controlCompra = factory->getControlCompra();



    do {
        system("clear");
        cout << "Mercado Finger - Equipo 72" << endl;
        cout << "1. Ver y modificar fecha del sistema" << endl;
        cout << "2. Suscripciones" << endl;
        cout << "3. Usuarios" << endl;
        cout << "4. Promociones" << endl;
        cout << "5. Cargar datos de prueba" << endl;
        cout << "6. Salir" << endl;
        cout << "7. Realizar Compra" << endl;
        cout << "8. Alta de Usuario" << endl;
        cout << "9. Listado de Usuarios" << endl;
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
                cargarDatosDePrueba(controlUsuario, controlSuscripciones, controlPromocion);
                break;
            case '6':
                cout << "Saliendo..." << endl;
                break;
            case '7':
                realizarCompra(controlFecha, controlCompra);
                break;
            case '8':
                altaDeUsuario(controlUsuario);
                break;
            case '9':
                listadoDeUsuarios(controlUsuario);
            default:
                cout << "Opcion invalida, intenta de nuevo" << endl;
        }

        cout << "Presiona enter para continuar..." << endl;
        cin.ignore();
        cin.get();
    } while (choice != '6');

    return 0;
}
            
            