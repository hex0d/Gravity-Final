#pragma once
#include "GameScreen.h"

class ExitScreen : public GameScreen
{
    public:
        ExitScreen();
        virtual ~ExitScreen();
        ALLEGRO_DISPLAY *display;
        //void Update(ALLEGRO_EVENT ev,InputManager &input);
        //void Draw(ALLEGRO_DISPLAY *display);
        //ALLEGRO_BITMAP *go = al_load_bitmap("WS1.png");


    protected:

    private:
};
