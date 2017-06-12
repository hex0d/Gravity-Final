#pragma once

#include "Animation.h"

class FadeAnimation : public Animation
{
public:
    FadeAnimation();
    virtual ~FadeAnimation();
    void SetIncrease(bool value);
    void Update(Animation &a);
    void Draw(ALLEGRO_DISPLAY *display);
protected:

private:
    float fadeSpeed;
    bool increase;
};
