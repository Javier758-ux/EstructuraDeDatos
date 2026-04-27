#include "QueueDin.h"
#include <iostream>
#include "Nodo.h"

using namespace std;

QueueDin::QueueDin() : cola(nullptr), cabeza(nullptr), ITEMS(0), ITEMSIZE(sizeof(DATA_TYPE)) {}

// destructor (libera memoria)
QueueDin::~QueueDin() {
    while (!empty()) {
        get();
    }
}

/* agregar componente a la lista */
DATA_TYPE QueueDin::put(DATA_TYPE valor)
{
    Nodo* temp = new Nodo(valor);

    if (temp == nullptr) return '\0';

    ITEMS++;

    if (cabeza == nullptr)
    {
        cabeza = temp;
        cola = temp;
    }
    else
    {
        cola->next = temp;
        cola = temp;
    }
    return valor;
}

// regresa 1 (true) si la lista está vacia
int QueueDin::empty() {
    return ITEMS == 0;
}

/* retirar elemento de la lista */
DATA_TYPE QueueDin::get()
{
    if (empty()) return '\0';

    Nodo* temp = cabeza;
    DATA_TYPE d = cabeza->data;

    cabeza = cabeza->next;
    delete temp;

    ITEMS--;

    return d;
}