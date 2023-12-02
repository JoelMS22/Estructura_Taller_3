#include "Evento.h"


Evento::Evento(string equipementID, int operatorId, string event, float floatValue) {


	this->equipementID = equipementID;
	this->operatorId = operatorId;
	this->event = event;
	this->floatValue = floatValue;



}

float Evento::getFloatValue() {
	return this->floatValue;
}