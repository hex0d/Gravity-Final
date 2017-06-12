#pragma once
#include "GameScreen.h"
#include "Player.h"
#include "BG.h"
#include "Projectiles.h"
#include "PPC.h"
#include "Timer.h"
#include "BGSound.h"

class Player;

class GameplayScreen : public GameScreen
{
public:
    GameplayScreen();
    virtual ~GameplayScreen();
    void LoadContent();
    void UnloadContent();
    void Update(ALLEGRO_EVENT ev);
    void Draw(ALLEGRO_DISPLAY *display);
    Projectiles projectile[9];
    void liberaProjetil(ALLEGRO_EVENT ev);
    void checaColisao();


    static int fase;


protected:

private:

    Timer timer;
    Player player;
    BG bg;
    PPC ppc;
    BGSound BGS;
    ALLEGRO_SAMPLE *bgs;

};

