#include <iostream>
#include <string>
#include "ColaCircular.h"

using namespace std;
int main() {
    ColaCircular cola;

    cola.encolar("Juan");
    cola.encolar("Maria");
    cola.encolar("Pedro");

    cola.mostrar();

    cout << "Atendiendo: " << cola.desencolar() << endl;
    cola.mostrar();

    cola.encolar("Luis");
    cola.mostrar();

    cout << "Atendiendo: " << cola.desencolar() << endl;
    cout << "Atendiendo: " << cola.desencolar() << endl;
    cola.mostrar();

    return 0;
}