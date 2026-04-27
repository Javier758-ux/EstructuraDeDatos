#pragma once
using namespace std;

typedef char DATA_TYPE;
class Nodo
{
public:
	DATA_TYPE data;
	Nodo* next;
	Nodo(DATA_TYPE d) : data(d), next(nullptr) {}
};

