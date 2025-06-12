#ifndef Staff_H
#define Staff_H
#include <iostream>
#include "User.h"
#include "Dynamic_array.h"
#include <string>
#include "Pets.h"
#include "Application.h"
#include "Adopter.h"
#include "raylib.h"
#include "Staff.h"
using namespace std;


class Staff: protected User
{
private:
	string department;
public:

	     Staff();
		 Staff(string n, string ema, string ID, string dept);
		 void display_menu(int& currentScreen);
		 void review_applications(Dynamic_array<Application*>& apps, int& currentScreen);
		 void update_pet_status(Pet* pet, bool is_Adopted);
		 void setDepartment(string dept);
	     string getDepartment();
};











#endif
