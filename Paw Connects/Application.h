#ifndef Application_H
#define Application_H
#include <string>
#include <iostream>
#include "User.h"
#include "Dynamic_array.h"
#include "Pets.h"
#include "Application.h"
#include "Adopter.h"
#include "raylib.h"
#include "Staff.h"
using namespace std;

class Application
{
private:
	int aapID;
	Pet* pet;
	Adopter* adopter;
	string status;
public:
	Application();
	Application(int appID, Pet* pt, Adopter* adop, string stat);
	void updateStatus();
	void setAppID(int ID);
	void setStatus(string stat);
	int getAppID();
	string getStatus();
	Pet* getPet();
	Adopter* getAdopter();

};


#endif