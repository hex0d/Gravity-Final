#include "Timer.h"
#include<iostream>
#include "ScreenManager.h"

Timer::Timer()
{


}

Timer::~Timer()
{
    //dtor
}
void Timer::start()
{
    seconds = 3;
}
void Timer::update()
{
    seconds -= 0.0166666666666667;


}
void Timer::draw(ALLEGRO_DISPLAY *display)
{
    al_draw_textf(font,al_map_rgb(255,255,255),400,30,NULL,"%.2f",seconds);
}

void Timer::ended(int i)
{
    if(seconds < 0)
    {
        seconds = 1000;
        if(i==0)
        {



            ScreenManager::GetInstance().AddScreen("WinScreen1");
        }
        if(i==1)
        {

            ScreenManager::GetInstance().AddScreen("WinScreen2");

        }
        if(i==2)
        {

            ScreenManager::GetInstance().AddScreen("WinScreenEnd");

        }

    }

}
