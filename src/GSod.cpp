#include "GSod.h"

GSod::GSod()
{
    //ctor
}

GSod::~GSod()
{
    //dtor
}
void GSod::playSound(ALLEGRO_SAMPLE *CS)
{
    al_play_sample(CS,1,0,1,ALLEGRO_PLAYMODE_ONCE,NULL);

}
