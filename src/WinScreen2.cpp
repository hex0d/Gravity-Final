#include "WinScreen2.h"
#include "ScreenManager.h"

WinScreen2::WinScreen2()
{
    //ctor
}

WinScreen2::~WinScreen2()
{
    //dtor
}


void WinScreen2::Draw(ALLEGRO_DISPLAY *display)
{
    input.Update();
    if(input.IsKeyDown(ALLEGRO_KEY_ENTER))
    {
        ScreenManager::GetInstance().currentScreen->UnloadContent();
        ScreenManager::GetInstance().AddScreen("TitleScreen");
        GameplayScreen::fase = 0;
    }
    if((input.IsKeyDown(ALLEGRO_KEY_R)))
    {
        ScreenManager::GetInstance().currentScreen->UnloadContent();
        ScreenManager::GetInstance().AddScreen("WaitScreen");
        GameplayScreen::fase =2;

    }
    al_draw_bitmap(go,250,200,NULL);

}
