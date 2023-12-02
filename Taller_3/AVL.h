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
	bool buscarIdRec(Nodo* nodo, int id);
	void eliminarArbolRec(Nodo* nodo);

public:
	AVL();
	void insertar(Trabajador trabajador);
	void imprimirEnOrden();
	void desplegarArbol(Nodo* nodo, int espacio);
	Nodo* getRaiz();
	int getBalance(Nodo* nodo);
	int TotalNodos(Nodo* nodo);
	int TotalNodos();
	bool buscarId(int id);
	void eliminarArbol();


	Nodo* rotacionSimpleDerecha(Nodo* nodo);
	Nodo* rotacionSimpleIzquierda(Nodo* nodo);
};

