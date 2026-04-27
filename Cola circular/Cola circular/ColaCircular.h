#pragma once
#include <string>
#include "Nodo.h"

class ColaCircular
{
private:
    Nodo* frente;
    Nodo* final;

public:
    ColaCircular();
    ~ColaCircular();

    // Encola un nuevo elemento
    void encolar(const string& valor);
    // Desencola y devuelve el valor
    string desencolar();

    // ¿La cola está vacía?
    bool estaVacia();
    // Mostrar elementos recorriendo la cola
    void mostrar();
};

