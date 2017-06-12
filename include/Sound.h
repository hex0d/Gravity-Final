#pragma once
#include <allegro5/allegro_audio.h>

class Sound
{
public:
    virtual void playSong(ALLEGRO_SAMPLE *bg) = 0;
    virtual ~Sound();

protected:

private:
};
