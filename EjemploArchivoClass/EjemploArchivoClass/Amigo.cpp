#include "Amigo.h"

Amigo::Amigo() {

    nombre[0] = '\0';
    edad = 0;
    sexo = ' ';
    fechaNacimiento[0] = '\0';
    estado = 'A';
}

void Amigo::setAmigo(const char nom[], int ed, char sx, const char fecha[]) {

    int i = 0;

    while (nom[i] != '\0' && i < 49) {
        nombre[i] = nom[i];
        i++;
    }

    nombre[i] = '\0';

    edad = ed;
    sexo = sx;

    i = 0;

    while (fecha[i] != '\0' && i < 14) {
        fechaNacimiento[i] = fecha[i];
        i++;
    }

    fechaNacimiento[i] = '\0';

    estado = 'A';
}

const char* Amigo::getNombre() {
    return nombre;
}

int Amigo::getEdad() {
    return edad;
}

char Amigo::getSexo() {
    return sexo;
}

const char* Amigo::getFechaNacimiento() {
    return fechaNacimiento;
}

char Amigo::getEstado() {
    return estado;
}

void Amigo::guardarArchivo(ofstream& fsalida) {

    fsalida.write(reinterpret_cast<char*>(this), sizeof(Amigo));
}

bool Amigo::leerArchivo(ifstream& fentrada) {

    fentrada.read(reinterpret_cast<char*>(this), sizeof(Amigo));

    return fentrada.good();
}

bool Amigo::buscar(fstream& fes, int nroReg) {

    fes.seekg((nroReg - 1) * sizeof(Amigo), ios::beg);

    fes.read(reinterpret_cast<char*>(this), sizeof(Amigo));

    return fes.good();
}

bool Amigo::eliminar(fstream& fes, int nroReg) {

    if (buscar(fes, nroReg)) {

        estado = 'E';

        fes.seekp((nroReg - 1) * sizeof(Amigo), ios::beg);

        fes.write(reinterpret_cast<char*>(this), sizeof(Amigo));

        return true;
    }

    return false;
}

bool Amigo::modificar(fstream& fes, int nroReg) {

    fes.seekp((nroReg - 1) * sizeof(Amigo), ios::beg);

    fes.write(reinterpret_cast<char*>(this), sizeof(Amigo));

    return fes.good();
}

int Amigo::getTamRegistro() {

    return sizeof(Amigo);
}