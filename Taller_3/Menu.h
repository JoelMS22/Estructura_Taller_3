#pragma once

#include "AVL.h"
#include "MaxHeap.h"
#include "Archivos.h"

class Menu {
private:
    AVL* arbol;
    MaxHeap* maxheap;
    Archivos* archivo;

public:
    // Constructor que acepta punteros a las instancias
    Menu(AVL* avlInstancia, MaxHeap* maxheapInstancia, Archivos* archivoInstancia);

    void mostrarMenu();
    void agregarEventoDeSalud();
    void atenderUnEquipo();
};
