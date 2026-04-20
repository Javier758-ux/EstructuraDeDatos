//clase Main
#include <iostream> 
#include "Nodo.h"
#include "Dato.h"//Se incluye a la clase Nodo
using namespace std;
void Encolar(Nodo*& inicio, Nodo*& fin) { //Punteros enviados por referencia      
    Nodo* Elemento = new Nodo; //Creacion del nodo      
    if (inicio == NULL) {

        inicio = fin = Elemento; //Le asigno la direccion del primer nodo          
        cout << "ID: "; cin >> Elemento->dato.ID;
        cout << "Tipo de musica: "; cin >> Elemento->dato.lista;
        cin.ignore();
        cout << "Nombre de la mùsica: "; getline(cin, Elemento->dato.Nombre);
        cout << "Nombre del artista: "; getline(cin, Elemento->dato.artista);
        cout << "Fecha: "; getline(cin, Elemento->dato.lanzamiento);


    }
    else {

        fin->puntero = Elemento; //Asigno el puntero del anterior elemento al nuevo

        fin = Elemento; //Cambio la direccion del ultimo nodo creado 

        cout << "ID: "; cin >> Elemento->dato.ID;
        cout << "Tipo de musica: "; cin >> Elemento->dato.lista;
        cin.ignore();
        cout << "Nombre de la musica: ";getline( cin, Elemento->dato.Nombre);
        cout << "Nombre del artista "; getline(cin, Elemento->dato.artista);
        cout << "Fecha: "; getline(cin, Elemento->dato.lanzamiento); cout << endl;

    }

}
    void Desencolar(Nodo * &inicio, Nodo * &fin) {
        if (inicio != NULL) {
            Nodo* temp = inicio;

            cout << "ID: " << inicio->dato.ID << endl;
            cout << "Tipo de musica: " << inicio->dato.lista << endl;
            cout << "Nombre de la musica: " << inicio->dato.Nombre << endl;
            cout << "Nombre del artista: " << inicio->dato.artista << endl;
            cout << "Fecha: " << inicio->dato.lanzamiento << endl;

            inicio = inicio->puntero;

            if (inicio == NULL) {
                fin = NULL;
            }

            delete temp;
        }
        else {
            cout << "La cola se encuentra vacia" << endl;
        }
    }
    int main(int argc, char* argv[]) {
    Nodo* inicio = NULL, * fin = NULL; //Punteros libres para el manejo de la cola
    int opc = 0, respuesta = 0;
    do {
        cout << "1. LA Lista ESTA VACIA?" << endl;
        cout << "2. Enlistar" << endl;
        cout << "3. Deslistar" << endl;
        cout << "4. FINALIZAR" << endl;
        cout << "Opcion: "; cin >> opc;


        switch (opc) {
        case 1:
            if (inicio == NULL)
                cout << "La lista se encuentra vacia" << endl;
            else
                cout << "Existe elemento(s) dentro de la cola" << endl;
            break;
        case 2:
            Encolar(inicio, fin);
            break;
        case 3:
            Desencolar(inicio, fin);
            break;

        }

    } while (opc != 4);


    return 0;
}