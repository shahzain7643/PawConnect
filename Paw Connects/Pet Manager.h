#ifndef PETMANAGER_H
#define PETMANAGER_H

#include "Dynamic_array.h"
using namespace std;

class Pet;  

class PetManager {
private:
    Dynamic_array<Pet*> pets;

public:
    PetManager();
    void AddPet(Pet* pet);
    void DisplayPets();
    Pet* Search_by_id(int id);
    int GetPetCount();
    Dynamic_array<Pet*>& getPets();
};

#endif

