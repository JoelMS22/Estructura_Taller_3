#pragma once
#include <iostream>
#include <vector>
#include "Evento.h" // Asegúrate de incluir el archivo de encabezado de Eventos
using namespace std;
class MaxHeap {
private:
    vector<Evento> heap;

    void turnIntoMaxHeap(int index);
    void Swap(Evento& a, Evento& b);

public:
    MaxHeap();
    void insert(Evento value);
    void printHeap();
};