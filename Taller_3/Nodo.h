#pragma once
#include "Trabajador.h"


class Nodo
{
private:
	Nodo* izq;
	Nodo* der;
	int dato;
	Trabajador trabajador;


public:
	Nodo();
	Nodo(Trabajador trabajador);
	int getDato();
	Nodo* getDer();
	Nodo* getIzq();

	void setDato(int dato);
	void setDer(Nodo* der);
	void setIzq(Nodo* izq);
};

