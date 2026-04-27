#include "ColaCircular.h"
#include "Nodo.h"
#include <iostream>
#include <string>
using namespace std;


ColaCircular::ColaCircular() : frente(nullptr), final(nullptr) {}

ColaCircular::~ColaCircular() {
    while (!estaVacia()) {
        desencolar();
    }
}

// Encola un nuevo elemento
void ColaCircular::encolar(const string& valor) {
    Nodo* nuevo = new Nodo(valor);

    if (!frente) {
        // Primer nodo: apunta a sí mismo
        frente = final = nuevo;
        nuevo->sig = nuevo;
    }
    else {
        nuevo->sig = frente;
        final->sig = nuevo;
        final = nuevo;
    }
}

// Desencola y devuelve el valor
string ColaCircular::desencolar() {
    if (estaVacia()) return "COLA VACÍA";

    string dato;
    if (frente == final) {
        // Solo un elemento
        dato = frente->valor;
        delete frente;
        frente = final = nullptr;
    }
    else {
        Nodo* temp = frente;
        dato = temp->valor;
        frente = frente->sig;
        final->sig = frente;
        delete temp;
    }
    return dato;
}

// ¿La cola está vacía?
bool ColaCircular::estaVacia() {
    return frente == nullptr;
}

// Mostrar elementos recorriendo la cola
void ColaCircular::mostrar() {
    if (estaVacia()) {
        cout << "Cola vacía.\n";
        return;
    }

    Nodo* actual = frente;
    cout << "Cola: ";
    do {
        cout << "[" << actual->valor << "] ";
        actual = actual->sig;
    } while (actual != frente);
    cout << endl;
}