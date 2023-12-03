#include "Menu.h"
#include <vector>

Menu::Menu(AVL* avlInstancia, MaxHeap* maxheapInstancia, Archivos* archivoInstancia)
    : arbol(avlInstancia), maxheap(maxheapInstancia), archivo(archivoInstancia) {
}

string Menu::agregarEspacios(string palabra)
{
    string resultado;
    for (size_t i = 0; i < palabra.length(); ++i) {
        if (i > 0 && isupper(palabra[i]) && islower(palabra[i - 1])) {
            resultado += ' '; // Agrega un espacio
        }
        resultado += palabra[i]; // Agrega el carácter actual
    }
    return resultado;
}

void Menu::mostrarMenu()
{
   
    bool salir = false;
    int opcion;
    while (!salir) {
        
        cout << "--------------- MENU ---------------" << endl;
        cout << "[1] Agregar un evento de salud." << endl;
        cout << "[2] Atender un equipo." << endl;
        cout << "[3] Reportabilidad." << endl;
        cout << "[4] Salir." << endl;
        cout << "Ingrese una opcion: ";

        if (!(cin >> opcion)) {
            // Limpiar el estado de error de cin y descartar la entrada incorrecta
            cin.clear();
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
            cout << "Entrada no valida. Por favor, ingrese un numero." << endl;
            continue; // Volver al inicio del bucle
        }

        switch (opcion) {
        case 1:
            cout << "------- AGREGAR EVENTO SALUD -------" << endl;
            agregarEventoDeSalud();
            break;
        case 2:
            cout << "-------     ATENDER EQUIPO    -------" << endl;
            atenderUnEquipo();
            break;
        case 3:
            cout << "-------     REPORTABILIDAD    -------" << endl;

            cout << "OPERADORES AUSENTES EN EVENTOS DE SALUD: " << endl << endl;
            operadoresAusentes();
            break;
        case 4:

            arbol->eliminarArbol();
            maxheap->~MaxHeap();
            cout << "Saliendo del programa..." << endl;
            salir = true;
            break;
        default:
            cout << "Opcion no valida. Por favor, ingrese una opcion valida." << endl;
            break;
        }
    }
}

void Menu::agregarEventoDeSalud()
{
    bool agregar = false;
    while (!agregar) {

        int inID;
        string eleccion;

        string nombre;
        string ciudad;

        string idEquipo;
        string salud;
        float valorRegistro = 0.0;


        cout << "Ingrese el ID del operador: ";
        cin >> inID;

        if (arbol->buscarId(inID) == true && maxheap->existeId(inID) == true) {

            cout << "¡Ya existe un Evento de Salud asociado a este Operador! " << endl;
            agregar = true;
        }
        else if (arbol->buscarId(inID) == true && maxheap->existeId(inID) == false) {

            cout << "Ingrese el ID del equipo: ";
            cin >> idEquipo;
            cout << "Ingrese el evento de salud (Formato AaBbCc): ";
            cin >> salud;

            string eventoSalud = agregarEspacios(salud);
            if (eventoSalud == "Frame Torque Exceeded" || eventoSalud == "Negative High Peak Frame Bias" ||
                eventoSalud == "Negative High Peak Frame Pitch" || eventoSalud == "Negative High Peak Frame Rack" ||
                eventoSalud == "Positive High Peak Frame Bias" || eventoSalud == "Positive High Peak Frame Pitch" ||
                eventoSalud == "Positive High Peak Frame Rack" || eventoSalud == "Sprung Weight Exceeded") {
                cout << "evento valido " << endl;
            }
            else {
                cout << "evento INVALIIIIDO" << endl;
            }

        }
        else
        {
            cout << "¡Error! No existe el ID del operador." << endl;
            cout << "¿Desea agregar un operador? (SI/NO): ";
            cin >> eleccion;

            for (char& c : eleccion) {  // recorre cada caracter de ocpion y lo pone mayuscula con toupper
                c = toupper(c);
            }

            if (eleccion == "SI") {
                cout << "Ingrese el Nombre: ";
                cin >> nombre;
                cout << "Ingrese la Ciudad de residencia: ";
                cin >> ciudad;
                cout << "Ingrese el ID del equipo: ";
                cin >> idEquipo;
                cout << "Ingrese el evento de salud (Formato AaBbCc): ";
                cin >> salud;
                string eventoSalud = agregarEspacios(salud);
                if (eventoSalud == "Frame Torque Exceeded" || eventoSalud == "Negative High Peak Frame Bias" ||
                    eventoSalud == "Negative High Peak Frame Pitch" || eventoSalud == "Negative High Peak Frame Rack" ||
                    eventoSalud == "Positive High Peak Frame Bias" || eventoSalud == "Positive High Peak Frame Pitch" ||
                    eventoSalud == "Positive High Peak Frame Rack" || eventoSalud == "Sprung Weight Exceeded") {
                    while (valorRegistro <= 0)
                    {
                        cout << "Ingrese valor de registro: ";
                        cin >> valorRegistro;
                        if (valorRegistro <= 0) {
                            cout << "¡Error! Valor de registro invalido." << endl;
                        }
                    }
                    Trabajador nuevo(inID, nombre, ciudad);
                    Evento evento(idEquipo, inID, eventoSalud, valorRegistro);
                    arbol->insertar(nuevo);
                    maxheap->insert(evento);
                    agregar = true;
                }
                else {
                    cout << "evento INVALIIIIDO" << endl;
                    cout << eventoSalud << endl;
                    break;
                }
            }
            else if (eleccion == "NO") {}
        }
        agregar = true;
    }
}

void Menu::atenderUnEquipo()
{
    int id = maxheap->idRaiz();
    if (id > 0) {
        arbol->desplegarInformacion(id);
    }
    maxheap->eliminarRaiz();
}

void Menu::operadoresAusentes()
{
    vector<int> todasLasIdsAVL;
    arbol->obtenerTodasLasId(arbol->getRaiz(), todasLasIdsAVL);
    for (int id : todasLasIdsAVL) {
        bool existeEnMaxHeap = maxheap->existeId(id);

        if (!existeEnMaxHeap) {
        //    std::cout << "El ID " << id << " existe tanto en el AVL como en el MaxHeap." << std::endl;
        //}
       // else {
          //  std::cout << "El ID " << id << " no existe en el MaxHeap." << std::endl;
            arbol->buscarId(id);
            cout << endl;
        }
    }
}
