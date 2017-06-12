#pragma once
#include "GameScreen.h"
#include "InputManager.h"


class Exit : public GameScreen
{
    public:
        Exit();
        virtual ~Exit();
        /*void operator=(ALLEGRO_EVENT const&);
        void finalize(ALLEGRO_EVENT ev);
        InputManager input;*/
        ALLEGRO_DISPLAY *display;


    protected:

    private:
};

