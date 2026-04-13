#pragma once
#include "Nodo.h"
using namespace std;
class Pila
{
	Nodo* inicio;
public:
	Pila() {
		inicio = NULL;
	}
	void push();
	void pop();
	void show();
	void top();
	void size();
};

