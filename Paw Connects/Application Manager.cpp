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
void ApplicationManager::savetoFile(const string& filename) {
    ofstream save(filename);
    if (!save.is_open()) {
        cerr << "Error opening file for writing.\n";
        return;
    }

    for (int i = 0; i < applications.size(); ++i) {
        Application* app = applications.at(i);
        save << app->getAppID() << " "
            << app->getPet()->getPetID() << " "
            << app->getAdopter()->getUserID() << " "
            << app->getStatus() << "\n";
    }

    save.close();

    save.close();
}
void ApplicationManager::loadfromFile(const string& filename, PetManager& petManager, Dynamic_array<Adopter*>& adopters) {
    ifstream inFile(filename);
    if (!inFile.is_open()) {
        cerr << "Error opening file for reading.\n";
        return;
    }

    int appID, petID;
    string adopterID, status;

    while (!inFile.eof()) {
        inFile >> appID >> petID >> adopterID >> status;
        if (inFile.fail()) break;
        Pet* pet = petManager.Search_by_id(petID);
        Adopter* adopter = nullptr;

        for (int i = 0; i < adopters.size(); ++i) {
            if (adopters[i]->getUserID() == adopterID) {
                adopter = adopters[i];
                break;
            }
        }

        if (pet != nullptr && adopter != nullptr) {
            Application* app = new Application(appID, pet, adopter, status);
            applications.push(app);
            
        }
    }

    inFile.close();
}
Application* ApplicationManager::getApplicationByID(int ID) {
	for (int i = 0; i < applications.size(); i++) {
		if (applications[i]->getAppID() == ID) {
			return applications[i];
		}
	}
	return nullptr;
}

