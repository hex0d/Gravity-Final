#include "WaitScreen.h"
#include "ScreenManager.h"
#include "Includes.h"


WaitScreen::WaitScreen()
{
    //ctor
}

WaitScreen::~WaitScreen()
{
    //dtor
}

void WaitScreen::Draw(ALLEGRO_DISPLAY *display)
{
    input.Update();
    if(input.IsKeyDown(ALLEGRO_KEY_ENTER))
    {
        ScreenManager::GetInstance().AddScreen("GameplayScreen");
    }


    al_draw_bitmap(ww,0,0,NULL);
    al_draw_text(font,al_map_rgb(255,255,255),SCREENW/2,SCREENH/2,ALLEGRO_ALIGN_CENTRE,"Aperte Enter Para INICIAR!");


}
