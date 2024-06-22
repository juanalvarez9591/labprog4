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
using namespace std;

void cargarDatosDePrueba(IControlUsuario* controlUsuario, IControlSuscripciones* controlSuscripciones, IControlPromocion* controlPromocion) {
    controlUsuario->darDeAltaVendedor("vendedor1", "password1", DTFecha(1, 1, 1990), "123456789012");
    controlUsuario->darDeAltaVendedor("vendedor2", "password2", DTFecha(2, 2, 1991), "234567890123");
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
    cout << "Datos de prueba cargados exitosamente" << endl;
}

void promocionesHandler(IControlPromocion* controlPromocion, IControlUsuario* controlUsuario) {
    string choiceStr;
    int choice;
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
        cin >> choiceStr;

        try {
            choice = stoi(choiceStr);
        } catch (const std::invalid_argument& ia) {
            choice = 0;  // Invalid input
        }

        switch (choice) {
            case 1:
            {
                vector<string> nicknames = controlUsuario->listarNicknamesVendedores();
                cout << "Nicknames de vendedores:" << endl;
                for (const string& nickname : nicknames) {
                    cout << "- " << nickname << endl;
                }
            }
                break;
            case 2:
                cout << "Ingresa el nickname del vendedor: ";
                cin >> nickVendedor;
                if (controlPromocion->elegirVendedor(nickVendedor)) {
                    cout << "Vendedor elegido exitosamente" << endl;
                } else {
                    cout << "Error al elegir vendedor" << endl;
                }
                break;
            case 3:
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
            case 4:
            {
                vector<DTProducto> productos = controlPromocion->listarProductos();
                cout << "Productos disponibles:" << endl;
                for (const DTProducto& producto : productos) {
                    cout << "- " << producto.getNombre() << " (ID: " << producto.getId() << ")" << endl;
                }
            }
                break;
            case 5:
                cout << "Ingresa el ID del producto: ";
                cin >> idProducto;
                {
                    DTInfoProducto infoProducto = controlPromocion->verInfoProducto(idProducto);
                    cout << infoProducto.toString() << endl;
                }
                break;
            case 6:
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
            case 7:
            {
                vector<DTProducto> productos = controlPromocion->verProductosVendedorEnMemoria();
                cout << "Productos del vendedor:" << endl;
                for (const DTProducto& producto : productos) {
                    cout << "- " << producto.getNombre() << " (ID: " << producto.getId() << ")" << endl;
                }
            }
                break;
            case 8:
                cout << "Ingresa el ID del producto: ";
                cin >> idProducto;
                cout << "Ingresa la cantidad a agregar: ";
                cin >> cantidad;
                controlPromocion->agregarProductoPromocion(idProducto, cantidad);
                cout << "Producto agregado a la promocion exitosamente" << endl;
                break;
            case 9:
                controlPromocion->confirmarPromocion();
                cout << "Promocion confirmada exitosamente" << endl;
                break;
            case 10:
            {
                set<DTPromocion> promociones = controlPromocion->listarPromocionesVigentes();
                cout << "Promociones vigentes:" << endl;
                for (const DTPromocion& promocion : promociones) {
                    cout << "- " << promocion.getNombre() << " (Vencimiento: " << promocion.getFechaVencimiento().getString() << ")" << endl;
                }
            }
                break;
            case 11:
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
            case 12:
                cout << "Volviendo al menu principal..." << endl;
                break;
            default:
                cout << "Opcion invalida, intenta de nuevo" << endl;
        }

        if (choice != 12) {
            cout << "Presiona enter para continuar...";
            cin.ignore();
            cin.get();
        }
    } while (choice != 12);
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
                cin.ignore(); // Add this line to clear the input buffer
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
                DTDetallesCompra detallesCompra = controlCompra->verDetallesCompra();
                cout << "Detalle de la compra: " << endl;
                // Aquí deberías mostrar los detalles de la compra según la estructura de DTDetallesCompra

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
    string nickname, password, direccion, ciudad, rut;
    int dia, mes, anio;

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
                cout << "Ingresa el RUT (12 caracteres): ";
                cin >> rut;
                if (rut.length() != 12) {
                    cout << "El RUT debe tener exactamente 12 caracteres. Intenta de nuevo." << endl;
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
        cout << "6. Realizar Compra" << endl;
        cout << "7. Salir" << endl;
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
                promocionesHandler(controlPromocion, controlUsuario);
                break;
            case '5':
                cargarDatosDePrueba(controlUsuario, controlSuscripciones, controlPromocion);
                break;
            case '6':
                compraHandler( controlCompra, controlPromocion, controlUsuario);
                break;
            case '7':
                break;
            default:
                cout << "Opcion invalida, intenta de nuevo" << endl;
        }

        cout << "Presiona enter para continuar..." << endl;
        cin.ignore();
        cin.get();
    } while (choice != '7');

    return 0;
}
            
            