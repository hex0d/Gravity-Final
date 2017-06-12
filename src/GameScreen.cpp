#include "GameScreen.h"

GameScreen::GameScreen()
{
    //ctor
}

GameScreen::~GameScreen()
{
    //dtor
}

void GameScreen::LoadContent()
{

}

void GameScreen::Update(ALLEGRO_EVENT ev)
{

}

void GameScreen::Draw(ALLEGRO_DISPLAY *display)
{

}
void GameScreen::UnloadContent()
{
    attributes.clear();
    contents.clear();
}
InputManager GameScreen::GetInput()
{
    return input;

}
