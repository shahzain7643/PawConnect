#include "Application Manager.h"
#include "Application.h"  
#include "Pet.h"
#include "Adopter.h"
#include "Pet Manager.h"
#include <string>
#include <fstream>
#include <cstring>
#include <iostream>
using namespace std;


ApplicationManager::ApplicationManager() {

}
void ApplicationManager::submitApplication(Application* app) {
	applications.push(app);
}
void ApplicationManager::viewApplications() {
	for (int i=0;i<applications.size();i++)
	{
		cout << "Application ID " << applications[i]->getAppID() << endl;
		cout << "Status " << applications[i]->getStatus() << endl;
	}
}
void ApplicationManager::savetoFile() {
    ofstream save("applications.dat", ios::binary);
    if (!save) {
        cout << "Failed to open file for writing."<<endl;
        return;
    }

    for (int i = 0; i < applications.size(); i++) {
        Application* app = applications[i];

        int appID = app->getAppID();
        int petID = app->getPet()->getPetID();
        string adopterID = app->getAdopter()->getUserID();  
        string status = app->getStatus();

        int adopterLen = adopterID.length();
        int statusLen = status.length();
        // Type casting to convert all data types to char
        save.write((char*)&appID, sizeof(appID));
        save.write((char*)&petID, sizeof(petID));

        save.write((char*)&adopterLen, sizeof(adopterLen));
        // used to convert string into char *
        save.write(adopterID.c_str(), adopterLen);

        save.write((char*)&statusLen, sizeof(statusLen));
        save.write(status.c_str(), statusLen);
    }

    save.close();
}
void ApplicationManager::loadfromFile() {
    
}
Application* ApplicationManager::getApplicationByID(int ID) {
	for (int i = 0; i < applications.size(); i++) {
		if (applications[i]->getAppID() == ID) {
			return applications[i];
		}
	}
	return nullptr;
}

