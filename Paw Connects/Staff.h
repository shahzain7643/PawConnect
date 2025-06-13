#ifndef STAFF_H
#define STAFF_H

#include <string>
#include "User.h"
#include "Dynamic_array.h"

class Pet;
class Application;

using namespace std;

class Staff : public User {
private:
    string department;

public:
    Staff();
    Staff(string n, string ema, string ID, string dept);

    void review_application(Application* app, bool approve);
    void update_pet_status(Pet* pet, bool is_Adopted);
    void setDepartment(string dept);
    string getDepartment();
};

#endif
