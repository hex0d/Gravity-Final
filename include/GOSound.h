#pragma once
#include "Sound.h"


class GOSound : public Sound
{
public:
    GOSound();
    virtual ~GOSound();
    void playSong(ALLEGRO_SAMPLE *GOS);

protected:

private:
};

