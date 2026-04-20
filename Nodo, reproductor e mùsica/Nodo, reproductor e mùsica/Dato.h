#pragma once
#include <string>
using namespace std;
class Dato {
public:
    string lista;
    string Nombre;
    double ID;
    string lanzamiento;
    string artista ;
    Dato() {
        lista = "Unknow";
        Nombre = "Unknow";
        ID = 0;
        lanzamiento = "Unknow";
        artista = "Unknow";
    }
};