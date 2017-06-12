#pragma once

#include "GameScreen.h"
#include "MenuManager.h"
#include "InputManager.h"
#include <allegro5/allegro_font.h>

class MenuManager;
class TitleScreen : public GameScreen
{
private:
    ALLEGRO_FONT *font;
    MenuManager menu;
    InputManager input;
    ALLEGRO_BITMAP *bg = al_load_bitmap("Load/marcola.png");

public:
    TitleScreen();
    virtual ~TitleScreen();
    void LoadContent();
    void UnloadContent();
    void Update(ALLEGRO_EVENT ev);
    void Draw(ALLEGRO_DISPLAY *display);

};
