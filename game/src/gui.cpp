#include "raylib.h"
#include "raygui.h"
#include "gui.h"
#include "logic.h"


void DrawGUI()
{
    BeginDrawing();

    switch (g_gameState)
    {
        case GAME_STATE_MENU:
            DrawMainMenu();
            break;

        case GAME_STATE_PLAYING:
            DrawGame();
            break;

        case GAME_STATE_PAUSED:
            // Game paused logic here
            break;

        case GAME_STATE_GAME_OVER:
            // Game over logic here
            break;
    }

    EndDrawing();
}

void DrawMainMenu()
{
    GuiSetStyle(DEFAULT, TEXT_SIZE, 30);

    ClearBackground(DARKGRAY);

    // Center the button
    float buttonX = (GetScreenWidth() - ButtonWidth) / 2.0f;
    float buttonY = (GetScreenHeight() - ButtonHeight) / 2.0f;
    
    if(GuiButton((Rectangle){ buttonX, buttonY, ButtonWidth, ButtonHeight }, "Start Game"))
    {
        StartGameLogic();
    }
}

void DrawGame()
{
    ClearBackground(RAYWHITE);

    // Game drawing logic here
    // For example, draw the game board, pieces, etc.
    
    // Example: Draw a simple score display
    GuiLabel((Rectangle){ 10, 10, 200, 30 }, TextFormat("Score: %d", g_score));
}