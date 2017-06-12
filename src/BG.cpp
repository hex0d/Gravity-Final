#include "BG.h"

BG::BG()
{

}

BG::~BG()
{
    //dtor
}


void BG::Draw(ALLEGRO_DISPLAY *display)
{
    al_draw_bitmap(bg,0,0,NULL);
}
