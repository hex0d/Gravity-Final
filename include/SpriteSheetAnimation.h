#pragma once

#include "Animation.h"

class SpriteSheetAnimation
{
public:
    SpriteSheetAnimation();
    virtual ~SpriteSheetAnimation();
    void Update(Animation &a);

protected:

private:
    int frameCounter,switchFrame;
};
