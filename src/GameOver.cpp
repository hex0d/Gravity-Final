#include "GameOver.h"
#include "Player.h"
#include "ScreenManager.h"
#include "Includes.h"
#define MAX_Y 800
#define MAX_X 600
#include "PPC.h"




GameOver::GameOver()
{

}

GameOver::~GameOver() {}

void GameOver::setPlayer(Player *player)
{
    pl = player;
}


bool GameOver::isDougrasDead()
{
    if(pl->pAnimation.position[1] >= SCREENH || pl->pAnimation.position[1] <= -PLAYERSIZE
            || pl->pAnimation.position[0] >= SCREENW || pl->pAnimation.position[0] <= -PLAYERSIZE)
    {
        ScreenManager::GetInstance().AddScreen("GameOverScreen");
    }
}
