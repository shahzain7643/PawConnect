#ifndef Adopter_H
#define Adopter_H
#include "User.h"
#include "Application.h"
#include "Dynamic_array.h"
#include <string>
using namespace std;

class Adopter : protected User
{
private:
	string phonenumber;
	Dynamic_array<Application*> Applications;
public:




};




#endif