#include <iostream>
#include <string>

using namespace std;

void functionOne() {
    cout << "Function One" << endl;
}

void functionTwo() {
    cout << "Function Two" << endl;
}

void functionThree() {
    cout << "Function Three" << endl;
}

int main() {
    char choice;

    // aca irian todas las cosas que queremos inicializar si o si antes de ejecutar

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
                functionOne();
                break;
            case '2':
                functionTwo();
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