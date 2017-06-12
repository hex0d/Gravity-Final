#pragma once

#include<allegro5/allegro.h>
#include<allegro5/allegro_image.h>
#include <allegro5/allegro_font.h>

#include<string>

#include "InputManager.h"

using namespace std;
class Animation
{
public:
    Animation();
    virtual ~Animation();

    void UnloadContent();
    void LoadContent(ALLEGRO_BITMAP *image,string text,float position[2]);
    virtual void Update(Animation &a);
    void Draw(ALLEGRO_DISPLAY *display);

    float &Alpha();
    bool &IsActive();

    pair<int,int> &AmountOfFrames();
    pair<int,int> &CurrentFrame();
    pair<int,int> FrameDimensions();

    ALLEGRO_BITMAP* Image();
    ALLEGRO_BITMAP* &SourceRect();
    float position[2];
    bool isActive;


private:
    ALLEGRO_BITMAP *image,*sourceRect;
    ALLEGRO_FONT *font;
    string text;

    float alpha;

    pair<int,int> amountOfFrames;
    pair<int,int> currentFrame;
};

