#pragma once
#include <iostream> 

using namespace std;
class Evento
{

private:
	string equipementID;
	int operatorId;
	string event;
	float floatValue;

public:

	Evento(string equipementID, int operatorId, string event, float floatValue);

	string getEquipementID();

	int getOperatorId();

	string getEvent();

	float getFloatValue();



};
