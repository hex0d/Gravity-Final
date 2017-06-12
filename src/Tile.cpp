#include "Tile.h"

Tile::Tile()
{
    //ctor
}

Tile::~Tile()
{
    //dtor
}

void Tile::SetContent(ALLEGRO_BITMAP *tileImage, State state, pair <float, float> position)
{
    image = tileImage;
    this->state = state;
    tileAnimation.LoadContent(tileImage, "", position);

}

void Tile::UnloadContent()
{
    al_destroy_bitmap(image);
}

void Tile::Update()
{

}

void Tile::Draw(ALLEGRO_DISPLAY *display)
{
    tileAnimation.Draw(display);
}
