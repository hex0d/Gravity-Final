#pragma once
#include <allegro5/allegro5.h>
#include <allegro5/allegro.h>

#include <allegro5/allegro_font.h>




class Timer
{
public:
    void start();
    void update();
    void draw(ALLEGRO_DISPLAY *display);
    void ended(int i);
    Timer();
    virtual ~Timer();
    ALLEGRO_FONT *font = al_load_font("1.ttf",15,0);
    char tempo;
    float seconds;

protected:


private:

};

