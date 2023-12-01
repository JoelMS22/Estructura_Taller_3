#pragma once
#include <iostream>
using namespace std;

class Trabajador
{

private:
	int operatorId;
	string operatorName;
	string operatorCity;
	

public:

	Trabajador();
	Trabajador(int operatorId, string operatorName, string operatorCity);
	int getOperatorId();
	string getOperatorName();
	string getOperatorCity();
	void infoTrabajador();

};

