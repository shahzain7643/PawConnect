#ifndef PETS_H
#define PETS_H

#include <string>
using namespace std;

class Pet
{
private:
    int petID;
    string name;
    string species;
    int age;
    bool isadopted;

public:
    Pet();
    Pet(int pid, string name, string spec, int age, bool adopted);

    void displayInfo();
    void setPetID(int ID);
    void setName(string name);
    void setSpecies(string spec);
    void setAge(int age);
    void setIsAdopted(bool flag);

    int getPetID();
    string getName();
    string getSpecies();
    int getAge();
    bool getIsAdopted();
};

#endif
