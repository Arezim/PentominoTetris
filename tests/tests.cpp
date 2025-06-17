#include "raylib.h"
#include "../game/include/pentomino.h"
#include <vector>
#include <iostream>

// Display constants
const float CELL_SIZE = 30.0f;
const float PENTOMINO_SPACING = 200.0f;
const int WINDOW_WIDTH = 1200;
const int WINDOW_HEIGHT = 800;

// Function to draw a single pentomino
void DrawPentomino(PentominoType type, float x, float y)
{
    auto shapeIt = pentominoShapes.find(type);
    if (shapeIt == pentominoShapes.end())
        return;

    const auto &shape = shapeIt->second;
    Color color = Pentomino::getColor(type);

    for (int row = 0; row < shape.size(); row++)
    {
        for (int col = 0; col < shape[row].size(); col++)
        {
            if (shape[row][col] != PentominoType::NONE)
            {
                Rectangle cell = {
                    x + col * CELL_SIZE - col,
                    y + row * CELL_SIZE - row,
                    CELL_SIZE,
                    CELL_SIZE};
                DrawRectangleRec(cell, color);
                DrawRectangleLinesEx(cell, 1.0f, BLACK);
            }
        }
    }
}

// Function to draw pentomino name
void DrawPentominoName(PentominoType type, float x, float y)
{
    const char *names[] = {"I", "X", "Z", "V", "T", "W", "U", "L", "N", "Y", "F", "P"};
    int index = static_cast<int>(type);
    if (index >= 0 && index < 12)
    {
        DrawText(names[index], x, y - 30, 20, BLACK);
    }
}

int main()
{
    InitWindow(WINDOW_WIDTH, WINDOW_HEIGHT, "Pentomino Tests - Display All Pentominos");
    SetTargetFPS(60);

    // List of all pentomino types for testing
    std::vector<PentominoType> allPentominos = {
        PentominoType::I, PentominoType::X, PentominoType::Z, PentominoType::V,
        PentominoType::T, PentominoType::W, PentominoType::U, PentominoType::L,
        PentominoType::N, PentominoType::Y, PentominoType::F, PentominoType::P};

    int currentPentomino = 0;
    bool showAll = false;
    float timer = 0.0f;
    const float AUTO_SWITCH_TIME = 2.0f; // Auto switch every 2 seconds

    while (!WindowShouldClose())
    {
        float deltaTime = GetFrameTime();
        timer += deltaTime;

        // Keyboard handling
        if (IsKeyPressed(KEY_RIGHT) || IsKeyPressed(KEY_SPACE))
        {
            currentPentomino = (currentPentomino + 1) % allPentominos.size();
            timer = 0.0f;
        }
        if (IsKeyPressed(KEY_LEFT))
        {
            currentPentomino = (currentPentomino - 1 + allPentominos.size()) % allPentominos.size();
            timer = 0.0f;
        }
        if (IsKeyPressed(KEY_A))
        {
            showAll = !showAll;
        }

        // Automatic pentomino switching
        if (timer >= AUTO_SWITCH_TIME && !showAll)
        {
            currentPentomino = (currentPentomino + 1) % allPentominos.size();
            timer = 0.0f;
        }

        BeginDrawing();
        ClearBackground(RAYWHITE);

        // Header
        DrawText("PENTOMINO TESTS", 10, 10, 30, DARKBLUE);
        DrawText("Arrows/Space: Change | A: Show all | ESC: Exit", 10, 50, 16, GRAY);

        if (showAll)
        {
            // Display all pentominos in a grid
            DrawText("ALL PENTOMINOS:", 10, 90, 20, BLACK);

            int cols = 4;
            float startX = 50;
            float startY = 130;

            for (int i = 0; i < allPentominos.size(); i++)
            {
                int row = i / cols;
                int col = i % cols;

                float x = startX + col * PENTOMINO_SPACING;
                float y = startY + row * 150;

                DrawPentominoName(allPentominos[i], x, y);
                DrawPentomino(allPentominos[i], x, y);

                // Highlight currently selected
                if (i == currentPentomino)
                {
                    DrawRectangleLinesEx({x - 10, y - 40, PENTOMINO_SPACING - 20, 140}, 3, RED);
                }
            }
        }
        else
        {
            // Display only current pentomino
            DrawText(TextFormat("PENTOMINO %d/%d:", currentPentomino + 1, (int)allPentominos.size()), 10, 90, 20, BLACK);

            float centerX = WINDOW_WIDTH / 2 - 100;
            float centerY = WINDOW_HEIGHT / 2 - 100;

            DrawPentominoName(allPentominos[currentPentomino], centerX, centerY);
            DrawPentomino(allPentominos[currentPentomino], centerX, centerY);

            // Auto-switch progress bar
            float progressWidth = 300;
            float progressHeight = 10;
            float progressX = (WINDOW_WIDTH - progressWidth) / 2;
            float progressY = WINDOW_HEIGHT - 100;

            DrawRectangle(progressX, progressY, progressWidth, progressHeight, LIGHTGRAY);
            DrawRectangle(progressX, progressY, (timer / AUTO_SWITCH_TIME) * progressWidth, progressHeight, GREEN);
            DrawRectangleLinesEx({progressX, progressY, progressWidth, progressHeight}, 1, BLACK);

            DrawText("Auto switch in:", progressX, progressY - 25, 16, BLACK);
            DrawText(TextFormat("%.1fs", AUTO_SWITCH_TIME - timer), progressX + progressWidth + 10, progressY - 5, 16, BLACK);
        }

        EndDrawing();
    }

    CloseWindow();
    return 0;
}