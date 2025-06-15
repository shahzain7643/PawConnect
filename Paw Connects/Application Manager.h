#ifndef Manager_H
#define Manager_H

#include <string>
#include "Dynamic_array.h"
#include "Pet Manager.h"
#include "Adopter.h"

using namespace std;

class Application;

class  ApplicationManager
{
private:
	Dynamic_array<Application*> applications;
public:
	ApplicationManager();
	void submitApplication(Application* app);
	void viewApplications();
	void savetoFile(const string& filename);
	void loadfromFile(const string& filename, PetManager& petManager, Dynamic_array<Adopter*>& adopters);
	Application* getApplicationByID(int ID);

};


#endif