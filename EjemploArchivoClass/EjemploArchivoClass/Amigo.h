#ifndef AMIGO_H
#define AMIGO_H

#include <iostream>
#include <fstream>

using namespace std;

class Amigo {

private:
    char nombre[50];
    int edad;
    char sexo;
    char fechaNacimiento[15];
    char estado;

public:
    Amigo();

    void setAmigo(const char nom[], int ed, char sx, const char fecha[]);

    const char* getNombre();
    int getEdad();
    char getSexo();
    const char* getFechaNacimiento();
    char getEstado();

    void guardarArchivo(ofstream& fsalida);
    bool leerArchivo(ifstream& fentrada);

    bool buscar(fstream& fes, int nroReg);
    bool eliminar(fstream& fes, int nroReg);
    bool modificar(fstream& fes, int nroReg);

    int getTamRegistro();
};

#endif