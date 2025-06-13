#ifndef APPLICATION_H
#define APPLICATION_H

#include <string>
using namespace std;

class Pet;       
class Adopter;   

class Application {
private:
    int aapID;
    Pet* pet;
    Adopter* adopter;
    string status;

public:
    Application();
    Application(int appID, Pet* pt, Adopter* adop, string stat);

    void updateStatus();
    void setAppID(int ID);
    void setStatus(string stat);

    int getAppID();
    string getStatus();
    Pet* getPet();
    Adopter* getAdopter();
};

#endif
