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


Staff::Staff() :department{"null"} {

}
Staff::Staff(string n, string ema, string ID, string dept) : User(n, ema, ID), department{dept} {

}
void Staff::display_menu(int& currentScreen) {
    BeginDrawing();
    ClearBackground(RAYWHITE);

    DrawText("Staff Menu", 520, 80, 32, DARKGRAY);

    Rectangle reviewAppsBtn = { 500, 200, 280, 50 };
    Rectangle logoutBtn = { 500, 270, 280, 50 };

    DrawRectangleRec(reviewAppsBtn, LIGHTGRAY);
    DrawText("Review Applications", reviewAppsBtn.x + 20, reviewAppsBtn.y + 15, 20, BLACK);

    DrawRectangleRec(logoutBtn, LIGHTGRAY);
    DrawText("Logout", logoutBtn.x + 20, logoutBtn.y + 15, 20, BLACK);

    if (CheckCollisionPointRec(GetMousePosition(), reviewAppsBtn) && IsMouseButtonPressed(MOUSE_LEFT_BUTTON)) {
        currentScreen = 4;  
    }

    if (CheckCollisionPointRec(GetMousePosition(), logoutBtn) && IsMouseButtonPressed(MOUSE_LEFT_BUTTON)) {
        currentScreen = 1;  
    }

    EndDrawing();
}
void Staff::review_applications(Dynamic_array<Application*>& apps, int& currentScreen) {
	BeginDrawing();
	ClearBackground(RAYWHITE);
	DrawText("Review Apllication", 480, 40, 32, DARKBLUE);

	int startY = 100;
	int spacing = 160;
	
	
	for (int i=0;i<apps.size();i++)
	{
		Application* app = apps[i];
		Pet* pet = app->getPet();
		Adopter* adopter = app->getAdopter();
		DrawText(TextFormat("App ID: %d", app->getAppID()), 100, startY, 20, BLACK);
		DrawText(TextFormat("Pet: %s", pet->getName().c_str()), 100, startY + 30, 20, BLACK);
        DrawText(TextFormat("Adopter: %s", adopter->getname().c_str()), 100, startY + 60, 20, BLACK);
		DrawText(TextFormat("Status: %s", app->getStatus().c_str()), 100, startY + 90, 20, BLACK);


        Rectangle approveBtn = { 600, startY + 30, 120, 30 };
        Rectangle rejectBtn = { 740, startY + 30, 120, 30 };

        DrawRectangleRec(approveBtn, GREEN);
        DrawText("Approve", approveBtn.x + 15, approveBtn.y + 5, 20, BLACK);

        DrawRectangleRec(rejectBtn, RED);
        DrawText("Reject", rejectBtn.x + 20, rejectBtn.y + 5, 20, BLACK);

        if (CheckCollisionPointRec(GetMousePosition(), approveBtn) && IsMouseButtonPressed(MOUSE_LEFT_BUTTON)) {
            app->setStatus("Approved");
            update_pet_status(pet, true);
        }

        if (CheckCollisionPointRec(GetMousePosition(), rejectBtn) && IsMouseButtonPressed(MOUSE_LEFT_BUTTON)) {
            app->setStatus("Rejected");
        }

        startY += spacing;
    }

    
    Rectangle backBtn = { 30, 30, 100, 40 };
    DrawRectangleRec(backBtn, GRAY);
    DrawText("Back", backBtn.x + 20, backBtn.y + 10, 20, BLACK);

    if (CheckCollisionPointRec(GetMousePosition(), backBtn) && IsMouseButtonPressed(MOUSE_LEFT_BUTTON)) {
        currentScreen = 3; 
    }

    EndDrawing();
	
}
void Staff::update_pet_status(Pet* pet, bool is_Adopted) {
    if (pet != nullptr) {
        pet->setIsAdopted(is_Adopted);
    }
}
void Staff::setDepartment(string dept) {
	department = dept;
}
string Staff::getDepartment() {
	return department;
}


