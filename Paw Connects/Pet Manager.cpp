#include "Pet Manager.h"
#include "Pet.h"  
#include <string>
#include <iostream>
using namespace std;


PetManager::PetManager() {

}
void PetManager::AddPet(Pet* pet) {
	
	pets.push(pet);
}
void PetManager::DisplayPets() {
	for (int i=0;i<pets.size();i++)
	{
		pets[i]->displayInfo();

	}
}
Pet* PetManager::Search_by_id(int id) {
	for (int i = 0; i < pets.size(); i++) {
		if (pets[i]->getPetID() == id) {
			return pets[i];
		}
	}
	return nullptr;
}
int PetManager::GetPetCount() {
	return pets.size();
}
Dynamic_array<Pet*>& PetManager::getPets() {
	return pets;
}