#include "PPC.h"
#include<cmath>

PPC::PPC()
{
    //ctor
}

PPC::~PPC()
{
    //dtor
}

bool PPC::colision(ALLEGRO_BITMAP *player,ALLEGRO_BITMAP *projectile,float x,float y,float ex,float ey)
{
    int top,bot,left,right;

    if(x+100 < ex || x > ex+69|| y + 100 < ey || y > ey + 28)
        return false;
    else
    {
        top = max(y,ey);
        bot = min (y+100,ey+28);
        left = max(x,ex);
        right = min(x+100,ex+69);
        for(int i = top; i<bot; i++)
        {
            for (int j = left; j<right; j++)
            {
                al_lock_bitmap(player,al_get_bitmap_format(player),ALLEGRO_LOCK_READONLY);
                al_lock_bitmap(projectile,al_get_bitmap_format(projectile),ALLEGRO_LOCK_READONLY);
                ALLEGRO_COLOR color = al_get_pixel(player,j-x,i-y);
                ALLEGRO_COLOR color2 = al_get_pixel(projectile,j-ex,i-ey);

                if(color.a!=0 && color2.a != 0)
                {
                    return true;
                }
            }
        }

    }
    return false;

}
