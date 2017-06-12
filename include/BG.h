#pragma once
#include <allegro5/allegro.h>

class BG
{
public:
    void LoadContent();
    void Draw(ALLEGRO_DISPLAY *display);
    BG();
    virtual ~BG();

protected:

private:
    ALLEGRO_BITMAP *bg = al_load_bitmap("Load/bg1.jpg");
};


