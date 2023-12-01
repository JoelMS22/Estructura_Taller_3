// Taller_3.cpp : Este archivo contiene la función "main". La ejecución del programa comienza y termina ahí.
//

#include <iostream>
#include "Nodo.h"
#include "AVL.h"
#include "Trabajador.h"
using namespace std;

int main()
{
    cout << "Hello World!\n" << endl;
    

    Trabajador j(2, "Joel", "Antofagasta");
    Trabajador jo(10, "Joel", "Antofagasta");
    Trabajador joe(94, "Joel", "Antofagasta");
    Trabajador joel(22, "Joel", "Antofagasta");
    Trabajador joelm(30, "Joel", "Antofagasta");
    Trabajador joelmo(17, "Joel", "Antofagasta");
    Trabajador joelmoy(18, "Joel", "Antofagasta");
    Trabajador joelmoya(19, "Joel", "Antofagasta");
    Trabajador joelmoyas(13, "Joel", "Antofagasta");
    Trabajador joelmoyaso(1, "Joel", "Antofagasta");
   
    joel.infoTrabajador();

    AVL arbol;
    
    arbol.insertar(j);
    arbol.insertar(jo);
    arbol.insertar(joe);
    arbol.insertar(joel);
    arbol.insertar(joelm);
    arbol.insertar(joelmo);
    arbol.insertar(joelmoy);
    arbol.insertar(joelmoya);
    arbol.insertar(joelmoyas);
    arbol.insertar(joelmoyaso);
    arbol.imprimirEnOrden();

    cout << "   \n";
    cout << "   \n";
    cout << "   \n";
    cout << "   \n";
    cout << "   \n";
    arbol.desplegarArbol(arbol.getRaiz(), 2);
    cout << arbol.TotalNodos();
    cout << "   \n";
    cout << "   \n";
    cout << "   \n";
    cout << "   \n";
    cout << "   \n";
  
}
