#pragma once
#include <string>
using namespace std;
class Dato {
public:
    double Codigo;
    string Nombre;
    string Carrera;
    Dato() {
        Codigo = 0;
        Nombre = "Unknow";
        Carrera = "Unknow";
    }
};