#include "GOSound.h"

GOSound::GOSound()
{
    //ctor
}

GOSound::~GOSound()
{
    //dtor
}
void GOSound::playSong(ALLEGRO_SAMPLE *GOS)
{
    al_play_sample(GOS,1.0,0.0,1.0,ALLEGRO_PLAYMODE_ONCE,NULL);

}
