#include "CS.h"

CS::CS()
{
    //ctor
}

CS::~CS()
{
    //dtor
}

void CS::playSong(ALLEGRO_SAMPLE *cs){
    ALLEGRO_SAMPLE *cs = al_load_sample("CS.wav");
    al_play_sample(cs,1,0,1,ALLEGRO_PLAYMODE_ONCE,NULL);

}
