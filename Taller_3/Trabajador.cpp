#include "Trabajador.h"

Trabajador::Trabajador()
{
    this->operatorId = 0;
    this->operatorName = "";
    this->operatorCity = "";
}

Trabajador::Trabajador(int operatorId, string operatorName, string operatorCity)
{
    this->operatorId = operatorId;
    this->operatorName = operatorName;
    this->operatorCity = operatorCity;

}

int Trabajador::getOperatorId()
{
    return this->operatorId;
}

string Trabajador::getOperatorName()
{
    return this->operatorName;
}

string Trabajador::getOperatorCity()
{
    return this->operatorCity;
}

void Trabajador::infoTrabajador()
{
    cout << "Numero de identificacion del Operador: " << this->operatorId << endl
         << "Nombre del Operador: ";
         if (!this->operatorName.empty()) {
             // Convertir el primer carácter a mayúscula
             this->operatorName[0] = toupper(this->operatorName[0]);
             cout << this->operatorName;
         }
         cout << endl << "Ciudad del Operador: ";
         if (!this->operatorCity.empty()) {
             // Convertir el primer carácter a mayúscula
             this->operatorCity[0] = toupper(this->operatorCity[0]);
             cout << this->operatorCity << endl;
         }
}
