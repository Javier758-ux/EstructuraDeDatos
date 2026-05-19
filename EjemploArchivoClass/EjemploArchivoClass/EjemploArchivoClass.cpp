#include <iostream>
#include "ABMmigo.h"

using namespace std;

int main() {

    ABMmigo sistema("amigos.dat");
    int opcion;

    do {
        cout << "\n========= MENU =========";
        cout << "\n1. Alta / Registrar";
        cout << "\n2. Baja / Eliminar";
        cout << "\n3. Modificar / Actualizar";
        cout << "\n4. Listar";
        cout << "\n5. Consultar / Buscar";
        cout << "\n0. Salir";
        cout << "\nSeleccione opcion: ";
        cin >> opcion;

        switch (opcion) {

        case 1:
            sistema.alta();
            break;

        case 2:
            sistema.baja();
            break;

        case 3:
            sistema.actualizar();
            break;

        case 4:
            sistema.listar();
            break;

        case 5:
            sistema.consultar();
            break;

        case 0:
            cout << "\nFin del programa\n";
            break;

        default:
            cout << "\nOpcion invalida\n";
        }

    } while (opcion != 0);

    return 0;
}