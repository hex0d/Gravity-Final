#pragma once
#include "GameScreen.h"
#include "GSod.h"


class CreditScreen : public GameScreen, public GSod
{
public:
    CreditScreen();
    virtual ~CreditScreen();
    ALLEGRO_SAMPLE *CS;
    void Update(ALLEGRO_EVENT ev,InputManager &input);
    void Draw(ALLEGRO_DISPLAY *display);
    void UnloadContent();
    ALLEGRO_BITMAP *CSb = al_load_bitmap("Load/CS.png");
    GSod cs;
    void LoadContent();

protected:

private:
};
