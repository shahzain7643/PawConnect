#include <iostream>
#include "User.h"
#include "Dynamic_array.h"
#include <string>
#include "Pet.h"
#include "Application.h"
#include "Adopter.h"
#include "raylib.h"
using namespace std;


Adopter::Adopter() :phonenumber("null") {

}
Adopter::Adopter(string n, string ema, string ID, string phonenum) : User(n, ema, ID), phonenumber{ phonenum } {

}
void Adopter::display_menu() {
 
}

void Adopter::apply_for_application(Pet* pet) {  
    if (pet == nullptr) {
        cout << "Invalid pet selected." << endl;
        return;
    }

    if (pet->getIsAdopted()) {
        cout << "This pet is not available for adoption." << endl;
        return;
    }

    int appID = rand() % 10000 + 1;   // for random application id
    Application* newApp = new Application(appID, pet, this, "Pending");
    Applications.push(newApp);
    pet->setIsAdopted(false); 
    

    cout << "Adoption application submitted successfully." << endl;
}
Dynamic_array<Application*>& Adopter::getApplications() {
    return Applications;
}
void Adopter::setPhoneNum(string num) {
    phonenumber = num;
}
string Adopter::getPhoneNUM() {
    return phonenumber;
}


