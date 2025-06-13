#include "Application.h"
#include "Pets.h"
#include "Adopter.h"
#include <iostream>
#include <string>
using namespace std;


Application::Application() : aapID{000}, pet{nullptr}, adopter{nullptr}, status{"null"} {

}
Application::Application(int appID, Pet* pt, Adopter* adop, string stat):aapID{ appID }, pet{ pt }, adopter{ adop }, status{ stat } {

}
void Application::updateStatus() {
    int choice;
    cout << "Set status: (1) Approve, (2) Reject: ";
    cin >> choice;

    if (choice == 1)
        status = "Approved";
    else if (choice == 2)
        status = "Rejected";
    else
        cout << "Invalid option."<<endl;
}
void Application::setAppID(int ID) {
	aapID = ID;
}
void Application::setStatus(string stat) {
	status = stat;
}
int Application::getAppID() {
	return aapID;
}
string Application::getStatus() {
	return status;
}
Pet* Application::getPet() {
	return pet;
}
Adopter* Application::getAdopter() {
	return adopter;
}
