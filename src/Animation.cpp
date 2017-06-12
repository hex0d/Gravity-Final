#include "Animation.h"

using namespace std;
Animation::Animation() {}

Animation::~Animation() {}

void Animation::LoadContent(ALLEGRO_BITMAP* image, string text, float position[2])
{
    this->image = image;
    this->text = text;
    this->position[0] = position[0];
    this->position[1] = position[1];
    alpha = 255;
    font = al_load_font("1.ttf", 40, NULL);
    sourceRect = image;
    isActive = true;
    amountOfFrames = pair<int, int>(9, 2);
    currentFrame = pair<int, int>(0, 0);
}

void Animation::UnloadContent()
{
    al_destroy_font(font);
    alpha = NULL;
    position[0] = position[1] = NULL;
}

void Animation::Update(Animation& a) {}

void Animation::Draw(ALLEGRO_DISPLAY* display)
{
    al_set_blender(ALLEGRO_ADD, ALLEGRO_ALPHA, ALLEGRO_INVERSE_ALPHA);
    if (sourceRect != NULL)
        al_draw_tinted_bitmap(sourceRect, al_map_rgba(255, 255, 255, alpha), position[0], position[1], NULL);
    if (text != "")
        al_draw_text(font, al_map_rgba(255, 0, 0, alpha), position[0], position[1], ALLEGRO_ALIGN_CENTRE, text.c_str());
}

float& Animation::Alpha()
{
    return alpha;
}

bool& Animation::IsActive()
{
    return isActive;
}

pair<int, int>& Animation::AmountOfFrames()
{
    return amountOfFrames;
}

pair<int, int>& Animation::CurrentFrame()
{
    return currentFrame;
}

pair<int, int> Animation::FrameDimensions()
{
    pair<int, int> fd(al_get_bitmap_width(image) / amountOfFrames.first, al_get_bitmap_height(image) / amountOfFrames.second);
    return fd;
}

ALLEGRO_BITMAP* Animation::Image()
{
    return image;
}

ALLEGRO_BITMAP*& Animation::SourceRect()
{
    return sourceRect;
}
