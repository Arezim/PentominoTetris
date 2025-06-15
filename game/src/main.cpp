#include "raylib.h"

#define RAYGUI_IMPLEMENTATION
#include "raygui.h"

#include "raymath.h"

//---------------------------------
// Global Variables
//---------------------------------

static const int InitialWidth = 1920*0.5;
static const int InitialHeight = 1080*0.5;

// Button dimensions
static const float ButtonWidth = 300.0f;
static const float ButtonHeight = 100.0f;

void GameInit()
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

void GameDraw()
{
    BeginDrawing();

    GuiSetStyle(DEFAULT, TEXT_SIZE, 30);

    ClearBackground(DARKGRAY);
    // Display the button

    // center the button
    float buttonX = (GetScreenWidth() - ButtonWidth) / 2.0f;
    float buttonY = (GetScreenHeight() - ButtonHeight) / 2.0f;
    
    if(GuiButton((Rectangle){ buttonX, buttonY, ButtonWidth, ButtonHeight }, "Start Game"))
    {
        // Start the game logic here
    }
    EndDrawing();
}

int main()
{
    GameInit();
    
    while (!WindowShouldClose())
    {
        if (!GameUpdate())
            break;
        GameDraw();
    }
    GameCleanup();

    return 0;
}