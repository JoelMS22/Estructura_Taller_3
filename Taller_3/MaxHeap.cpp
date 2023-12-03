#include "MaxHeap.h"
#include <iostream>

MaxHeap::MaxHeap() {
    heap.push_back(nullptr); // Primer elemento es nullptr
}

void MaxHeap::turnIntoMaxHeap(int index) {
    while (index > 1 && heap[index]->getFloatValue() > heap[index / 2]->getFloatValue()) {
        Swap(heap[index], heap[index / 2]);
        index = index / 2;
    }
}

void MaxHeap::Swap(Evento*& a, Evento*& b) {
    Evento* aux = a;
    a = b;
    b = aux;
}

void MaxHeap::insert(Evento evento) {
    if (heap.size() == 1) {
        Evento* nuevoEvento = new Evento(evento);
        heap.push_back(nuevoEvento);// Almacenar un nuevo objeto Evento en el heap como puntero
        return;
    }
    Evento* nuevoEvento = new Evento(evento);
    // Insertar el puntero al nuevo Evento en el heap
    heap.push_back(nuevoEvento);
    // Ajustar la estructura del Max Heap después de insertar el nuevo elemento
    turnIntoMaxHeap(heap.size() - 1);
}

void MaxHeap::eliminarRaiz() {
    if (heap.size() <= 1) {
        std::cout << "No hay equipos que hayan registrado eventos de salud." << endl;
        return;
    } 
    infoRaiz();
    delete heap[1]; // Liberar memoria del objeto en la raíz antes de reemplazarlo
    heap[1] = heap[heap.size() - 1];
    heap.pop_back();

    int index = 1;
    while (true) {
        int leftChild = 2 * index;
        int rightChild = 2 * index + 1;
        int largest = index;

        if (leftChild < heap.size() && heap[leftChild]->getFloatValue() > heap[index]->getFloatValue()) {
            largest = leftChild;
        }

        if (rightChild < heap.size() && heap[rightChild]->getFloatValue() > heap[largest]->getFloatValue()) {
            largest = rightChild;
        }

        if (largest == index) {
            break;
        }

        Swap(heap[index], heap[largest]);
        index = largest;
    }
}

void MaxHeap::printHeap() {
    for (size_t i = 1; i < heap.size(); ++i) {
        std::cout << heap[i]->getFloatValue() << " ";
    }
}

bool MaxHeap::existeId(int operatorId) {
    for (size_t i = 1; i < heap.size(); ++i) {
        if (heap[i]->getOperatorId() == operatorId) {
            return true;

        }

    }
    return false;

    cout << "llegue aqui" << endl;

}

void MaxHeap::infoRaiz()
{
    cout << "Numero de identificacion del Equipo: " << heap[1]->getEquipementId() << endl
        << "Nombre del Evento de salud: " << heap[1]->getEvent() << endl 
        << "Valor de registro del Evento: "  << heap[1]->getFloatValue() << endl;
}

int MaxHeap::idRaiz()
{
    if (heap.size() <= 1 || heap[1] == nullptr) {
        return 0;
    }
    else {
        return this->heap[1]->getOperatorId();
    }
}

MaxHeap::~MaxHeap() {
    // Liberar la memoria de todos los objetos Evento almacenados en el heap
    for (size_t i = 1; i < heap.size(); ++i) {
        delete heap[i];
    }
    // Liberar el vector que contiene punteros
    heap.clear();
}