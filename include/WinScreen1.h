#pragma once
#include "GameScreen.h"


class WinScreen1 : public GameScreen
{
public:
    WinScreen1();
    virtual ~WinScreen1();
    void Update(ALLEGRO_EVENT ev,InputManager &input);
    void Draw(ALLEGRO_DISPLAY *display);
    ALLEGRO_BITMAP *go = al_load_bitmap("Load/WS1.png");


protected:

private:
};

