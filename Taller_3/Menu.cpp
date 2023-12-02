#include "Menu.h"

Menu::Menu(AVL* avlInstancia, MaxHeap* maxheapInstancia, Archivos* archivoInstancia)
    : arbol(avlInstancia), maxheap(maxheapInstancia), archivo(archivoInstancia) {
}

void Menu::mostrarMenu()
{
    int opcion;
    bool salir = false;

    while (!salir) {
        cout << "---------------------MENU-------------------------" << endl;
        cout << "[1] Agregar un evento de salud." << endl;
        cout << "[2] Atender un equipo." << endl;
        cout << "[3] Reportabilidad." << endl;
        cout << "[4] Salir." << endl;
        cout << "Ingrese una opcion: ";

        cin >> opcion;

        switch (opcion) {
        case 1:
            arbol->desplegarArbol(arbol->getRaiz(), 5);
            break;
        case 2:

            break;
        case 3:

            break;
        case 4:
            salir = true;
            arbol->eliminarArbol();
            cout << "Saliendo del programa..." << endl;
            break;
        default:
            cout << "Opción no válida. Por favor, ingrese una opción válida." << endl;
            break;
        }
    }
}

void Menu::agregarEventoDeSalud()
{

}
