#include <iostream>
#include "Cola.h"
using namespace std;

void mostrarMenu() {
    cout << "\n===== MENU COLA =====\n";
    cout << "1. Encolar elemento\n";
    cout << "2. Desencolar elemento\n";
    cout << "3. Ver frente\n";
    cout << "4. Ver cola completa\n";
    cout << "5. Verificar si esta vacia\n";
    cout << "6. Limpiar cola\n";
    cout << "7. Salir\n";
    cout << "Seleccione una opcion: ";
}

int main()
{
    Cola c;
    int opcion;
    int elemento;

    do {
        mostrarMenu();
        cin >> opcion;

        switch (opcion) {
        case 1:
            cout << "Ingrese elemento: ";
            cin >> elemento;
            if (c.Encolar(elemento))
                cout << "Elemento encolado correctamente\n";
            break;

        case 2:
            if (c.Desencolar())
                cout << "Elemento desencolado correctamente\n";
            break;

        case 3:
            if (c.VerFrente(elemento))
                cout << "Elemento al frente: " << elemento << endl;
            break;

        case 4:
            cout << "Elementos de la cola:\n";
            c.VerCola();
            break;

        case 5:
            if (c.ColaVacia())
                cout << "La cola esta vacia\n";
            else
                cout << "La cola NO esta vacia\n";
            break;

        case 6:
            c.LimpiarCola();
            cout << "Cola limpiada correctamente\n";
            break;

        case 7:
            cout << "Saliendo...\n";
            break;

        default:
            cout << "Opcion invalida\n";
        }

    } while (opcion != 7);

    return 0;
}