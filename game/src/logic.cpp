#include "logic.h"
#include "raylib.h"

//---------------------------------
// Global Variables
//---------------------------------
GameState g_gameState;
int g_score;

void InitGameLogic()
{
    g_gameState = GAME_STATE_MENU;
}

void StartGameLogic()
{
    g_gameState = GAME_STATE_PLAYING;
    g_score = 0;
}

void EndGameLogic()
{
    g_gameState = GAME_STATE_GAME_OVER;
}

// set the game state to exit
void ExitGame()
{
    g_gameState = GAME_STATE_EXIT;
}