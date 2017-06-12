#include "ScreenManager.h"
#include "GameScreen.h"
#include "GameOverScreen.h"
#include "WaitScreen.h"
#include "WinScreen1.h"
#include "WinScreen2.h"
#include "WinScreenEnd.h"
#include "CreditScreen.h"
ScreenManager &ScreenManager::GetInstance()
{
    static ScreenManager instance;
    return instance;
}
ScreenManager::ScreenManager()
{
    //ctor
}

ScreenManager::~ScreenManager()
{
    //dtor
}
void ScreenManager::AddScreen(std::string screenName)
{
    transition.Alpha() = 0;
    fade.SetIncrease(true);
    startTransition = true;
    newScreen = screenDirectory[screenName];
    transition.IsActive() = true;
}
void ScreenManager::Initialize()  // para fazer um noto tipo de tela tem que criar a classe como filha de GameScreen senao n da certo e chamar assim as funções :: Exemplo-> ||         ScreenManager::GetInstance().AddScreen("GameOverScreen");
{
    screenDirectory["CreditScreen"] = new CreditScreen();
    screenDirectory["WinScreen1"] = new WinScreen1();
    screenDirectory["WinScreen2"] = new WinScreen2();
    screenDirectory["WinScreenEnd"] = new WinScreenEnd();
    screenDirectory["WaitScreen"] = new WaitScreen();
    screenDirectory["GameOverScreen"] = new GameOverScreen();
    screenDirectory["SplashScreen"] = new SplashScreen();
    screenDirectory["TitleScreen"] = new TitleScreen();
    screenDirectory["GameplayScreen"] = new GameplayScreen();
    currentScreen = screenDirectory["SplashScreen"];
}
void ScreenManager::LoadContent()
{
    currentScreen->LoadContent();
    transitionImage = al_load_bitmap("Load/black.bmp");
    float position[2] = {0,0};
    transition.LoadContent(transitionImage, "",position);
    startTransition = false;

}
void ScreenManager::UnloadContent()
{
    al_destroy_bitmap(transitionImage);
    transition.UnloadContent();
    currentScreen->UnloadContent();
    std::map<std::string, GameScreen*>::iterator tempIterator;
    for(tempIterator = screenDirectory.begin(); tempIterator!= screenDirectory.end(); tempIterator++)
        delete tempIterator->second;

}
void ScreenManager::Update(ALLEGRO_EVENT ev)
{
    if(!startTransition)
        currentScreen->Update(ev);
    else
        Transition();
}

void ScreenManager::Draw(ALLEGRO_DISPLAY *display)
{
    currentScreen->Draw(display);
    if(startTransition)
    {
        transition.Draw(display);
    }
}
void ScreenManager::Transition()
{
    fade.Update(transition);
    if(transition.Alpha()>= 255)
    {
        transition.Alpha() = 255;
        currentScreen -> UnloadContent();
        currentScreen = newScreen;
        currentScreen ->LoadContent();
    }
    else if(transition.Alpha() <= 0 )
    {
        startTransition = false;
        transition.IsActive()= false;

    }
}

