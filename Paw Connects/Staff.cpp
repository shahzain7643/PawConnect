#include "Staff.h"
#include "Application.h"
#include "Pets.h"
#include <iostream>
#include <string>
using namespace std;



Staff::Staff() :department{"null"} {

}
Staff::Staff(string n, string ema, string ID, string dept) : User(n, ema, ID), department{dept} {

}
void Staff::review_application(Application* app, bool approve) {
    if(approve) {
        app->setStatus("Approved");
        update_pet_status(app->getPet(), true);
    }
 else {
     app->setStatus("Rejected");
    }
}
void Staff::update_pet_status(Pet* pet, bool is_Adopted) {
    if (pet != nullptr) {
        pet->setIsAdopted(is_Adopted);
    }

}




void Staff::setDepartment(string dept) {
	department = dept;
}
string Staff::getDepartment() {
	return department;
}


