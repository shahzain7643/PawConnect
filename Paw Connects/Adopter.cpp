#include <iostream>
#include "User.h"
#include "Dynamic_array.h"
#include <string>
#include "Pets.h"
#include "Application.h"
#include "Adopter.h"
#include "raylib.h"
using namespace std;


Adopter::Adopter() :phonenumber("null") {

}
Adopter::Adopter(string n, string ema, string ID, string phonenum) : User(n, ema, ID), phonenumber{ phonenum } {

}
void  Adopter::display_menu() {
    const int screenWidth = 800;
    const int screenHeight = 450;

    InitWindow(screenWidth, screenHeight, "Adopter Menu - Paw Connects");
    SetTargetFPS(60);

    
    Rectangle applyBtn = { 300, 100, 200, 40 };
    Rectangle viewBtn = { 300, 160, 200, 40 };
    Rectangle phoneBtn = { 300, 220, 200, 40 };
    Rectangle exitBtn = { 300, 280, 200, 40 };

    while (!WindowShouldClose()) {
        Vector2 mousePoint = GetMousePosition();

        BeginDrawing();
        ClearBackground(RAYWHITE);

        DrawText("Adopter Menu", 290, 30, 30, DARKGRAY);

        
        DrawRectangleRec(applyBtn, CheckCollisionPointRec(mousePoint, applyBtn) ? LIGHTGRAY : GRAY);
        DrawText("Apply for Adoption", applyBtn.x + 20, applyBtn.y + 10, 20, BLACK);

        
        DrawRectangleRec(viewBtn, CheckCollisionPointRec(mousePoint, viewBtn) ? LIGHTGRAY : GRAY);
        DrawText("View Application", viewBtn.x + 25, viewBtn.y + 10, 20, BLACK);

        
        DrawRectangleRec(phoneBtn, CheckCollisionPointRec(mousePoint, phoneBtn) ? LIGHTGRAY : GRAY);
        DrawText("Update Phone", phoneBtn.x + 40, phoneBtn.y + 10, 20, BLACK);

        
        DrawRectangleRec(exitBtn, CheckCollisionPointRec(mousePoint, exitBtn) ? LIGHTGRAY : GRAY);
        DrawText("Exit", exitBtn.x + 80, exitBtn.y + 10, 20, BLACK);

        
        if (IsMouseButtonPressed(MOUSE_LEFT_BUTTON)) {
            if (CheckCollisionPointRec(mousePoint, applyBtn)) {
                cout << "Apply button clicked" << endl;
                
            }
            else if (CheckCollisionPointRec(mousePoint, viewBtn)) {
                cout << "View status clicked" << endl;
                view_application_status();
            }
            else if (CheckCollisionPointRec(mousePoint, phoneBtn)) {
                cout << "Update phone clicked" << endl;
                
            }
            else if (CheckCollisionPointRec(mousePoint, exitBtn)) {
                break;
            }
        }

        EndDrawing();
    }

    CloseWindow();
}
void Adopter::apply_for_application(Pet* pet) {  
    if (pet == nullptr) {
        cout << "Invalid pet selected."<<endl;
        return;
    }
    if (pet->getIsAdopted() ==true) {
        cout << "This pet is not available for adoption." << endl;
        return;
    }
    int appID = rand() % 10000 + 1;
    Application* newApp = new Application(appID, pet, this, "Pending");
    Applications.push(newApp); 
    pet->setIsAdopted("Pending");
    cout << "Adoption application submitted successfully."<<endl;
    const int screenWidth = 800;
    const int screenHeight = 450;

    InitWindow(screenWidth, screenHeight, "Application Status - Paw Connects");
    SetTargetFPS(60);

    while (!WindowShouldClose()) {
        BeginDrawing();
        ClearBackground(RAYWHITE);

        DrawText("Your Adoption Applications", 220, 20, 25, DARKGRAY);

        if (Applications.size() == 0) {
            DrawText("No applications submitted yet.", 250, 200, 20, RED);
        }
        else {
            int yStart = 80;
            for (int i = 0; i < Applications.size(); i++) {
                Application* app = Applications[i];

                string id = "ID: " + app->getAppID();
                string pet = "Pet: " + app->getPet()->getName();
                string status = "Status: " + app->getStatus();

                DrawText(id.c_str(), 100, yStart, 20, BLACK);
                DrawText(pet.c_str(), 300, yStart, 20, BLACK);
                DrawText(status.c_str(), 500, yStart, 20, BLACK);

                yStart += 40; 
            }
        }

        DrawText("Press ESC to go back", 580, 420, 15, GRAY);

        EndDrawing();
    }

    CloseWindow();
}
void Adopter::view_application_status(int& currentScreen) {
    BeginDrawing();
    ClearBackground(RAYWHITE);

    DrawText("Your Adoption Applications", 420, 30, 26, DARKGRAY);

    if (Applications.size() == 0) {
        DrawText("You have not submitted any applications.", 360, 100, 20, GRAY);
    }

    int startY = 100;

    for (int i = 0; i < Applications.size(); i++) {
        Application* app = Applications[i];
        Pet* pet = app->getPet();

        DrawRectangle(100, startY, 700, 110, LIGHTGRAY);
        DrawText(TextFormat("App ID: %d", app->getAppID()), 120, startY + 10, 20, BLACK);
        DrawText(TextFormat("Pet Name: %s", pet->getName().c_str()), 120, startY + 40, 20, BLACK);
        DrawText(TextFormat("Status: %s", app->getStatus().c_str()), 120, startY + 70, 20, BLACK);

        startY += 130;
    }

    
    Rectangle backBtn = { 30, 30, 100, 40 };
    DrawRectangleRec(backBtn, GRAY);
    DrawText("Back", backBtn.x + 20, backBtn.y + 10, 20, BLACK);

    if (CheckCollisionPointRec(GetMousePosition(), backBtn) && IsMouseButtonPressed(MOUSE_LEFT_BUTTON)) {
        currentScreen = 2; 
    }

    EndDrawing();
}
void Adopter::setPhoneNum(string num) {
    phonenumber = num;
}


