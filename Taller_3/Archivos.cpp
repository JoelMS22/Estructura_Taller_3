#include "Archivos.h"

void Archivos::lecturaArchivos(AVL& avl, MaxHeap& maxheap) {
    // LECTURA 


    ifstream workers("workers.csv");
    ifstream minecare_events("minecare_events.csv");


    if (workers.is_open() && minecare_events.is_open()) {
        string line;

        // Set para almacenar los operatorId del primer archivo
        set<int> operatorIds;

        // Leer y almacenar operatorIds del primer archivo
        getline(workers, line); // Leer la primera l�nea del archivo de trabajadores
        while (getline(workers, line)) {

            stringstream lineStream(line);
            string operatorIdStr;
            string operatorName;
            string operatorCity;
            getline(lineStream, operatorIdStr, ';');
            int operatorId = stoi(operatorIdStr);
            operatorIds.insert(operatorId);
            cout << operatorId << endl;
            getline(lineStream, operatorName, ';');
            cout << operatorName << endl;
            getline(lineStream, operatorCity);
            cout << operatorCity << endl;
            Trabajador trabajador(operatorId, operatorName, operatorCity);
            avl.insertar(trabajador);
        }


        getline(minecare_events, line); // Leer la primera l�nea del archivo minecare_events
        while (getline(minecare_events, line)) {
            stringstream lineStream(line);
            string equipementID;
            string operatorIdStr;
            string event;
            string floatValueStr;

            getline(lineStream, equipementID, ';');
            getline(lineStream, operatorIdStr, ';');
            int operatorId = stoi(operatorIdStr);
            // Se verifica si el operatorId del segundo archivo est� en el conjunto del primer archivo
            if (operatorIds.find(operatorId) == operatorIds.end()) {

                continue; // Si no est�, se salta al siguiente ciclo sin leer esta l�nea
            }
            // Si est� en el conjunto, se lee la l�nea normalmente
            cout << equipementID << endl;
            cout << operatorId << endl;
            getline(lineStream, event, ';');
            cout << event << endl;

            getline(lineStream, floatValueStr, ';');
            float floatValue = stof(floatValueStr);
            maxheap.insert(floatValue);
            cout << floatValue << endl;
        }

        workers.close();
        minecare_events.close();


    }
    else {
        cout << "Hubo un error al abrir uno de los archivos." << endl;
    }

    maxheap.printHeap();
    avl.imprimirEnOrden();
    cout << "" << endl;
    avl.eliminarArbol();
    avl.imprimirEnOrden();
}