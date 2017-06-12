#pragma once
#include "Sound.h"

class CSong : public Sound
{
    public:
        CSong();
        virtual ~CSong();
        void playSong(ALLEGRO_SAMPLE *CS);

    protected:

    private:
};


