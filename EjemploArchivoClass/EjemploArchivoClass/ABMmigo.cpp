#include "ABMmigo.h"
#include <iostream>
#include <fstream>

using namespace std;

ABMmigo::ABMmigo(const char nomArch[]) {

    int i = 0;

    while (nomArch[i] != '\0' && i < 49) {
        nomArchivo[i] = nomArch[i];
        i++;
    }

    nomArchivo[i] = '\0';
}

void ABMmigo::introducirDatos(Amigo& amig) {

    char nombre[50];
    int edad;
    char sexo;
    char fecha[15];

    cin.ignore();

    cout << "\nNombre: ";
    cin.getline(nombre, 50);

    cout << "Edad: ";
    cin >> edad;

    cout << "Sexo (M/F): ";
    cin >> sexo;

    cin.ignore();

    cout << "Fecha nacimiento (dd/mm/yyyy): ";
    cin.getline(fecha, 15);

    amig.setAmigo(nombre, edad, sexo, fecha);
}

void ABMmigo::alta() {

    ofstream fsalida(nomArchivo, ios::binary | ios::app);

    if (!fsalida) {

        cout << "\nError al abrir archivo\n";
        return;
    }

    Amigo amig;

    introducirDatos(amig);

    amig.guardarArchivo(fsalida);

    fsalida.close();

    cout << "\nRegistro guardado correctamente\n";
}

void ABMmigo::listar() {

    ifstream fentrada(nomArchivo, ios::binary);

    if (!fentrada) {

        cout << "\nNo existe el archivo\n";
        return;
    }

    Amigo amig;
    int nro = 1;

    cout << "\n===== LISTA DE AMIGOS =====\n";

    while (amig.leerArchivo(fentrada)) {

        if (amig.getEstado() == 'A') {

            cout << "\nRegistro: " << nro;
            cout << "\nNombre: " << amig.getNombre();
            cout << "\nEdad: " << amig.getEdad();
            cout << "\nSexo: " << amig.getSexo();
            cout << "\nFecha Nac.: " << amig.getFechaNacimiento();
            cout << "\n------------------------";
        }

        nro++;
    }

    fentrada.close();
}

void ABMmigo::consultar() {

    int nroReg;

    cout << "\nNumero de registro: ";
    cin >> nroReg;

    fstream fes(nomArchivo, ios::binary | ios::in);

    if (!fes) {

        cout << "\nError al abrir archivo\n";
        return;
    }

    Amigo amig;

    if (amig.buscar(fes, nroReg)) {

        if (amig.getEstado() == 'A') {

            cout << "\nNombre: " << amig.getNombre();
            cout << "\nEdad: " << amig.getEdad();
            cout << "\nSexo: " << amig.getSexo();
            cout << "\nFecha Nac.: " << amig.getFechaNacimiento();
        }
        else {

            cout << "\nRegistro eliminado";
        }
    }
    else {

        cout << "\nRegistro no encontrado";
    }

    fes.close();
}

void ABMmigo::baja() {

    int nroReg;

    cout << "\nNumero de registro a eliminar: ";
    cin >> nroReg;

    fstream fes(nomArchivo, ios::binary | ios::in | ios::out);

    if (!fes) {

        cout << "\nError al abrir archivo\n";
        return;
    }

    Amigo amig;

    if (amig.eliminar(fes, nroReg)) {

        cout << "\nRegistro eliminado correctamente";
    }
    else {

        cout << "\nNo se pudo eliminar";
    }

    fes.close();
}

void ABMmigo::actualizar() {

    int nroReg;

    cout << "\nNumero de registro a modificar: ";
    cin >> nroReg;

    fstream fes(nomArchivo, ios::binary | ios::in | ios::out);

    if (!fes) {

        cout << "\nError al abrir archivo\n";
        return;
    }

    Amigo amig;

    if (amig.buscar(fes, nroReg)) {

        if (amig.getEstado() == 'E') {

            cout << "\nEl registro esta eliminado";
        }
        else {

            introducirDatos(amig);

            amig.modificar(fes, nroReg);

            cout << "\nRegistro actualizado";
        }
    }
    else {

        cout << "\nRegistro no encontrado";
    }

    fes.close();
}