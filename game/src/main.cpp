#include "raylib.h"

#define RAYGUI_IMPLEMENTATION
#include "raygui.h"

#include "logic.h"
#include "gui.h"

//---------------------------------
// Global Variables
//---------------------------------

static const int InitialWidth = 1920*0.5;
static const int InitialHeight = 1080*0.5;

void InitGameWindow()
{
    SetConfigFlags(FLAG_VSYNC_HINT | FLAG_WINDOW_RESIZABLE);
    InitWindow(InitialWidth, InitialHeight, "Pentomino Tetris");
    SetTargetFPS(144);
    // load resources
}

void GameCleanup()
{
    // unload resources

    CloseWindow();
}

bool GameUpdate()
{
    return true;
}

int main()
{
    InitGameWindow();
    InitGameLogic();
    while (!WindowShouldClose())
    {
        DrawGUI();
    }
    GameCleanup();

    return 0;
}