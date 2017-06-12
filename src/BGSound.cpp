#include "BGSound.h"
#include <iostream>
using namespace std;


BGSound::BGSound()
{
    //bg =
    //ctor
}

BGSound::~BGSound()
{
    //dtor
}

void BGSound::playSong(ALLEGRO_SAMPLE *bg)
{
    al_play_sample(bg, 1.0, 0.0,1.0,ALLEGRO_PLAYMODE_LOOP,NULL);



}
