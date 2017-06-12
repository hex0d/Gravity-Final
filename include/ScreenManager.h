#pragma once

#include<iostream>
#include<string>
#include<map>


#include "GameScreen.h"
#include "SplashScreen.h"
#include "TitleScreen.h"
#include "FadeAnimation.h"
#include "GameplayScreen.h"

#include<allegro5/allegro.h>
#include<allegro5/allegro_native_dialog.h>
#include<allegro5/allegro_image.h>
#include<allegro5/allegro_audio.h>
#include<allegro5/allegro_acodec.h>
#include<allegro5/allegro_font.h>
#include<allegro5/allegro_ttf.h>


using namespace std;
class ScreenManager
{
private:
    ScreenManager();
    ScreenManager(ScreenManager const&);
    void operator=(ScreenManager const&);
    string text;
    ALLEGRO_DISPLAY *display;
    Animation transition;
    FadeAnimation fade;
    ALLEGRO_BITMAP *transitionImage;
    void Transition();
    bool startTransition;
    map<string, GameScreen*> screenDirectory;
public:
    GameScreen *currentScreen,*newScreen;
    ~ScreenManager();
    static ScreenManager &GetInstance();
    void AddScreen(string newScreen);
    void Initialize();
    void LoadContent();
    void UnloadContent();
    void Update(ALLEGRO_EVENT ev);
    void Draw(ALLEGRO_DISPLAY *display);

};
