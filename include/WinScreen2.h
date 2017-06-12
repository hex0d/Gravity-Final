#pragma once
#include "GameScreen.h"


class WinScreen2 : public GameScreen
{
public:
    WinScreen2();
    virtual ~WinScreen2();
    void Update(ALLEGRO_EVENT ev,InputManager &input);
    void Draw(ALLEGRO_DISPLAY *display);
    ALLEGRO_BITMAP *go = al_load_bitmap("Load/WS2.png");

protected:

private:
};

