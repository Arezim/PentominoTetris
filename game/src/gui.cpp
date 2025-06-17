#include "raylib.h"
#include "raygui.h"

#include "gui.h"
#include "logic.h"
#include "initializer.h"
#include "pentomino.h"

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

void DrawGame()
{

    // Draw game GUI - game score and finish button
    ClearBackground(RAYWHITE);
    GuiLabel((Rectangle){10, 10, 200, 30}, TextFormat("Score: %d", g_score));

    GuiSetStyle(DEFAULT, TEXT_SIZE, 30);
    if (GuiButton((Rectangle){GetScreenWidth() - 210, 10, 200, 80}, "Finish Game"))
    {
        g_gameState = GAME_STATE_GAME_OVER;
    }

    // Draw the actual game board
    DrawBoard();
    DrawSmallBoard();
}

// Board dimensions expressed in terms of cells
static const int BoardWidth = 5;
static const int BoardHeight = 15;

// Cell dimensions in pixels
static const float CellWidth = 40.0f;
static const float CellHeight = 40.0f;

// 2D array representing the game board
static std::vector<std::vector<PentominoType>> gameBoard(BoardWidth, std::vector<PentominoType>(BoardHeight, PentominoType::NONE));

// The actual game board
void DrawBoard()
{
    // Calculate total board dimensions
    float totalBoardWidth = BoardWidth * CellWidth - BoardWidth;
    float totalBoardHeight = BoardHeight * CellHeight - BoardHeight;

    // Calculate starting position to center the board
    float startX = (GetScreenWidth() - totalBoardWidth) / 2.0f;
    float startY = (GetScreenHeight() - totalBoardHeight) / 2.0f;

    // Iterate through the board dimensions
    for (int row = 0; row < BoardWidth; row++)
    {
        for (int col = 0; col < BoardHeight; col++)
        {
            // Draw a rectangle for each cell in the board
            // I substract width from (width * CellWidth) and height from (height * CellHeight), because rectangle outline is drawn inside the rectangle. This small overlap ensures that the cells's outlines are not doubled.
            Rectangle cell = {startX + row * CellWidth - row, startY + col * CellHeight - col, CellWidth, CellHeight};
            
            // Get the color for the current cell based on its type
            Color cellColor = Pentomino::getColor(gameBoard[row][col]);

            DrawRectangleRec(cell, cellColor);
            // Draw a border around each cell
            DrawRectangleLinesEx(cell, 1.0f, DARKGRAY);
        }
    }
}

static const int SmallBoardWidth = 5;
static const int SmallBoardHeight = 5;

// This board displays the next pentomino piece
void DrawSmallBoard()
{
    float totalBoardWidth = SmallBoardWidth * CellWidth - SmallBoardWidth;
    float totalBoardHeight = SmallBoardHeight * CellHeight - SmallBoardHeight;

    float startX = (GetScreenWidth() * 3.0f - SmallBoardWidth * CellWidth ) / 4.0f;
    float startY = (GetScreenHeight() - SmallBoardHeight / 2.0f) * 1.0f / 4.0f;

    for (int width = 0; width < SmallBoardWidth; width++)
    {
        for (int height = 0; height < SmallBoardHeight; height++)
        {
            Rectangle cell = {startX + width * CellWidth - width, startY + height * CellHeight - height, CellWidth, CellHeight};
            DrawRectangleRec(cell, LIGHTGRAY);
            // Draw a border around each cell
            DrawRectangleLinesEx(cell, 1.0f, DARKGRAY);
        }
        
    }
}