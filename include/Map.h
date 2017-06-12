#pragma once

#include "Layer.h"

class Map
{
    public:
        Map();
        ~Map();

        void LoadContent();
        void UnloadContent();
        void Update();
        void Draw(ALLEGRO_DISPLAY *display);
    protected:

    private:
};
