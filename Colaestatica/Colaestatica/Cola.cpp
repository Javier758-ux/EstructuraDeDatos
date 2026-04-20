#include <iostream>
#include "Cola.h"
using namespace std;

Cola::Cola()
{
    frente = 0;
    final = -1;
}

bool Cola::ColaVacia()
{
    return final < frente;
}

bool Cola::Encolar(int& elemento)
{
    if (final == MAX - 1)
    {
        cout << "Overflow: cola llena" << endl;
        return false;
    }
    else
    {
        final++;
        cola[final] = elemento;
        return true;
    }
}

bool Cola::Desencolar()
{
    if (ColaVacia())
    {
        cout << "Underflow: cola vacia" << endl;
        return false;
    }
    else
    {
        frente++;
        return true;
    }
}

bool Cola::VerFrente(int& elemento)
{
    if (ColaVacia())
    {
        cout << "Cola vacia" << endl;
        return false;
    }
    else
    {
        elemento = cola[frente];
        return true;
    }
}

void Cola::VerCola()
{
    for (int i = frente; i <= final; i++)
        cout << cola[i] << endl;
}

void Cola::LimpiarCola()
{
    frente = 0;
    final = -1;
}