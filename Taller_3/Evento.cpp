#include "Evento.h"


Evento::Evento(string equipementID, int operatorId, string event, float floatValue) {

	this->equipementId = equipementID;
	this->operatorId = operatorId;
	this->event = event;
	this->floatValue = floatValue;

}

string Evento::getEquipementId()
{
	return this->equipementId;
}

int Evento::getOperatorId()
{
	return this->operatorId;
}

string Evento::getEvent()
{
	return this->event;
}

float Evento::getFloatValue() {
	return this->floatValue;
}