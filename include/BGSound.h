#pragma once
#include "Sound.h"
#include <allegro5/allegro.h>
#include <allegro5/allegro_acodec.h>
#include <allegro5/allegro_audio.h>

class BGSound : public Sound
{
public:
    BGSound();
    virtual ~BGSound();
    void playSong(ALLEGRO_SAMPLE *bg);
protected:

private:
};

