#include "AVL.h"
#include <iostream>
using namespace std;

int AVL::altura(Nodo* nodo)
{
    if (nodo == nullptr) {
        return 0;
    }
    int izqAltura = altura(nodo->getIzq());
    int derAltura = altura(nodo->getDer());
    return 1 + ((izqAltura > derAltura) ? izqAltura : derAltura);
}

int AVL::obtenerBalance(Nodo* nodo)
{
    if (nodo == nullptr) {
        return 0;
    }
    return altura(nodo->getIzq()) - altura(nodo->getDer());
}

Nodo* AVL::insertar(Nodo* nodo, Trabajador trabajador) // insertar, con recursiones, en el main siempre se usara el otro, donde se comienza siempre desde la raiz
{
    if (nodo == nullptr) {
        return new Nodo(trabajador);
    }

    if (trabajador.getOperatorId() < nodo->getDato()) {
        Nodo* nuevoIzq = insertar(nodo->getIzq(), trabajador);
        nodo->setIzq(nuevoIzq);
    }
    else if (trabajador.getOperatorId() > nodo->getDato()) {
        Nodo* nuevoDer = insertar(nodo->getDer(), trabajador);
        nodo->setDer(nuevoDer);
    }
    else {
        return nodo;
    }

    int balance = obtenerBalance(nodo); //Balance del nodo actual
    if (balance > 1 && trabajador.getOperatorId() < nodo->getIzq()->getDato()) {//El balance en NodoActual es 2 (o +) (lo que quiere decir que hay un desbalanceo a la iquierda. Ademas el dato a ingresar es menor que el dato del hijo izquierdo
        return rotacionSimpleDerecha(nodo);      
    }
    if (balance < -1 && trabajador.getOperatorId() > nodo->getDer()->getDato()) {// El balance en NodoActual es -2 (o -) (lo que dice que existe desbalance hacia der. Ademas el dato a ingresar es mayor que el dato del hijo derecho
        return rotacionSimpleIzquierda(nodo);
    }
    if (balance > 1 && trabajador.getOperatorId() > nodo->getIzq()->getDato()) { // El balance en NodoACtual es 2 (o +) (lo que dice que existe un desbalance hacia izq. Ademas el dato a ingresar es mayor que el dato del hijo izquierdo
        nodo->setIzq(rotacionSimpleIzquierda(nodo->getIzq())); //rotacion simple izquierda en hijo izquierdo, el resultado de la rotacion sera el hijo izquierdo del nodo
        return rotacionSimpleDerecha(nodo); //Doble rotacion, primero simple izquierda y despues simple derecha
    }
    if (balance < -1 && trabajador.getOperatorId() < nodo->getDer()->getDato()) {// El Balance en NodoActual es -2 (o -) (lo que dice que existe un desbalance hacia der. Ademas el dato a ingresar es menor que el dato del hijo derecho
        nodo->setDer(rotacionSimpleDerecha(nodo->getDer()));// rotacion simple derecha del hijo derecho, el resultado de la rotacion sera el hijo derecho del nodo
        return rotacionSimpleIzquierda(nodo); // Doble rotacion, primero simple derecha y luego simple izquierda
    }



    return nodo;
  
}

void AVL::inOrder(Nodo* nodo)
{
    if (nodo != nullptr) {
        inOrder(nodo->getIzq());
        cout << nodo->getDato() << "    ";
        inOrder(nodo->getDer());
    }
}

bool AVL::buscarIdRec(Nodo* nodo, int id)
{
    if (nodo == nullptr) {
        return false;
    }
    if (nodo->getDato() == id) {
        return true;
    }
    if (id < nodo->getDato()) {
        return buscarIdRec(nodo->getIzq(), id);
    }
    else
    {
        return buscarIdRec(nodo->getDer(), id);
    }

    return false;
}

void AVL::eliminarArbolRec(Nodo* nodo)
{
    if (nodo == nullptr) {
        return;
    }
    eliminarArbolRec(nodo->getIzq()); // Elimina el subárbol izquierdo
    eliminarArbolRec(nodo->getDer()); // Elimina el subárbol derecho

    delete nodo; // Elimina el nodo actual
}

AVL::AVL() : raiz(nullptr)
{
}

void AVL::insertar(Trabajador trabajador)// Metodo Insertar desde la raiz, se usara en main
{
    if (raiz != nullptr) {
        this->raiz = insertar(raiz, trabajador);
    }
    else {
        raiz = new Nodo(trabajador);
    }
        
}

void AVL::imprimirEnOrden()
{
    inOrder(raiz);
}

void AVL::desplegarArbol(Nodo* nodo, int espacio)
{
    if (nodo == nullptr) {
        return;
    }

    espacio += 2;
    desplegarArbol(nodo->getDer(), espacio);
    cout << endl;
    for (int i = 2; i < espacio; i++) {
        cout << "  ";
    }
    cout << nodo->getDato() << "\n";
    desplegarArbol(nodo->getIzq(), espacio);
}

Nodo* AVL::getRaiz()
{
    if (raiz == nullptr) {
        return nullptr;
    }
    return this->raiz;
}

int AVL::getBalance(Nodo* nodo)
{
    return obtenerBalance(nodo);
}

int AVL::TotalNodos(Nodo* nodo)
{
    if (nodo == nullptr) {
        return 0;
    }
    int NodosIzq = TotalNodos(nodo->getIzq());
    int NodosDer = TotalNodos(nodo->getDer());
    return 1 + NodosIzq + NodosDer;

}

int AVL::TotalNodos()
{
    if (this->raiz == nullptr) {
        return 0;
    }

    return TotalNodos(this->raiz);

}

bool AVL::buscarId(int id)
{
    return buscarIdRec(this->raiz,id);
}

void AVL::eliminarArbol()
{
    return eliminarArbolRec(this->raiz);
    raiz = nullptr;
}




Nodo* AVL::rotacionSimpleDerecha(Nodo* nodo)
{
    // Existe un desbalanceo hacia la izquierda, es por esto que se mueven hacia la derecha y por esto el nombre de la rotacion
    if (nodo == nullptr) {
        return nullptr;
    }
    Nodo* aux = nodo->getIzq();
    Nodo* subIzq = aux->getDer();

    aux->setDer(nodo);
    nodo->setIzq(subIzq);

    return aux;
}

Nodo* AVL::rotacionSimpleIzquierda(Nodo* nodo)
{
    // Existe un desbalanceo hacia la derecha, es por esto que se mueven hacia la izquierda y por esto el nombre de la rotacion
    if (nodo == nullptr) {
        return nullptr;
    }
    Nodo* aux = nodo->getDer();
    Nodo* subDer = aux->getIzq();

    aux->setIzq(nodo);
    nodo->setDer(subDer);
    
    return aux;
}

