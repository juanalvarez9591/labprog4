#include <iostream>
#include <string>
#include "Factory.h"
#include "IControlUsuario.h"
#include "DTFecha.h"
using namespace std;

void functionOne(IControlUsuario* controlador) {
    cout << "Dar de alta cliente" << endl;
    controlador->darDeAltaCliente("nickname", "password", DTFecha(1, 1, 2000), "direccion", "ciudad");
}

void functionTwo(IControlUsuario* controlador) {
    cout << "Listar usuarios" << endl;
    vector<string> nicknames = controlador->listarNicknamesUsuarios();
    for (auto it = nicknames.begin(); it != nicknames.end(); it++) {
        cout << *it << endl;
    }
}

void functionThree() {
    cout << "Function Three" << endl;
}

int main() {
    char choice;

    // aca irian todas las cosas que queremos inicializar si o si antes de ejecutar

    Factory *factory = new Factory();
    IControlUsuario *controlador = factory->getControlUsuario();

    do {
        // A partir de aca sumariamos funciones para mas opciones digamos
        system("clear");
        cout << "Mercado Finger - Equipo 72" << endl;
        cout << "1. Function One" << endl;
        cout << "2. Function Two" << endl;
        cout << "3. Function Three" << endl;
        cout << "4. Exit" << endl;
        cout << "Enter your choice: ";
        cin >> choice;

        switch (choice) {
            case '1':
                functionOne(controlador);
                break;
            case '2':
                functionTwo(controlador);
                break;
            case '3':
                functionThree();
                break;
            case '4':
                cout << "Saliendo..." << endl;
                break;
            default:
                cout << "Opcion invalida, intente de nuevo" << endl;
        }

        cout << "Presiona enter para continuar..." << endl;
        cin.ignore();
        cin.get();
    } while (choice != '4');

    return 0;
}