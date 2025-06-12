#ifndef Pets_H
#define Pets_H
#include "User.h"
#include "Application.h"
#include "Dynamic_array.h"
#include "Staff.h"
#include "Adopter.h"
#include <string>
using namespace std;

class Pet
{
private:
	int petID;
	string name;
	string species;
	int age;
	bool isadopted;
public:
	Pet();
	Pet(int pid, string name, string spec, int age, bool adopted);
	void displayInfo();
	void setPetID(int ID);
	void setName(string name);
	void setSpecies(string spec);
	void setAge(int age);
	void setIsAdopted(bool flag);
	int getPetID();
	string getName();
	string getSpecies();
	int getAge();
	bool getIsAdopted();

};




#endif
