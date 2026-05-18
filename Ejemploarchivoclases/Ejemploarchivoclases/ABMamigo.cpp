#include "ABMamigo.h"
#include <iostream>
#include <fstream>
#include <string>
#include <limits>
using namespace std;
ABMamigo::ABMamigo(string nomArch) {
	nomArchivo = nomArch;
}
void ABMamigo::introducirDatos(Amigo* newReg) {
	string	nombre;
	int		edad;
	char	sexo;
	cout << endl << endl << "Introducir los siguientes datos --->>> :" << endl;
	fflush(stdin);
	cout << "Nombre : ";
	getline(cin, nombre);
	cout << "Edad : ";
	cin >> edad;
	cout << "Sexo <F/M>: ";
	cin >> sexo;
	newReg->setAmigo(nombre, edad, sexo);
}


void ABMamigo::mostrarRegistro(int nroReg) {
	cout << endl << nroReg << ".-  " << amig->getNombre() << "  " << amig->getEdad() << "  " << amig->getSexo() << "  " << amig->getEstado();

}
void ABMamigo::adicionarNuevo() {
	ofstream fsalida(nomArchivo, ios::app | ios::binary);
	amig = new Amigo();
	introducirDatos(amig);
	amig->guardarArchivo(fsalida);
	fsalida.close();
}

void ABMamigo::listar() {
	int cr = 0;
	cout << endl << endl << "Los registros son --->>> : " << endl;
	amig = new Amigo();
	ifstream fentrada(nomArchivo, ios::in | ios::binary);
	while (amig->leerArchivo(fentrada) == true) {
		cr++;
		if (amig->getEstado() == 'A') {
			mostrarRegistro(cr);
		}
	}
	fentrada.close();
}

int ABMamigo::buscarReg() {
	int nroReg;
	cout << endl << endl << "Introducir numero de registro a buscar :  ";
	cin >> nroReg;
	amig = new Amigo();
	ifstream fentrada(nomArchivo, ios::in | ios::binary);
	if (amig->buscar(fentrada, nroReg) == true) {
		mostrarRegistro(nroReg);
	}
	else {
		cout << endl << "Registro no existe";
		nroReg = -1;
	}
	fentrada.close();
	return(nroReg);
}

void ABMamigo::eliminarReg() {
	int nroReg;
	nroReg = buscarReg();
	if (nroReg > 0) {
		fstream fes(nomArchivo, ios::in | ios::out | ios::binary);
		amig = new Amigo();
		if (amig->eliminar(fes, nroReg) == true) {
			cout << endl << "Registro eliminado correctmente " << endl;
		}
		else {
			cout << endl << "Registro no existe pa eliminar" << endl;
		}
		fes.close();
	}
}

void ABMamigo::modificarReg() {
	int nroReg;
	nroReg = buscarReg();
	if (nroReg > 0) {
		fstream fes(nomArchivo, ios::in | ios::out | ios::binary);
		amig = new Amigo();
		introducirDatos(amig);
		if (amig->modificar(fes, nroReg) == true) {
			cout << endl << "modificado correctamente... " << endl;
		}
		else {
			cout << endl << "Registro no existe pa modificar";
		}
		fes.close();
	}
}