#pragma once

#include "Player.h"


class PPC
{
public:
    PPC();
    virtual ~PPC();
    static bool colision(ALLEGRO_BITMAP *player,ALLEGRO_BITMAP *projectile,float x, float y,float ex,float ey );
    void setPlayer(Player *player);
protected:

private:
};
