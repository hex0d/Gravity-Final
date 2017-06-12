#include "SpriteSheetAnimation.h"

SpriteSheetAnimation::SpriteSheetAnimation()
{
    frameCounter = 0;
    switchFrame = 6;// 8 - 6 best adjust, lower = faster
    //ctor
}

SpriteSheetAnimation::~SpriteSheetAnimation()
{
    //dtor
}

void SpriteSheetAnimation::Update(Animation &a)
{
    if(a.IsActive())
    {
        frameCounter++;
        if(frameCounter >= switchFrame)
        {
            frameCounter =0;
            a.CurrentFrame().first++;

            if(a.CurrentFrame().first * a.FrameDimensions().first >= al_get_bitmap_width(a.Image())||a.CurrentFrame().first>=8)
            {
                a.CurrentFrame().first = 0;


            }
        }

    }
    else if(!a.IsActive()&&a.CurrentFrame().second == 0)
    {
        frameCounter =0;
        a.CurrentFrame().first = 8;
        a.CurrentFrame().second = 0;
    }
    else if(!a.IsActive()&&a.CurrentFrame().second==1)
    {
        frameCounter =0;
        a.CurrentFrame().first = 8;
        a.CurrentFrame().second = 1;
    }
    a.SourceRect() = al_create_sub_bitmap(a.Image(), a.CurrentFrame().first * a.FrameDimensions().first,
                                          a.CurrentFrame().second*a.FrameDimensions().second,
                                          a.FrameDimensions().first,
                                          a.FrameDimensions().second);



}
