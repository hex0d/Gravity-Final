#include "CreditScreen.h"
#include "ScreenManager.h"

CreditScreen::CreditScreen()
{
    LoadContent();
}
void CreditScreen::LoadContent()
{
    CS = al_load_sample("Load/GS.wav");
    cs.playSound(CS);

}

CreditScreen::~CreditScreen()
{
    //dtor
}
void CreditScreen::Update(ALLEGRO_EVENT ev,InputManager &input)
{



}
void   CreditScreen::UnloadContent()
{
    al_destroy_sample(CS);
    GameScreen::UnloadContent();

}


void CreditScreen::Draw(ALLEGRO_DISPLAY *display)
{
    input.Update();
    if(input.IsKeyDown(ALLEGRO_KEY_ENTER))
    {
        ScreenManager::GetInstance().currentScreen->UnloadContent();
        ScreenManager::GetInstance().AddScreen("TitleScreen");

    }
    al_draw_bitmap(CSb,0,0,NULL);
}
