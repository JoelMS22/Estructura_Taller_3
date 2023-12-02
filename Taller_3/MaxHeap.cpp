#include "MaxHeap.h"
#include <iostream>
#include <vector>


MaxHeap::MaxHeap() {
    heap.push_back(0); // Primer elemento es 0
}

void MaxHeap::turnIntoMaxHeap(int index) {
    while (index > 1 && heap[index] > heap[index / 2]) {
        Swap(heap[index], heap[index / 2]);
        index = index / 2;
    }
}

void MaxHeap::Swap(float& a, float& b) {
    float aux = a;
    a = b;
    b = aux;
}

void MaxHeap::insert(float value) {
    heap.push_back(value);
    turnIntoMaxHeap(heap.size() - 1);
}

void MaxHeap::printHeap() {
    for (size_t i = 1; i < heap.size(); ++i) {
        std::cout << heap[i] << " ";
    }
    std::cout << std::endl;
}