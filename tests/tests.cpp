#include "raylib.h"

int main() {
    // Your test code here
    InitWindow(800, 600, "Tests");
    
    while (!WindowShouldClose()) {
        BeginDrawing();
        ClearBackground(RAYWHITE);
        DrawText("Tests Running!", 190, 200, 20, LIGHTGRAY);
        EndDrawing();
    }
    
    CloseWindow();
    return 0;
}