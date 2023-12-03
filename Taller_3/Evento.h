#pragma once
#include <iostream> 

using namespace std;
class Evento
{

private:
	string equipementId;
	int operatorId;
	string event;
	float floatValue;

public:

	Evento(string equipementId, int operatorId, string event, float floatValue);

	string getEquipementId();
	int getOperatorId();
	string getEvent();
	float getFloatValue();



};
