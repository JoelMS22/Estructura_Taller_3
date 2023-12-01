#pragma once
#include "Nodo.h"
#include "Trabajador.h"

class AVL
{
private:

	Nodo* raiz;
	int altura(Nodo* nodo);
	int obtenerBalance(Nodo* nodo);
	Nodo* insertar(Nodo* nodo, Trabajador trabajador);
	void inOrder(Nodo* nodo);

public:
	AVL();
	void insertar(Trabajador trabajador);
	void imprimirEnOrden();
	void desplegarArbol(Nodo* nodo, int espacio);
	Nodo* getRaiz();
	int getBalance(Nodo* nodo);
	int TotalNodos(Nodo* nodo);
	int TotalNodos();

	Nodo* rotacionSimpleDerecha(Nodo* nodo);
	Nodo* rotacionSimpleIzquierda(Nodo* nodo);
};

