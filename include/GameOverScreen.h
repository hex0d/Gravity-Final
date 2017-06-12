#pragma once
#include "GameScreen.h"
#include "FadeAnimation.h"
#include "Animation.h"
#include "GOSound.h"



class GameOverScreen : public GameScreen
{
public:
    ALLEGRO_SAMPLE *GOS;
    GameOverScreen();
    virtual ~GameOverScreen();
    void Update(ALLEGRO_EVENT ev,InputManager &input);
    void Draw(ALLEGRO_DISPLAY *display);
    void UnloadContent();
    ALLEGRO_BITMAP *go = al_load_bitmap("Load/go.png");
    GOSound gos;
    void LoadContent();

protected:

private:
};

