#pragma once
#include "GameScreen.h"


class WinScreenEnd : public GameScreen
{
public:
    WinScreenEnd();
    virtual ~WinScreenEnd();
    void Update(ALLEGRO_EVENT ev,InputManager &input);
    void Draw(ALLEGRO_DISPLAY *display);
    ALLEGRO_BITMAP *go = al_load_bitmap("Load/WSE.png");

protected:

private:
};

