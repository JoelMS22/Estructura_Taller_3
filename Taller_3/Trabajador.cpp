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
     cout << "Numero de identificacion del Operador: " << this->getOperatorId() << endl
            << "Nombre del Operador: " << this->getOperatorName() << endl
                 << "Ciudad del Operador: " << this->getOperatorCity() << endl << endl;
    
}
