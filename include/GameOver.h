#pragma once
#include "GOSound.h"



class Player;
class GameOver
{
public:
    GameOver();
    ~GameOver();
    void setPlayer(Player *player);
    bool isDougrasDead();
    bool gameOver;

protected:

private:
    Player *pl;
};

