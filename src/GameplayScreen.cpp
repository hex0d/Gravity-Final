#include "GameplayScreen.h"
#include "Includes.h"
#include "ScreenManager.h"


GameplayScreen::GameplayScreen()
{



}

GameplayScreen::~GameplayScreen()
{
    //dtor
}
void GameplayScreen::checaColisao()
{
    for(int i = 0 ; i < 9 ; i++)
    {
        if(ppc.colision(player.playerImage,projectile[i].proj,player.pAnimation.position[0],player.pAnimation.position[1],projectile[i].posx,projectile[i].posy))
        {


            ScreenManager::GetInstance().currentScreen->UnloadContent();
            ScreenManager::GetInstance().AddScreen("GameOverScreen");

        }
    }

}
void GameplayScreen::liberaProjetil(ALLEGRO_EVENT ev)
{
    for (int i=0; i<9; i++)
    {
        if(projectile[i].active)
        {
            projectile[i].Update(ev,GameplayScreen::fase);
            if (projectile[i].posx >= SCREENW+70|| projectile[i].posx <= -70|| projectile[i].posy >= SCREENH + 50 || projectile[i].posy <= -50)
                projectile[i].active = false;

        }

    }


    for (int p=0; p<9; p++)
    {
        if(!projectile[p].active)
        {
            if(rand()%350 == 0)
            {
                projectile[p].LoadContent();
                projectile[p].active = true;
                break;

            }
        }
    }

}


void GameplayScreen::LoadContent()
{


    player.LoadContent();
    timer.start();
    if(fase == 0 )
    {
        bgs = al_load_sample("Load/GS1.wav");
        BGS.playSong(bgs);
    }
    if(fase == 1 )
    {
        bgs = al_load_sample("Load/GS2.wav");
        BGS.playSong(bgs);
    }
    if(fase == 2 )
    {
        bgs = al_load_sample("Load/GS3.wav");
        BGS.playSong(bgs);
    }

}





void GameplayScreen::UnloadContent()
{
    al_destroy_sample(bgs);

    GameScreen::UnloadContent();
    for(int i = 0 ; i < 9 ; i++)
    {
        projectile[i].active = false;
        projectile[i].posx = -200;
        projectile[i].posy = -200;
    }
}

void GameplayScreen::Update(ALLEGRO_EVENT ev)
{
    timer.update();


    liberaProjetil(ev);
    checaColisao();

    player.Update(ev,input);


}


void GameplayScreen::Draw(ALLEGRO_DISPLAY *display)
{

    bg.Draw(display);
    player.Draw(display);
    timer.draw(display);
    timer.ended(GameplayScreen::fase);



    for (int i=0; i<9; i++)
    {

        projectile[i].Draw(display);


    }

}
