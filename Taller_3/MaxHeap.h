#pragma once
#include <iostream>
#include <vector>
#include "Evento.h"

class MaxHeap {
private:

    vector<Evento*> heap; // Cambio de vector<Evento> a vector<Evento*>
    vector<int> contadores;
    void turnIntoMaxHeap(int index);
    void Swap(Evento*& a, Evento*& b); // Cambio de parámetros en Swap a punteros de Evento

public:
    MaxHeap();
    void insert(Evento evento);
    void eliminarRaiz();
    void printHeap();
    bool existeId(int operatorId);
    void infoRaiz();
    int idRaiz();
    float sumarFloatValues();
    int getSize();
    void llenarContadores();
    void getPorcentajeEventos();
    // Destructor para liberar la memoria de los objetos almacenados en el heap
    ~MaxHeap();
};