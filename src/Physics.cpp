#include "Physics.h"
#include "Player.h"

Physics::Physics() {}

Physics::~Physics() {}

void Physics::setPlayer(Player *player)
{
    pl = player;
}
void Physics::playerMove(int vx, int vy, int dir)
{
    switch(dir)
    {
    case 0:
        pl->direction = Player::Right;
        pl->pAnimation.position[1] -= vy;
        pl->pAnimation.position[0] += vx;
        break;
    case 1:
        pl->direction = Player::Left;
        pl->pAnimation.position[1] -= vx;
        pl->pAnimation.position[0] -= vy;
        break;
    case 2:
        pl->pAnimation.position[1] -= vy;
        break;
    case 3:
        pl->direction = Player::Right;
        pl->pAnimation.position[0] += vx;
        break;
    case 4:
        pl->direction = Player::Left;
        pl->pAnimation.position[0] -= vx;
        break;
    default:
        pl->pAnimation.isActive = true;
        pl->direction = Player::Right;
        pl->pAnimation.position[1] += 7;
        break;
    }
}
