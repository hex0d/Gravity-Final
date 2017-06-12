#pragma once
#include "InputManager.h"
#include "GameScreen.h"
#include <allegro5/allegro_font.h>
class WaitScreen: public GameScreen
{
public:
    WaitScreen();
    virtual ~WaitScreen();
    void Draw(ALLEGRO_DISPLAY *display);
    ALLEGRO_BITMAP *ww = al_load_bitmap("Load/ww.png");
    ALLEGRO_FONT *font = al_load_font("1.ttf",40,0);

protected:

private:
};
