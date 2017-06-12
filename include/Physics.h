#pragma once
class Player;
class Physics
{
public:
    Physics();
    ~Physics();
    void setPlayer(Player *player);
    void playerMove(int, int, int);

protected:

private:
    Player *pl;
    int gravity;
    int velocity_x;
    int velocity_y;

};
