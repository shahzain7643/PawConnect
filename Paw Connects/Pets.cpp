#include <iostream>
#include "User.h"
#include "Dynamic_array.h"
#include <string>
#include "Pets.h"
using namespace std;


Pet::Pet() : petID{ 0 }, name{ "null" }, species{ "null" }, age{ 0 }, isadopted{false} {

}
Pet::Pet(int pid, string Name, string spec, int Age, bool adopted) : petID{ pid }, name{ Name }
, species{ spec }, age{ Age }, isadopted{ adopted }
{

}
void Pet::displayInfo() {
    cout << "Pet ID: " << petID << endl;
    cout << "Name: " << name << endl;
    cout << "Species: " << species << endl;
    cout << "Age: " << age << endl;
    cout << "Adoption Status: " << (isadopted ? "Adopted" : "Available") << endl;
}
void Pet::setPetID(int ID) {
    petID = ID;
}
void Pet::setName(string nme) {
    name = nme;
}
void Pet::setSpecies(string spec) {
    species = spec;
}
void Pet::setAge(int Age) {
    age = Age;
}
void Pet::setIsAdopted(bool flag) {
    isadopted = flag;
}
int Pet::getPetID() {
    return petID;
}
string Pet::getName() {
    return name;
}
string Pet::getSpecies() {
    return species;
}
int Pet::getAge() {
    return age;
}
bool Pet::getIsAdopted() {
    return isadopted;
}