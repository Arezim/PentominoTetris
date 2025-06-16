#include "raylib.h"
#include "raygui.h"
#include "gui.h"
#include "logic.h"
#include "initializer.h"

// "Start Game" Button dimensions
static const float ButtonWidth = 300.0f;
static const float ButtonHeight = 100.0f;

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
        break;

    case GAME_STATE_GAME_OVER:
        DrawGameOver();
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

    if (GuiButton((Rectangle){buttonX, buttonY, ButtonWidth, ButtonHeight}, "Start Game"))
    {
        StartGameLogic();
    }
}

void DrawGame()
{
    ClearBackground(RAYWHITE);
    GuiLabel((Rectangle){10, 10, 200, 30}, TextFormat("Score: %d", g_score));

    GuiSetStyle(DEFAULT, TEXT_SIZE, 30);
    if(GuiButton((Rectangle){GetScreenWidth() - 210, 10, 200, 80}, "Finish Game"))
    {
        g_gameState = GAME_STATE_GAME_OVER;
    }
}

void DrawGameOver()
{
    ClearBackground(DARKGRAY);

    GuiSetStyle(DEFAULT, TEXT_SIZE, 30);

    // Calculate total height of all buttons to center them as a group
    float totalButtonHeight = 3 * ButtonHeight + 2 * 10; // 3 buttons + 2 gaps
    float startY = (GetScreenHeight() - totalButtonHeight) / 2.0f;

    // Center the "Game Over" message above the buttons
    const char *gameOverText = "Game Over!";
    float textWidth = MeasureText(gameOverText, 30);
    float textX = (GetScreenWidth() - textWidth) / 2.0f;
    float textY = startY - 60; // 60 pixels ABOVE the first button

    DrawText(gameOverText, textX, textY, 30, RED);

    float buttonX = (GetScreenWidth() - ButtonWidth) / 2.0f;

    if (GuiButton((Rectangle){buttonX, startY, ButtonWidth, ButtonHeight}, "Main Menu"))
    {
        InitGameLogic();
    }
    if (GuiButton((Rectangle){buttonX, startY + ButtonHeight + 10, ButtonWidth, ButtonHeight}, "Restart Game"))
    {
        StartGameLogic();
    }
    if (GuiButton((Rectangle){buttonX, startY + 2 * (ButtonHeight + 10), ButtonWidth, ButtonHeight}, "Exit Game"))
    {
        ExitGameLogic();
    }
}