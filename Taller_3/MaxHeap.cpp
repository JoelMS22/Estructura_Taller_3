#include "MaxHeap.h"
#include <iostream>



MaxHeap::MaxHeap() {
    heap.push_back(Evento("", 0, "", 0)); // Primer elemento es un Eventos vacío (o con valores predeterminados)
}

void MaxHeap::turnIntoMaxHeap(int index) {
    while (index > 1 && heap[index].getFloatValue() > heap[index / 2].getFloatValue()) {
        Swap(heap[index], heap[index / 2]);
        index = index / 2;
    }
}

void MaxHeap::Swap(Evento& a, Evento& b) {
    Evento aux = a;
    a = b;
    b = aux;
}

void MaxHeap::insert(Evento value) {
    heap.push_back(value);
    turnIntoMaxHeap(heap.size() - 1);
}

void MaxHeap::printHeap() {
    for (size_t i = 1; i < heap.size(); ++i) {
        cout << heap[i].getFloatValue() << " ";
    }

}