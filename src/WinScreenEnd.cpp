#include "WinScreenEnd.h"
#include "ScreenManager.h"

WinScreenEnd::WinScreenEnd()
{
    //ctor
}

WinScreenEnd::~WinScreenEnd()
{
    //dtor
}


void WinScreenEnd::Draw(ALLEGRO_DISPLAY *display)
{
    input.Update();
    if(input.IsKeyDown(ALLEGRO_KEY_ENTER))
    {
        ScreenManager::GetInstance().currentScreen->UnloadContent();
        ScreenManager::GetInstance().AddScreen("CreditScreen");
        GameplayScreen::fase = 0;

    }
    al_draw_bitmap(go,250,200,NULL);

}
