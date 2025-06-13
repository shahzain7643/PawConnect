#ifndef Manager_H
#define Manager_H

#include <string>
#include "Dynamic_array.h"
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
	void savetoFile();
	void loadfromFile();
	Application* getApplicationByID(int ID);

};


#endif