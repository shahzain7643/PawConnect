#ifndef ADOPTER_H
#define ADOPTER_H

#include "User.h"
#include "Dynamic_array.h"
#include <string>

class Pet;
class Application;

using namespace std;

class Adopter : public User
{
private:
    string phonenumber;
    Dynamic_array<Application*> Applications;

public:
    Adopter();
    Adopter(string n, string ema, string ID, string phonenum);

    void apply_for_application(Pet* pet);
    Dynamic_array<Application*>& getApplications();
    void setPhoneNum(string num);
};

#endif
