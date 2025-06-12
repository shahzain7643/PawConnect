#include "raylib.h"

int main(void)
{
    // Initialization
    const int screenWidth = 1000;
    const int screenHeight = 450;

    InitWindow(screenWidth, screenHeight, "PawConnects");

    // Load the background image from project resources (placed in same folder or under Resource Files)
    Image bgImage = LoadImage("pet_background.jpg.jpeg"); // Load into RAM
    Texture2D bgTexture = LoadTextureFromImage(bgImage);  // Upload to VRAM

    UnloadImage(bgImage); // RAM copy no longer needed

    SetTargetFPS(60); // Run at 60 FPS

    // Main loop
    while (!WindowShouldClose()) // Runs until ESC or [X] clicked
    {
        BeginDrawing();
        ClearBackground(RAYWHITE); // Fills background color before drawing image

        // Draw background image centered
        DrawTexture(bgTexture, screenWidth / 2 - bgTexture.width / 2 , screenHeight / 2 - bgTexture.height / 2, WHITE);

        // Draw title and instruction
        DrawText("Welcome to PawConnects ", 100, 30, 24, DARKGRAY);
        DrawText("Press ENTER to continue", 260, 380, 20, GRAY);

        EndDrawing();
    }

    // De-initialize and cleanup
    UnloadTexture(bgTexture);
    CloseWindow();

    return 0;
}
