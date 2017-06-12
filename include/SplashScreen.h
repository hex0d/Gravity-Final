#pragma once

#include "GameScreen.h"

#include "InputManager.h"
#include "FileManager.h"
#include "FadeAnimation.h"
#include "TitleScreen.h"
#include "Animation.h"

#include <allegro5/allegro.h>
#include <allegro5/allegro_font.h>
#include <allegro5/allegro_font.h>
#include <allegro5/allegro_ttf.h>

class SplashScreen : public GameScreen
{

private:
    ALLEGRO_FONT *font;
    std::vector<ALLEGRO_BITMAP*> images;
    std::vector<Animation*> fade;
    int imageNumber;
    FadeAnimation fAnimation;
public:
    SplashScreen();
    virtual ~SplashScreen();

    void UnloadContent();
    void LoadContent();
    void Update (ALLEGRO_EVENT ev);
    void Draw (ALLEGRO_DISPLAY *display);

};
