#include <iostream>
#include <fstream>
#include "ABMamigo.h"

using namespace std;

int main() {
    ABMamigo* amig = new ABMamigo("amigOO.dat");
    int op;
    do
    {
        cout << endl << endl;
        cout << "===== MENU ABM AMIGOS =====" << endl;
        cout << "1. Alta - Registrar" << endl;
        cout << "2. Baja - Eliminar" << endl;
        cout << "3. Modificar archivo" << endl;
        cout << "4. Listar" << endl;
        cout << "5. Consultar o Buscar" << endl;
        cout << "6. Salir" << endl;
        cout << "Seleccione una opcion: ";
        cin >> op;
        switch (op)
        {
        case 1:
            cout << endl << "ALTA - REGISTRAR" << endl;
            amig->adicionarNuevo();
            break;
        case 2:
            cout << endl << "BAJA - ELIMINAR" << endl;
            amig->eliminarReg();
            break;
        case 3:
            cout << endl << "MODIFICAR ARCHIVO" << endl;
            amig->modificarReg();
            break;
        case 4:
            cout << endl << "LISTAR REGISTROS" << endl;
            amig->listar();
            break;
        case 5:
            cout << endl << "CONSULTAR O BUSCAR" << endl;
            amig->buscarReg();
            break;
        case 6:
            cout << endl << "Saliendo del programa..." << endl;
            break;
        default:
            cout << endl << "Opcion incorrecta. Intente nuevamente." << endl;
            break;
        }
    } while (op != 6);
    delete amig;
    return 0;
}