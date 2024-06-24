#include <iostream>
#include <string>
#include <set>
#include "Factory.h"
#include "IControlUsuario.h"
#include "IControlPromocion.h"
#include "IControlFecha.h"
#include "DTFecha.h"
#include "DTInfoProducto.h"
#include "DTPromocion.h"
#include "DTProducto.h"
#include "DTExpCliente.h"
#include "DTExpVendedor.h"
#include "DTCompra.h"
#include <algorithm>
using namespace std;

void cargarDatosDePrueba(IControlUsuario* controlUsuario, IControlSuscripciones* controlSuscripciones, IControlPromocion* controlPromocion, IControlCompra* controlCompra, IControlFecha* controlFecha, IControlComentario* controlComentario) {
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

    controlPromocion->crearProducto("Camiseta Azul", 1400, 50, "Camiseta de poliester, color azul", "Ropa", "carlos78");
    controlPromocion->crearProducto("Televisor LED", 40500, 30, "Televisor LED 55 pulgadas", "Electrodomestico", "ana23");
    controlPromocion->crearProducto("Chaqueta de Cuero", 699.99, 20, "Chaqueta de cuero, color negro", "Ropa", "carlos78");
    controlPromocion->crearProducto("Microondas Digital", 1199.99, 15, "Microondas digital, 30L", "Electrodomestico", "ana23");
    controlPromocion->crearProducto("Luz LED", 599.99, 40, "Luz Bluetooth LED", "Otro", "diegom");
    controlPromocion->crearProducto("Pantalones Vaqueros", 60, 25, "Pantalones vaqueros, talla 32", "Ropa", "carlos78");
    controlPromocion->crearProducto("Auriculares Bluetooth", 199.99, 35, "Auriculares bluethooth para celular", "Otro", "diegom");
    controlPromocion->crearProducto("Refrigerador", 15499, 10, "Refrigerador de doble puerta", "Electrodomestico", "ana23");
    controlPromocion->crearProducto("Cafetera", 23000, 50, "Cafetera de goteo programable", "Electrodomestico", "ana23");
    controlPromocion->crearProducto("Zapatillas Deportivas", 5500, 20, "Zapatillas para correr, talla 42", "Ropa", "carlos78");
    controlPromocion->crearProducto("Mochila", 9000, 30, "Mochila de viaje, 40L", "Otro", "carlos78");
    controlPromocion->crearProducto("Plancha de Ropa", 2534, 25, "Plancha a vapor, 1500W", "Electrodomestico", "diegom");
    controlPromocion->crearProducto("Gorra", 200, 50, "Gorra para deportes, color rojo", "Ropa", "sofia25");
    controlPromocion->crearProducto("Tablet", 15000, 15, "Tablet Android de 10 pulgadas", "Electrodomestico", "diegom");
    controlPromocion->crearProducto("Reloj de Pared", 150.50, 20, "Reloj de pared vintage", "Otro", "sofia25");

    controlPromocion->elegirVendedor("ana23");
    controlPromocion->ingresarDatosPromocion("Casa nueva", "Para que puedas ahorrar en la casa nueva", DTFecha(25, 10, 2024), 30);
    controlPromocion->agregarProductoPromocion(2, 1);
    controlPromocion->agregarProductoPromocion(4, 1);
    controlPromocion->agregarProductoPromocion(8, 1);
    controlPromocion->confirmarPromocion();

    controlPromocion->elegirVendedor("carlos78");
    controlPromocion->ingresarDatosPromocion("Fiesta", "Para que no te quedes sin ropa para las fiestas", DTFecha(26, 10, 2024), 20);
    controlPromocion->agregarProductoPromocion(3, 2);
    controlPromocion->agregarProductoPromocion(6, 3);
    controlPromocion->confirmarPromocion();

    controlPromocion->elegirVendedor("diegom");
    controlPromocion->ingresarDatosPromocion("Domotica", "Para modernizar tu casa", DTFecha(26, 10, 2024), 10);
    controlPromocion->agregarProductoPromocion(5, 2);
    controlPromocion->confirmarPromocion();

    controlPromocion->elegirVendedor("diegom");
    controlPromocion->ingresarDatosPromocion("Liquidacion", "Hasta agotar stock", DTFecha(26, 3, 2024), 10);
    controlPromocion->agregarProductoPromocion(14, 1);
    controlPromocion->confirmarPromocion();

    controlFecha->setFechaActual(DTFecha(1,5,2024));
    controlCompra->seleccionarCliente("juan87");
    controlCompra->agregarCantidad(2, 2);
    controlCompra->agregarCantidad(4, 1);
    controlCompra->agregarCantidad(8,1);
    controlCompra->confirmarCompra();
    controlCompra->elegirProducto(2);
    vector<DTCompra> comprasCliente1 = controlCompra->listarComprasCliente();
    controlCompra->marcarComoEnviado(1);

    controlCompra->seleccionarCliente("juan87");
    controlCompra->agregarCantidad(5, 1);
    controlCompra->confirmarCompra();
    controlCompra->elegirProducto(5);
    vector<DTCompra> comprasCliente2 = controlCompra->listarComprasCliente();
    controlCompra->marcarComoEnviado(1);

    controlFecha->setFechaActual(DTFecha(15,5,2024));
    controlCompra->seleccionarCliente("laura");
    controlCompra->agregarCantidad(14, 10);
    controlCompra->confirmarCompra();
    controlCompra->elegirProducto(14);
    vector<DTCompra> comprasCliente3 = controlCompra->listarComprasCliente();
    controlCompra->marcarComoEnviado(1);


    controlFecha->setFechaActual(DTFecha(25,4,2024));
    controlCompra->seleccionarCliente("natalia");
    controlCompra->agregarCantidad(11, 1);
    controlCompra->agregarCantidad(12, 1);
    controlCompra->agregarCantidad(13, 1);
    controlCompra->confirmarCompra();
    controlCompra->elegirProducto(11);
    vector<DTCompra> comprasCliente4 = controlCompra->listarComprasCliente();
    controlCompra->marcarComoEnviado(1);
    controlCompra->elegirProducto(12);
    vector<DTCompra> comprasCliente5 = controlCompra->listarComprasCliente();
    controlCompra->marcarComoEnviado(1);
    controlCompra->elegirProducto(13);
    vector<DTCompra> comprasCliente6 = controlCompra->listarComprasCliente();
    controlCompra->marcarComoEnviado(1);

    controlFecha->setFechaActual(DTFecha(20,5,2024));
    controlCompra->seleccionarCliente("juan87");
    controlCompra->agregarCantidad(3, 2);
    controlCompra->agregarCantidad(6, 3);
    controlCompra->confirmarCompra();
    controlCompra->elegirProducto(6);
    vector<DTCompra> comprasCliente7 = controlCompra->listarComprasCliente();
    controlCompra->marcarComoEnviado(1);

    controlFecha->setFechaActual(DTFecha(12,5,2024));
    controlCompra->seleccionarCliente("laura");
    controlCompra->agregarCantidad(1, 2);
    controlCompra->confirmarCompra();

    controlFecha->setFechaActual(DTFecha(13,5,2024));
    controlCompra->seleccionarCliente("natalia");
    controlCompra->agregarCantidad(1, 3);
    controlCompra->confirmarCompra();
    controlCompra->elegirProducto(1);
    vector<DTCompra> comprasCliente8 = controlCompra->listarComprasCliente();
    controlCompra->marcarComoEnviado(1);

    controlFecha->setFechaActual(DTFecha(14,5,2024));
    controlCompra->seleccionarCliente("pablo10");
    controlCompra->agregarCantidad(1, 4);
    controlCompra->confirmarCompra();

    controlFecha->setFechaActual(DTFecha(15,5,2024));
    controlCompra->seleccionarCliente("roberto");
    controlCompra->agregarCantidad(1, 5);
    controlCompra->confirmarCompra();

    controlFecha->setFechaActual(DTFecha(1,6,2024));
    controlComentario->seleccionarUsuario("juan87");
    controlComentario->seleccionarProducto(1);
    controlComentario->realizarComentario("¿La camiseta azul esta disponible en talla M?");

    controlFecha->setFechaActual(DTFecha(1,6,2024));
    controlComentario->seleccionarUsuario("carlos78");
    controlComentario->seleccionarProducto(1);
    controlComentario->elegirComentario("¿La camiseta azul esta disponible en talla M?");
    controlComentario->responderComentario("Si, tenemos la camiseta azul en talla M");

    controlFecha->setFechaActual(DTFecha(2,6,2024));
    controlComentario->seleccionarUsuario("laura");
    controlComentario->seleccionarProducto(1);
    controlComentario->elegirComentario("Si, tenemos la camiseta azul en talla M");
    controlComentario->responderComentario("¿Es de buen material? Me preocupa la durabilidad.");

    controlFecha->setFechaActual(DTFecha(2,6,2024));
    controlComentario->seleccionarUsuario("juan87");
    controlComentario->seleccionarProducto(1);
    controlComentario->elegirComentario("¿Es de buen material? Me preocupa la durabilidad.");
    controlComentario->responderComentario("He comprado antes y la calidad es buena.");

    controlFecha->setFechaActual(DTFecha(2,6,2024));
    controlComentario->seleccionarUsuario("natalia");
    controlComentario->seleccionarProducto(1);
    controlComentario->realizarComentario("¿Como es el ajuste? ¿Es ajustada o holgada?");

    controlFecha->setFechaActual(DTFecha(2,6,2024));
    controlComentario->seleccionarUsuario("laura");
    controlComentario->seleccionarProducto(2);
    controlComentario->realizarComentario("¿Cual es la resolucion del Televisor LED?");

    controlFecha->setFechaActual(DTFecha(2,6,2024));
    controlComentario->seleccionarUsuario("ana23");
    controlComentario->seleccionarProducto(2);
    controlComentario->elegirComentario("¿Cual es la resolucion del Televisor LED?");
    controlComentario->responderComentario("El televisor LED tiene una resolucion de 4K UHD.");

    controlFecha->setFechaActual(DTFecha(3,6,2024));
    controlComentario->seleccionarUsuario("pablo10");
    controlComentario->seleccionarProducto(2);
    controlComentario->realizarComentario("¿Tiene soporte para HDR10?");

    controlFecha->setFechaActual(DTFecha(3,6,2024));
    controlComentario->seleccionarUsuario("ana23");
    controlComentario->seleccionarProducto(2);
    controlComentario->elegirComentario("¿Tiene soporte para HDR10?");
    controlComentario->responderComentario("Si, soporta HDR10.");

    controlFecha->setFechaActual(DTFecha(3,6,2024));
    controlComentario->seleccionarUsuario("natalia");
    controlComentario->seleccionarProducto(3);
    controlComentario->realizarComentario("¿La chaqueta de cuero es resistente al agua?");

    controlFecha->setFechaActual(DTFecha(3,6,2024));
    controlComentario->seleccionarUsuario("carlos78");
    controlComentario->seleccionarProducto(3);
    controlComentario->elegirComentario("¿La chaqueta de cuero es resistente al agua?");
    controlComentario->responderComentario("No, la chaqueta de cuero no es resistente al agua");

    controlFecha->setFechaActual(DTFecha(1,1,2024));

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

void altaDeProducto(IControlPromocion* controlPromocion, IControlUsuario* controlUsuario){
    vector<string> nombresVendedores = controlUsuario->listarNicknamesVendedores();
    string vendedorElegido;
    string nombreProducto, descripcion, categoria;
    float precio;
    int stock;

    cout << "Los vendedores son: " <<endl;
    for (vector<string>::iterator it = nombresVendedores.begin(); it != nombresVendedores.end(); ++it){
        cout << "-" << *it << endl;
    }
    cout << "Ingrese el nombre del vendedor que desea elegir: ";
    cin.ignore();
    getline(cin, vendedorElegido);

    cout << "Ingrese el nombre del producto: ";
    getline(cin, nombreProducto);
    cout << "Ingrese el precio: ";
    cin >> precio;
    cout << "Ingrese la cantidad en stock: ";
    cin >> stock;
    cout << "Ingrese una descripción: ";
    cin.ignore();
    getline(cin, descripcion);
    cout << "Ingrese la categoría: ";
    getline(cin, categoria);
    cout << endl;

    bool exito = controlPromocion->crearProducto(nombreProducto, precio, stock, descripcion, categoria, vendedorElegido);
    if (exito){
        cout << "Producto dado de alta exitosamente!"<< endl;
    } else {
        cout << "Error: compruebe el nombre del vendedor." << endl;
    }

}

void consultarProducto (IControlPromocion* controlPromocion){
    vector<DTProducto> dataProductos = controlPromocion->listarProductos();
    int codigo;

    cout << "Información de todos los productos registrados: " << endl;
    for (vector<DTProducto>::iterator it = dataProductos.begin(); it != dataProductos.end(); ++it){
        cout << "-" << it->getNombre() << " ID: " << to_string(it->getId()) << endl;
    }
    cout << "Ingrese el código del producto seleccionado: ";
    cin >> codigo;

    DTInfoProducto infoProductoElegido = controlPromocion->verInfoProducto(codigo);

      if ((infoProductoElegido.getNombre() == "") && (infoProductoElegido.getPrecio() == 0)){
        /*uso esto como manejador de errores, ya que en caos de que el producto no exista, verInfoProducto llama
        al constructor por defecto, que setea el nombre con "" y el precio en 0, entre otros.*/
        cout << "El producto seleccionado no existe." << endl;
      }  else {
            // El producto existe, mostrar información
            string texto = infoProductoElegido.toString();
            cout << texto <<endl;
    }



}

void expedienteUsuario (IControlUsuario* controlUsuario){
    vector<string> nombresUsuarios = controlUsuario->listarNicknamesUsuarios();
    string usuarioElegido;

    cout << "Los nombres de todos los usuarios son: " << endl;
    cout << endl;
    for (vector<string>::iterator it = nombresUsuarios.begin(); it !=nombresUsuarios.end(); ++it){
        cout << "-" << *it << endl;
    }
    cout << "Escriba el nombre del usuario elegido: ";
    cin.ignore();
    getline(cin, usuarioElegido);

    DTInfoUsuarios* infoUsuario = controlUsuario->verExpedienteUsuario(usuarioElegido);

     if (infoUsuario) {
         if (const DTExpCliente* clienteElegido = dynamic_cast<const DTExpCliente*>(infoUsuario)) {
             // Si el downcast fue exitoso, podemos acceder a todos los datos de DTExpCliente
             cout << "Nickname: " << clienteElegido->getNickname() << endl;
             cout << "Fecha de nacimiento: " << clienteElegido->getFechaNacimiento().getString() << endl;
             cout << "Número de puerta: " << clienteElegido->getNroPuerta() << endl;
             cout << "Calle: " << clienteElegido->getCalle() << endl;
             cout << "Ciudad: " << clienteElegido->getCiudad() << endl;

             cout << "Información de compras:" << endl;
             vector<DTExpCompra> compras = clienteElegido->getCompras();
             for (vector<DTExpCompra>::const_iterator compraIt = compras.begin(); compraIt != compras.end(); ++compraIt) {
                 cout << "Costo: $" << compraIt->getCosto() << endl;
                 cout << "Fecha de compra: " << compraIt->getFecha().getString() << endl;
                 cout << "Productos:" << endl;
                 vector<DTExpProducto> productos = compraIt->getProductos();
                 for (vector<DTExpProducto>::const_iterator prodIt = productos.begin(); prodIt != productos.end(); ++prodIt) {
                     cout << " - Código: " << prodIt->getCodigoProducto()
                          << ", Nombre: " << prodIt->getNombreProducto()
                          << ", Cantidad: " << prodIt->getCantidadProducto()
                          << ", Enviado: ";
                     if (prodIt->getEnviado()) {
                         cout << "Sí";
                     } else {
                         cout << "No";
                     }
                     cout << endl;
                 }
                 cout << endl;
             }
         }   else if (const DTExpVendedor* vendedorElegido = dynamic_cast<const DTExpVendedor*>(infoUsuario)) {
                 // Si el downcast a DTExpVendedor fue exitoso, mostramos los datos del vendedor
                cout << "Nickname: " << vendedorElegido->getNickname() << endl;
                cout << "Fecha de nacimiento: " << vendedorElegido->getFechaNacimiento().getString() << endl;
                cout << "RUT: " << vendedorElegido->getRut() << endl;

                vector<DTPromocion> promociones = vendedorElegido->getPromociones();
                cout << "Promociones vigentes:" << endl;
                for (const auto& promocion : promociones) {
                    cout << " - " << promocion.getNombre() << endl;
                }

                vector<DTProducto> productos = vendedorElegido->getProductos();
                cout << "Productos:" << endl;
                for (const auto& producto : productos) {
                    cout << " - " << producto.getNombre() << endl;
                }
            }

    } else {
        cout << "No se encontró el usuario especificado." << endl;
    }

}

void promocionesHandler(IControlPromocion* controlPromocion, IControlUsuario* controlUsuario) {
    string choiceStr;
    int choice;

    string nickVendedor, nombre, descripcion, categoria;
    int idProducto, precio, stock, porcentaje, cantidad;
    DTFecha fechaVencimiento;

    do {
        cout << "Promociones:" << endl;
        cout << "1. Crear Promocion" << endl;
        cout << "2. Consultar Promoción" << endl;
        cout << "3. Volver al menu principal" << endl;
        cout << "Ingresa tu opcion: ";
        cin >> choiceStr;

        try {
            choice = stoi(choiceStr);
        } catch (const std::invalid_argument& ia) {
            choice = 0;  // Invalid input
        }

        switch (choice) {
            case 1:
            {
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
                
                vector<string> nicknames = controlUsuario->listarNicknamesVendedores();
                cout << "Nicknames de vendedores:" << endl;
                for (const string& nickname : nicknames) {
                    cout << "- " << nickname << endl;
                }
                
                cout << endl << "Ingresa el nickname del vendedor: ";
                cin >> nickVendedor;
                if (controlPromocion->elegirVendedor(nickVendedor)) {
                    cout << "Vendedor elegido exitosamente" << endl;
                } else {
                    cout << "Error al elegir vendedor" << endl;
                }

                vector<DTProducto> productos = controlPromocion->verProductosVendedorEnMemoria();
                cout << endl << "Productos del vendedor:" << endl;
                for (const DTProducto& producto : productos) {
                    cout << "- " << producto.getNombre() << " (ID: " << producto.getId() << ")" << endl;
                }
                char eleccion;
                cout << "Desea agregar un producto a la promoción? (y/n): ";
                cin >> eleccion;
                while (eleccion == 'y'){
                    cout << "Ingresa el ID del producto: ";
                cin >> idProducto;
                cout << "Ingresa la cantidad mínima para aplicar la promoción: ";
                cin >> cantidad;
                controlPromocion->agregarProductoPromocion(idProducto, cantidad);
                cout << "Producto agregado a la promocion exitosamente." << endl;
                cout << "Desea agregar un producto a la promoción? (y/n): ";
                cin >> eleccion;
                }
                controlPromocion->confirmarPromocion();
                cout << "Promocion confirmada exitosamente" << endl;

            }
                break;
            case 2:
                char eleccion;
               {
                    vector<DTPromocion> dataPromociones = controlPromocion->listarPromocionesVigentes();
                cout << endl;
                cout << "Las promociones vigentes son: "<< endl;
                for (vector<DTPromocion>::iterator it = dataPromociones.begin(); it != dataPromociones.end(); ++it){
                    cout << "Nombre: " << it->getNombre() << endl;
                    cout << "Descripcion: " << it->getDescripcion() << endl;
                    cout << "Fecha Vencimiento: " <<it->getFechaVencimiento().getString() << endl;
                    cout << "Descuento: " << to_string(it->getPorcentaje()) << "%" << endl;
                    cout << endl; 

                }
                cout << "Quiere más información de alguna promoción? (y/n): ";
                cin >> eleccion;
                if (eleccion == 'y'){
                    string nombrePromo;
                    cout << "Escriba el nombre de la promoción: ";
                    cin.ignore();
                    getline(cin,nombrePromo);
                    cout << endl;
                    vector<DTInfoProducto> infoProducto = controlPromocion->consultarProductosPromocion(nombrePromo);
                    for(vector<DTInfoProducto>::iterator it = infoProducto.begin(); it !=infoProducto.end(); ++it){
                        cout << it->toString() << endl;
                    } 
                }
               else {
                    break;
                 }
            }break;
            
            case 3:
                cout << "Volviendo al menu principal..." << endl;
                break;
            default:
                cout << "Opcion invalida, intenta de nuevo" << endl;
        }

        if (choice != 3) {
            cout << "Presiona enter para continuar...";
            cin.ignore();
            cin.get();
        }
    } while (choice != 3);
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

void compraHandler(IControlCompra* controlCompra, IControlPromocion* controlPromocion, IControlUsuario* controlUsuario) {
    char choice;

    do {
        cout << "Menu de Compra:" << endl;
        cout << "1. Realizar compra" << endl;
        cout << "2. Volver al menu principal" << endl;
        cout << "Ingresa tu opcion: ";
        cin >> choice;

        switch (choice) {
            case '1':
            {
                // Listar clientes
                vector<string> nicknamesClientes = controlUsuario->listarNicknamesClientes();
                cout << "Los clientes son:" << endl;
                for (vector<string>::const_iterator it = nicknamesClientes.begin(); it != nicknamesClientes.end(); ++it) {
                    cout << "- " << *it << endl;
                }

                // Seleccionar cliente
                string nickname;
                cout << "Escriba el nombre del cliente que desea elegir: ";
                cin.ignore();
                getline(cin, nickname);
                controlCompra->seleccionarCliente(nickname);

                // Mostrar datos de productos
                vector<DTDatosProducto> datosProductos = controlPromocion->listarDataProductos();
                cout << "Los productos son: " << endl;
                for (vector<DTDatosProducto>::const_iterator it = datosProductos.begin(); it != datosProductos.end(); ++it) {
                    cout << it->getNombre() << " - Código: " << it->getCodigo() <<
                         " - Precio: " << it->getPrecio() << " - Stock: " << it->getStock() << endl;
                }

                // Agregar productos a la compra
                char agregarProducto;
                do {
                    cout << "¿Desea agregar un producto a la compra? (y/n): ";
                    cin >> agregarProducto;

                    if (agregarProducto == 'y') {
                        int codigo, cantidad;
                        cout << "Ingrese el código del producto que desea comprar: ";
                        cin >> codigo;
                        cout << "Ingrese la cantidad que desea comprar: ";
                        cin >> cantidad;

                        if (controlCompra->agregarCantidad(codigo, cantidad)) {
                            cout << "Producto agregado exitosamente." << endl;
                        } else {
                            cout << "No se pudo agregar el producto. Verifique el código y la cantidad." << endl;
                        }
                    }
                } while (agregarProducto == 'y');

                // Mostrar detalles de la compra
                cout << "Detalle de la compra: " << endl;
                DTDetallesCompra detallesCompra = controlCompra->verDetallesCompra();

                cout << detallesCompra.toString() << endl;

                // Confirmar compra
                char confirmar;
                cout << "Desea confirmar la compra? (y/n): ";
                cin >> confirmar;
                if (confirmar == 'y') {
                    if (controlCompra->confirmarCompra()) {
                        cout << "Compra realizada con éxito!" << endl;
                    } else {
                        cout << "ERROR: No se pudo realizar la compra." << endl;
                    }
                } else {
                    controlCompra->olvidarCompra();
                    cout << "Compra cancelada." << endl;
                }
            }
                break;

            case '2':
                break;

            default:
                cout << "Opcion invalida, intenta de nuevo" << endl;
        }

        cout << "Presiona enter para continuar..." << endl;
        cin.ignore();
        cin.get();
    } while (choice != '2');
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
                cout << "Ingresa el RUT (12 caracteres): ";
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

void enviarProductoHandler(IControlCompra* controlCompra, IControlUsuario* controlUsuario) {
    // Listar vendedores
    vector<string> nicknamesVendedores = controlUsuario->listarNicknamesVendedores();
    cout << "Los vendedores son:" << endl;
    for (vector<string>::iterator it = nicknamesVendedores.begin(); it != nicknamesVendedores.end(); ++it) {
        cout << "- " << *it << endl;
    }

    // Seleccionar vendedor
    string nickVendedor;
    cout << "Escriba el nombre del vendedor que desea elegir: ";
    cin >> nickVendedor;

    if (controlCompra->elegirVendedor(nickVendedor)) {
        cout << "Vendedor seleccionado exitosamente." << endl;
    } else {
        cout << "Error: No se pudo seleccionar el vendedor." << endl;
        return;
    }

    // Listar productos aptos del vendedor
    vector<DTProducto> productosAptos = controlCompra->listarProductosAptosDelVendedor();

    if (productosAptos.empty()) {
        cout << "No hay productos aptos para enviar de este vendedor." << endl;
    } else {
        cout << "Productos aptos para enviar:" << endl;
        for (vector<DTProducto>::iterator it = productosAptos.begin(); it != productosAptos.end(); ++it) {
            cout << it->toString() << endl;
        }
    }

    // Elegir producto
    int idProducto;
    cout << "Ingrese el ID del producto que desea enviar: ";
    cin >> idProducto;

    if (!controlCompra->elegirProducto(idProducto)) {
        cout << "Codigo invalido, intenta de nuevo." << endl;
        return;
    }

    // Listar compras del cliente
    vector<DTCompra> comprasCliente = controlCompra->listarComprasCliente();

    if (comprasCliente.empty()) {
        cout << "No hay compras pendientes de envío para este producto." << endl;
    } else {
        cout << "Compras pendientes de envío:" << endl;
        for (vector<DTCompra>::iterator it = comprasCliente.begin(); it != comprasCliente.end(); ++it) {
            cout << "ID: " << it->getId() << ", Cliente: " << it->getNicknameCliente()
                 << ", Fecha: " << it->getFechaCompra().getString() << endl;
        }

        // Marcar como enviado
        int codigoEnvio;
        cout << "Ingrese el ID de la compra que desea marcar como enviada: ";
        cin >> codigoEnvio;

        if (controlCompra->marcarComoEnviado(codigoEnvio)) {
            cout << "Producto marcado como enviado exitosamente." << endl;
        } else {
            cout << "Error: No se pudo marcar el producto como enviado. Verifique el ID ingresado." << endl;
        }
    }
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
                } else {
                    cout << "¿Quién escribirá el comentario? " << endl;
                    for(const auto& usuario : usuarios) {
                        cout << usuario << endl;
                    }
                    cin >> usuarioElegido;
                    controlComentario->seleccionarUsuario(usuarioElegido);

                    cout << "¿Sobre qué producto quieres comentar?" << endl;
                    vector<DTProducto> productos = controlPromocion->listarProductos();
                    if (productos.empty()){
                        cout << "Ups, parece que no tenemos productos, vuelve luego" << endl;
                        break;
                    } else {
                        for(const auto& prod : productos) {
                            cout << "Nombre: " << prod.getNombre() << endl;
                            cout << "ID: " << prod.getId() << endl;
                        }
                        cout << "Ingresa el ID del producto que quieras" << endl;
                        cin >> productoElegido;
                        controlComentario->seleccionarProducto(productoElegido);

                        cout << "¿Comentar sobre el producto o responder otro comentario?" << endl;
                        cout << "1. Comentar sobre el producto" << endl;
                        cout << "2. Responder un comentario" << endl;
                        cin >> alt;
                        switch (alt) {
                            case '1':{
                                cout << "Escribe el comentario:" << endl;
                                cin.ignore();
                                getline(cin, texto);
                                sinError = controlComentario->realizarComentario(texto);
                                if (sinError) {
                                    cout << "¡Comentario creado con éxito!" << endl;
                                } else {
                                    cout << "Hubo un error al crear el comentario." << endl;
                                }
                                break;
                            }
                            case '2':{
                                string comentarios = controlComentario->listarComentarios();
                                if (comentarios.empty()){
                                    cout << "Este producto no tiene comentarios actualmente" << endl;
                                    break;
                                } else {
                                    cout << "¿Qué comentario quieres responder?" << endl;
                                    cout << comentarios << endl;
                                    cin.ignore();
                                    getline(cin, comentarioElegido);
                                    sinError = controlComentario->elegirComentario(comentarioElegido);
                                    if (!sinError) {
                                        cout << "No se encontró el comentario, asegurate de haberlo escrito correctamente" << endl;
                                        break;
                                    }
                                    cout << "Escribe la respuesta:" << endl;
                                    getline(cin, texto);
                                    sinError = controlComentario->responderComentario(texto);
                                    if (sinError) {
                                        cout << "¡Comentario creado con éxito!" << endl;
                                    } else {
                                        cout << "Hubo un error al crear el comentario." << endl;
                                    }
                                    break;
                                }
                            }
                        }
                        break;
                    }
                }
            }
            case '2':{
                if (usuarios.empty()){
                    cout << "No hay usuarios cargados, Intenta cargar algunos antes" << endl;
                    break;
                } else {
                    cout << "Selecciona el usuario cuyo comentario quieres borrar:" << endl;
                    for(const auto& usuario : usuarios) {
                        cout << usuario << endl;
                    }
                    cin >> usuarioElegido;
                    controlComentario->seleccionarUsuario(usuarioElegido);

                    string comentarios = controlComentario->listarComentarios();
                    if (comentarios.empty()){
                        cout << "Este usuario no tiene comentarios por el momento" << endl;
                        break;
                    } else {
                        cout << "¿Qué comentario quieres eliminar?" << endl;
                        cout << comentarios << endl;
                        cin.ignore();
                        getline(cin, texto);
                        sinError = controlComentario->elegirComentario(texto);
                        if (!sinError) {
                            cout << "No se encontró el comentario, asegurate de haberlo escrito correctamente" << endl;
                            break;
                        }
                        sinError = controlComentario->eliminarComentario();
                        if (sinError) {
                            cout << "¡Comentario eliminado con éxito!" << endl;
                        } else {
                            cout << "Hubo un error al eliminar el comentario." << endl;
                        }
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
    int choice;

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
        cout << "6. Salir" << endl;
        cout << "7. Realizar Compra" << endl;
        cout << "8. Alta de Usuario" << endl;
        cout << "9. Listado de Usuarios" << endl;
        cout << "10. Alta de Producto" << endl;
        cout << "11. Consultar Producto" << endl;
        cout << "12. Expediente Usuario" << endl;
        cout << "13. Enviar producto" << endl;
        cout << "14. Comentarios" << endl;
        cout << "Ingresa tu opcion: ";
        cin >> choice;

        switch (choice) {
            case 1:
                fechaSistemaHandler(controlFecha);
                break;
            case 2:
                suscripcionesHandler(controlSuscripciones);
                break;
            case 3:
                usuarioHandler(controlUsuario);
                break;
            case 4:
                promocionesHandler(controlPromocion, controlUsuario);
                break;
            case 5:
                cargarDatosDePrueba(controlUsuario, controlSuscripciones, controlPromocion, controlCompra, controlFecha, controlComentario);
                break;
            case 6:
                cout << "Saliendo..." << endl;
                break;
            case 7:
                compraHandler(controlCompra, controlPromocion, controlUsuario);
                break;
            case 8:
                altaDeUsuario(controlUsuario);
                break;
            case 9:
                listadoDeUsuarios(controlUsuario);
                break;
            case 10:
                altaDeProducto(controlPromocion, controlUsuario);
                break;
            case 11:
                consultarProducto(controlPromocion);
                break;
            case 12:
                expedienteUsuario(controlUsuario);
                break;
            case 13:
                enviarProductoHandler(controlCompra, controlUsuario);
                break;
            case 14:
                ComentarioHandler(controlComentario, controlPromocion, controlUsuario, controlFecha);
                break;
            default:
                cout << "Opcion invalida, intenta de nuevo." << endl;
                break;
        }

        if (choice != 6) {
            cout << "Presiona enter para continuar..." << endl;
            cin.ignore();
            cin.get();
        }
    } while (choice != 6);

    return 0;
}


            