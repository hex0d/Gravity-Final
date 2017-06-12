#include "Projectiles.h"
#include "Includes.h"
#include <math.h>
#include <cstdlib>
#include <ctime>


Projectiles::Projectiles()
{
    posx = -100;
    posy = -200;

}

Projectiles::~Projectiles()
{
    //dtor
}






void Projectiles::LoadContent()
{
    active = false;
    quadr = rand()%8;

    switch(quadr)
    {
    case 0:

        posx = SCREENW+50;
        posy = rand() % (SCREENH/2) + 1;
        finalposy = rand() % SCREENH + 3;
        finalposx = 0;
        break;

    case 1:
        posx = rand()%(SCREENW/2) + (SCREENW/2);
        posy = -50;
        finalposy = SCREENH;
        finalposx = (rand() % SCREENW) - 200 ;
        break;
    case 2:
        posx = rand() % (SCREENW/2);
        posy = -50;
        finalposy = SCREENH;
        finalposx = rand() % SCREENW;
        break;
    case 3:
        posx = -50;
        posy = (rand() % (SCREENH/2));
        finalposy = rand() % SCREENH;
        finalposx = SCREENW + 50;
        break;
    case 4:
        posx = -50;
        posy = (rand() % (SCREENH/2)) + SCREENH/2 ;
        finalposy = rand() % SCREENH;
        finalposx = SCREENW + 50;
        break;
    case 5:
        posx = rand() % (SCREENW/2);
        posy = SCREENH +50;
        finalposy = 0;
        finalposx = rand() % SCREENW;
        break;
    case 6:
        posx = rand() % (SCREENW/2)+(SCREENW/2);
        posy = SCREENH+50;
        finalposy = 0;
        finalposx = rand() % SCREENW;
        break;
    case 7:
        posx = SCREENW+50;
        posy = rand() % (SCREENH/2) + (SCREENH/2) ;
        finalposy = rand() % SCREENH;
        finalposx = -50;

        break;

    }
    velx[0] = ((finalposx - posx)/120)/2;
    vely[0] = ((finalposy - posy)/120)/2;
    velx[1] = (finalposx - posx)/120;
    vely[1] = (finalposy - posy)/120;


    velx[2] = ((finalposx - posx)/120)*2;
    vely[2] = ((finalposy - posy)/120)*2;






}
void Projectiles::Update(ALLEGRO_EVENT ev,int fase)
{
    posx += velx[fase];
    posy += vely[fase];

}
void Projectiles::Draw(ALLEGRO_DISPLAY *display)
{
    al_draw_bitmap(proj,posx,posy,NULL);


}
