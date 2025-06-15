#include "raylib.h"
#include <iostream>
#include "User.h"
#include "Pet.h"
#include "Adopter.h"
#include "Staff.h"
#include "Logger.h"
#include "Application.h"
#include "Pet Manager.h"
#include "Application Manager.h"
using namespace std;




enum ScreenState {
    SCREEN_WELCOME,
    SCREEN_USER_SELECTION,
    SCREEN_ADOPTER_MENU,
    SCREEN_STAFF_MENU,
    SCREEN_VIEW_PETS,
    SCREEN_VIEW_PET_BY_ID,
    SCREEN_VIEW_APPLICATION_BY_ID,
    SCREEN_ADD_PET,
    SCREEN_APPLY_FOR_ADOPTION,
    SCREEN_VIEW_ALL_APPLICATIONS
};
int main() {
    PetManager petManager;
    Dynamic_array<Pet*>& pets = petManager.getPets();
    ApplicationManager appManager;
    Dynamic_array<Adopter*> adopters;


    petManager.AddPet(new Pet(101, "Buddy", "Dog", 3, false));
    petManager.AddPet(new Pet(102, "Whiskers", "Cat", 2, false));
    petManager.AddPet(new Pet(103, "Max", "Dog", 1, false));
    petManager.AddPet(new Pet(104, "Luna", "Cat", 4, false));
    petManager.AddPet(new Pet(105, "Coco", "Rabbit", 2, false));
    petManager.AddPet(new Pet(106, "Charlie", "Dog", 5, false));
    petManager.AddPet(new Pet(107, "Milo", "Parrot", 1, false));
    

    adopters.push(new Adopter("Ali Khan", "ali.khan@gmail.com", "A001", "03201234567"));
    adopters.push(new Adopter("Sara Ahmed", "sara.ahmed@yahoo.com", "A002", "03012345678"));
    adopters.push(new Adopter("Usman Javed", "usman.j@hotmail.com", "A003", "03123456789"));
    adopters.push(new Adopter("Mariam Raza", "mariam.raza@gmail.com", "A004", "03456789123"));
    adopters.push(new Adopter("Bilal Tariq", "bilal.tariq@gmail.com", "A005", "03332111222"));
    adopters.push(new Adopter("Fatima Noor", "fatima.noor@gmail.com", "A006", "03214567890"));
    adopters.push(new Adopter("Ahmad Zubair", "ahmad.z@gmail.com", "A007", "03098765432"));
    

    appManager.loadfromFile("applications.txt", petManager, adopters);
    const int screenWidth = 1000;
    const int screenHeight = 600;

    InitWindow(screenWidth, screenHeight, "PawConnects");
    SetTargetFPS(60);

    Texture2D bgTexture = LoadTexture("pet_background.jpg.jpeg");
    ScreenState currentScreen = SCREEN_WELCOME;


    Adopter testAdopter("Ali", "ali@email.com", "A001", "03001234567");


    char idInput[10] = "";
    char nameInput[20] = "";
    char speciesInput[20] = "";
    char ageInput[5] = "";
    int selectedPetID = -1;
    int selectedAppID = -1;
    string petInfoMessage = "";
    string appInfoMessage = "";
    string applyMessage = "";
    string addPetMessage = "";

    while (!WindowShouldClose()) {
        BeginDrawing();
        ClearBackground(RAYWHITE);

        if (currentScreen == SCREEN_WELCOME) {
            DrawTexture(bgTexture, screenWidth / 2 - bgTexture.width / 2, screenHeight / 2 - bgTexture.height / 2, WHITE);
            DrawText("PawConnects", 350, 40, 50, DARKGRAY);
            DrawText("Press ENTER to continue...", 320, 500, 20, GRAY);
            if (IsKeyPressed(KEY_ENTER)) {
                currentScreen = SCREEN_USER_SELECTION;
            }
        }
        else if (currentScreen == SCREEN_USER_SELECTION) {
            DrawText("Select User Type", 360, 100, 40, BLACK);
            Rectangle adopterBtn = { 350, 200, 300, 60 };
            Rectangle staffBtn = { 350, 300, 300, 60 };
            DrawRectangleRec(adopterBtn, LIGHTGRAY);
            DrawText("Continue as Adopter", 390, 220, 20, BLACK);
            DrawRectangleRec(staffBtn, LIGHTGRAY);
            DrawText("Continue as Staff", 400, 320, 20, BLACK);
            if (IsMouseButtonPressed(MOUSE_LEFT_BUTTON)) {
                Vector2 mouse = GetMousePosition();
                if (CheckCollisionPointRec(mouse, adopterBtn)) currentScreen = SCREEN_ADOPTER_MENU;
                if (CheckCollisionPointRec(mouse, staffBtn)) currentScreen = SCREEN_STAFF_MENU;
            }
        }
        else if (currentScreen == SCREEN_ADOPTER_MENU) {
            DrawText("Adopter Menu", 400, 100, 30, DARKBLUE);

            Rectangle viewPetsBtn = { 350, 160, 300, 40 };
            Rectangle viewByIdBtn = { 350, 220, 300, 40 };
            Rectangle applyBtn = { 350, 280, 300, 40 };
            Rectangle backBtn = { 10, 10, 100, 40 };

            DrawRectangleRec(viewPetsBtn, LIGHTGRAY);
            DrawText("View Pets", 420, 170, 20, BLACK);

            DrawRectangleRec(viewByIdBtn, LIGHTGRAY);
            DrawText("View Pet by ID", 410, 230, 20, BLACK);

            DrawRectangleRec(applyBtn, LIGHTGRAY);
            DrawText("Apply for Adoption", 390, 290, 20, BLACK);

            DrawRectangleRec(backBtn, RED);
            DrawText("Back", 30, 20, 20, WHITE);

            if (IsMouseButtonPressed(MOUSE_LEFT_BUTTON)) {
                Vector2 mouse = GetMousePosition();
                if (CheckCollisionPointRec(mouse, viewPetsBtn)) {
                    currentScreen = SCREEN_VIEW_PETS;
                }
                if (CheckCollisionPointRec(mouse, viewByIdBtn)) {
                    currentScreen = SCREEN_VIEW_PET_BY_ID;
                }
                if (CheckCollisionPointRec(mouse, applyBtn)) {
                    currentScreen = SCREEN_APPLY_FOR_ADOPTION;
                }
                if (CheckCollisionPointRec(mouse, backBtn)) {
                    currentScreen = SCREEN_USER_SELECTION;
                }
            }
        }
        else if (currentScreen == SCREEN_STAFF_MENU) {
            DrawText("Staff Menu", 400, 100, 30, DARKGREEN);
            Rectangle viewPetsBtn = { 350, 160, 300, 40 };
            Rectangle viewAppByIdBtn = { 350, 220, 300, 40 };
            Rectangle addPetBtn = { 350, 280, 300, 40 };
            Rectangle viewAllAppsBtn = { 350, 340, 300, 40 };
            Rectangle backBtn = { 10, 10, 100, 40 };
            DrawRectangleRec(viewPetsBtn, LIGHTGRAY);
            DrawText("View Pets", 420, 170, 20, BLACK);
            DrawRectangleRec(viewAppByIdBtn, LIGHTGRAY);
            DrawText("View Application by ID", 370, 230, 20, BLACK);
            DrawRectangleRec(addPetBtn, LIGHTGRAY);
            DrawText("Add New Pet", 400, 290, 20, BLACK);
            DrawRectangleRec(viewAllAppsBtn, LIGHTGRAY);
            DrawText("View All Applications", 370, 350, 20, BLACK);
            DrawRectangleRec(backBtn, RED);
            DrawText("Back", 30, 20, 20, WHITE);
            if (IsMouseButtonPressed(MOUSE_LEFT_BUTTON)) {
                Vector2 mouse = GetMousePosition();
                if (CheckCollisionPointRec(mouse, viewPetsBtn)) currentScreen = SCREEN_VIEW_PETS;
                if (CheckCollisionPointRec(mouse, viewAppByIdBtn)) currentScreen = SCREEN_VIEW_APPLICATION_BY_ID;
                if (CheckCollisionPointRec(mouse, addPetBtn)) currentScreen = SCREEN_ADD_PET;
                if (CheckCollisionPointRec(mouse, viewAllAppsBtn)) currentScreen = SCREEN_VIEW_ALL_APPLICATIONS;
                if (CheckCollisionPointRec(mouse, backBtn)) currentScreen = SCREEN_USER_SELECTION;
            }
        }
        else if (currentScreen == SCREEN_VIEW_PETS) {
            DrawText("All Pets", 400, 20, 30, DARKGRAY);
            for (int i = 0; i < pets.size() && i < 10; i++) {
                string text = "ID: " + to_string(pets[i]->getPetID()) +
                    " | Name: " + pets[i]->getName() +
                    " | Species: " + pets[i]->getSpecies() +
                    " | Age: " + to_string(pets[i]->getAge());
                DrawText(text.c_str(), 100, 70 + i * 40, 20, BLACK);
            }
            DrawText("Press B to go back", 10, 10, 20, RED);
            if (IsKeyPressed(KEY_B)) {
                currentScreen = SCREEN_USER_SELECTION;
            }
        }
        else if (currentScreen == SCREEN_VIEW_PET_BY_ID) {
            DrawText("Enter Pet ID:", 350, 150, 20, BLACK);
            DrawText(idInput, 350, 180, 20, DARKGRAY);
            DrawText("Press ENTER to Search", 350, 210, 20, GRAY);
            DrawText("Press B to go back", 10, 10, 20, RED);

            int key = GetCharPressed();
            while (key > 0 && strlen(idInput) < 9) {
                if ((key >= 48 && key <= 57)) {
                    int len = strlen(idInput);
                    idInput[len] = (char)key;
                    idInput[len + 1] = '\0';
                }
                key = GetCharPressed();
            }

            if (IsKeyPressed(KEY_BACKSPACE)) {
                int len = strlen(idInput);
                if (len > 0) {
                    idInput[len - 1] = '\0';
                }
            }

            if (IsKeyPressed(KEY_ENTER)) {
                selectedPetID = atoi(idInput);
                Pet* pet = petManager.Search_by_id(selectedPetID);
                if (pet != nullptr) {
                    petInfoMessage = "Pet Found: " + pet->getName() + ", Age: " + to_string(pet->getAge());
                }
                else {
                    petInfoMessage = "Pet not found.";
                }
            }

            DrawText(petInfoMessage.c_str(), 300, 250, 20, DARKGREEN);

            if (IsKeyPressed(KEY_B)) {
                idInput[0] = '\0';
                petInfoMessage = "";
                currentScreen = SCREEN_ADOPTER_MENU;
            }
        }
        else if (currentScreen == SCREEN_VIEW_APPLICATION_BY_ID) {
            DrawText("Enter Application ID:", 320, 150, 20, BLACK);
            DrawText(idInput, 320, 180, 20, DARKGRAY);
            DrawText("Press ENTER to Search", 320, 210, 20, GRAY);
            DrawText("Press B to go back", 10, 10, 20, RED);

            int key = GetCharPressed();
            while (key > 0 && strlen(idInput) < 9) {
                if ((key >= 48 && key <= 57)) {
                    int len = strlen(idInput);
                    idInput[len] = (char)key;
                    idInput[len + 1] = '\0';
                }
                key = GetCharPressed();
            }

            if (IsKeyPressed(KEY_BACKSPACE)) {
                int len = strlen(idInput);
                if (len > 0) {
                    idInput[len - 1] = '\0';
                }
            }

            if (IsKeyPressed(KEY_ENTER)) {
                selectedAppID = atoi(idInput);
                Application* app = appManager.getApplicationByID(selectedAppID);
                if (app != nullptr) {
                    appInfoMessage = "Application Found | Status: " + app->getStatus();
                }
                else {
                    appInfoMessage = "Application not found.";
                }
            }

            DrawText(appInfoMessage.c_str(), 300, 250, 20, DARKGREEN);

            if (IsKeyPressed(KEY_B)) {
                idInput[0] = '\0';
                appInfoMessage = "";
                currentScreen = SCREEN_STAFF_MENU;
            }
        }
        else if (currentScreen == SCREEN_ADD_PET) {
            DrawText("Enter Pet Name:", 300, 100, 20, BLACK);
            DrawText(nameInput, 500, 100, 20, DARKGRAY);
            DrawText("Enter Species:", 300, 140, 20, BLACK);
            DrawText(speciesInput, 500, 140, 20, DARKGRAY);
            DrawText("Enter Age:", 300, 180, 20, BLACK);
            DrawText(ageInput, 500, 180, 20, DARKGRAY);
            DrawText("Press ENTER to Add", 300, 230, 20, GRAY);
            DrawText("Press B to go back", 10, 10, 20, RED);
            DrawText(addPetMessage.c_str(), 300, 270, 20, DARKGREEN);

            if (IsKeyPressed(KEY_ENTER)) {
                int newID = pets.size() + 116;
                int age = atoi(ageInput);

                if (strlen(nameInput) > 0 && strlen(speciesInput) > 0 && age > 0) {
                    petManager.AddPet(new Pet(newID, nameInput, speciesInput, age, false));
                    addPetMessage = "Pet Added Successfully!";
                    nameInput[0] = speciesInput[0] = ageInput[0] = '\0';
                }
                else {
                    addPetMessage = "Invalid input. Try again.";
                }
            }

            int key = GetCharPressed();
            while (key > 0) {
                if ((key >= 32 && key <= 125)) {
                    if (strlen(nameInput) < 19 && GetMouseY() < 120) {
                        int len = strlen(nameInput);
                        nameInput[len] = (char)key;
                        nameInput[len + 1] = '\0';
                    }
                    else if (strlen(speciesInput) < 19 && GetMouseY() < 160 && GetMouseY() > 120) {
                        int len = strlen(speciesInput);
                        speciesInput[len] = (char)key;
                        speciesInput[len + 1] = '\0';
                    }
                    else if (strlen(ageInput) < 4 && GetMouseY() > 160) {
                        int len = strlen(ageInput);
                        ageInput[len] = (char)key;
                        ageInput[len + 1] = '\0';
                    }
                }
                key = GetCharPressed();
            }

            if (IsKeyPressed(KEY_BACKSPACE)) {
                if (GetMouseY() < 120 && strlen(nameInput) > 0) {
                    nameInput[strlen(nameInput) - 1] = '\0';
                }
                else if (GetMouseY() < 160 && strlen(speciesInput) > 0) {
                    speciesInput[strlen(speciesInput) - 1] = '\0';
                }
                else if (GetMouseY() > 160 && strlen(ageInput) > 0) {
                    ageInput[strlen(ageInput) - 1] = '\0';
                }
            }

            if (IsKeyPressed(KEY_B)) {
                currentScreen = SCREEN_STAFF_MENU;
                addPetMessage = "";
                nameInput[0] = speciesInput[0] = ageInput[0] = '\0';
            }
        }
        else if (currentScreen == SCREEN_VIEW_ALL_APPLICATIONS) {
            DrawText("All Applications", 350, 20, 30, DARKGRAY);
            Dynamic_array<Application*>& applications = appManager.getAllApplications();

            for (int i = 0; i < applications.size() && i < 10; i++) {
                string text = "AppID: " + to_string(applications[i]->getAppID()) +
                    " | PetID: " + to_string(applications[i]->getPet()->getPetID()) +
                    " | Status: " + applications[i]->getStatus();
                DrawText(text.c_str(), 100, 70 + i * 40, 20, BLACK);
            }

            DrawText("Press B to go back", 10, 10, 20, RED);
            if (IsKeyPressed(KEY_B)) {
                currentScreen = SCREEN_STAFF_MENU;
            }
        }
        else if (currentScreen == SCREEN_APPLY_FOR_ADOPTION) {
            DrawText("Enter Pet ID to Apply for Adoption:", 300, 150, 20, BLACK);
            DrawText(idInput, 300, 180, 20, DARKGRAY);
            DrawText("Press ENTER to Apply", 300, 210, 20, GRAY);
            DrawText("Press B to go back", 10, 10, 20, RED);

            int key = GetCharPressed();
            while (key > 0 && strlen(idInput) < 9) {
                if ((key >= 48 && key <= 57)) {
                    int len = strlen(idInput);
                    idInput[len] = (char)key;
                    idInput[len + 1] = '\0';
                }
                key = GetCharPressed();
            }

            if (IsKeyPressed(KEY_BACKSPACE)) {
                int len = strlen(idInput);
                if (len > 0) {
                    idInput[len - 1] = '\0';
                }
            }

            if (IsKeyPressed(KEY_ENTER)) {
                selectedPetID = atoi(idInput);
                Pet* pet = petManager.Search_by_id(selectedPetID);
                if (pet != nullptr && !pet->getIsAdopted()) {
                    testAdopter.apply_for_application(pet);
                    applyMessage = "Application Submitted for Pet ID: " + to_string(selectedPetID);
                }
                else {
                    applyMessage = "Invalid Pet ID or Already Adopted.";
                }
            }

            DrawText(applyMessage.c_str(), 300, 250, 20, DARKGREEN);

            if (IsKeyPressed(KEY_B)) {
                idInput[0] = '\0';
                applyMessage = "";
                currentScreen = SCREEN_ADOPTER_MENU;
            }
        }

        EndDrawing();
    }

    UnloadTexture(bgTexture);
    for (int i = 0; i < pets.size(); i++) {
        delete pets[i];
    }
    for (int i = 0; i < adopters.size(); i++) {
        delete adopters[i];
    }
    CloseWindow();
    return 0;
}
