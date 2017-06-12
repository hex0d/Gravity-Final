#pragma once
#include<allegro5/allegro5.h>
#include "InputManager.h"
class PAnimation
{
    public:
        ALLEGRO_TIMER* timer = al_create_timer(1.0/60);
        ALLEGRO_BITMAP* playRight[8];
        int numFrames = 8;
        int frameNow = 0;
        int frameSwapTime = 100;
        void LoadContent();
        void Update(ALLEGRO_EVENT ev,InputManager &input);
        void Draw();
        PAnimation();
        virtual ~PAnimation();

    protected:

    private:

};


