#include "initializer.h"
#include "raylib.h"

#define RAYGUI_IMPLEMENTATION
#include "raygui.h"

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