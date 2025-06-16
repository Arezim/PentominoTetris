#include "initializer.h"
#include "logic.h"
#include "gui.h"

#include "raylib.h"

//---------------------------------
// Global Variables
//---------------------------------

bool exitWindow()
{
    return WindowShouldClose() || g_gameState == GAME_STATE_EXIT;
}

int main()
{
    InitGameWindow();
    InitGameLogic();
    while (!exitWindow())
    {
        DrawGUI();
    }
    GameCleanup();

    return 0;
}