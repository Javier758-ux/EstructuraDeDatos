#pragma once
#include <iostream>
#include <fstream>
#include <string>
#include "Amigo.h"

using namespace std;
class ABMamigo {
private:
	string  nomArchivo;
	Amigo* amig;

public:
	ABMamigo(string nomArch);
	void introducirDatos(Amigo* newReg);
	void mostrarRegistro(int nroReg);
	void adicionarNuevo();
	void listar();
	int buscarReg();
	void eliminarReg();

	void modificarReg();

};