#pragma once

#include <allegro5/allegro.h>
#include <iostream>
#include "Animation.h"


using namespace std;

class Tile
{
    public:
        Tile();
        ~Tile();

        /*static */enum State {Solid, Passive};

        void SetContent(ALLEGRO_BITMAP *tileImage, State state, pair <float, float> position);
        void UnloadContent();
        void Update();
        void Draw(ALLEGRO_DISPLAY *display);

    protected:

    private:
        ALLEGRO_BITMAP *image;
        Animation tileAnimation;
        State state;
};

