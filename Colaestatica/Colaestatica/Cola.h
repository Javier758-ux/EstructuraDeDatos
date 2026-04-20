#pragma once
#define MAX 100

class Cola
{
private:
    int cola[MAX];
    int frente;
    int final;

public:
    Cola();
    bool Encolar(int& elemento);
    bool Desencolar();
    bool VerFrente(int& elemento);
    void LimpiarCola();
    void VerCola();
    bool ColaVacia();
};