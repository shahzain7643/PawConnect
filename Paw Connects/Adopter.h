#ifndef Adopter_H
#define Adopter_H
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

class Adopter : public User
{
private:
	string phonenumber;
	Dynamic_array<Application*> Applications;
public:
	Adopter();
	Adopter(string n, string ema, string ID, string phonenum);
	void  display_menu();
	void apply_for_application(Pet* pet) ;
	void view_application_status(int& currentScreen) ;
	void setPhoneNum(string num) ;




};




#endif