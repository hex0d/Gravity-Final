#include "WinScreen1.h"
#include "ScreenManager.h"
#include "GameplayScreen.h"
WinScreen1::WinScreen1()
{
    //ctor
}

WinScreen1::~WinScreen1()
{
    //dtor
}



void WinScreen1::Draw(ALLEGRO_DISPLAY *display)
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
        GameplayScreen::fase = 1;

    }
    al_draw_bitmap(go,0,0,NULL);

}
