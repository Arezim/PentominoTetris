#ifndef LOGIC_H
#define LOGIC_H

//---------------------------------
// Global Variables
//---------------------------------
enum GameState
{
    GAME_STATE_MENU,
    GAME_STATE_PLAYING,
    GAME_STATE_PAUSED,
    GAME_STATE_GAME_OVER,
    GAME_STATE_EXIT
};

extern int g_score;
extern GameState g_gameState;

void InitGameLogic();
void StartGameLogic();
void EndGameLogic();
void ExitGameLogic();

#endif // LOGIC_H