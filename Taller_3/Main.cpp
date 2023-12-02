// Taller_3.cpp : Este archivo contiene la función "main". La ejecución del programa comienza y termina ahí.
//

#include <iostream>
#include "Nodo.h"
#include "AVL.h"
#include "Trabajador.h"
#include "Archivos.h"
#include "MaxHeap.h"
#include "Menu.h"
using namespace std;

int main()
{
    AVL arbol;
    MaxHeap maxheap;
    Archivos archivo;

    archivo.lecturaArchivos(arbol, maxheap);
    Menu* menu = new Menu(&arbol,&maxheap,&archivo);
    menu->mostrarMenu();
}
