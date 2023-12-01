#include "Nodo.h"

Nodo::Nodo()
{
    this->dato = 0;
    this->izq = nullptr;
    this->der = nullptr;
}

Nodo:: Nodo(Trabajador trabajador) {
    this->dato = trabajador.getOperatorId();
    this->izq = nullptr;
    this->der = nullptr;
}

int Nodo::getDato()
{
    if (this != nullptr) {
        return this->dato;
    }
    else {
        return 0;
    }
       
}

Nodo* Nodo::getDer()
{
    return this->der;
}

Nodo* Nodo::getIzq()
{
    return this->izq;
}

void Nodo::setDato(int dato)
{
    this->dato = dato;
}

void Nodo::setDer(Nodo* der)
{
    this->der = der;
}

void Nodo::setIzq(Nodo* izq)
{
    this->izq = izq;
}
