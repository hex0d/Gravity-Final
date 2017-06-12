#include "SplashScreen.h"
#include "ScreenManager.h"

SplashScreen::SplashScreen()
{
    //ctor
}

SplashScreen::~SplashScreen()
{
    //dtor
}
void SplashScreen::LoadContent()
{
    imageNumber=0;
    font = al_load_font("1.ttf",30,NULL);
    fileManager.LoadContent("Load/Splash.leo",attributes, contents);
    for(int i =0; i<attributes.size(); i++)
    {
        for(int j = 0 ; j < attributes[i].size(); j++)
        {
            if(attributes[i][j] == "Image")
            {
                float position[2] = { 0,0};
                images.push_back(al_load_bitmap(contents[i][j].c_str()));
                fade.push_back(new FadeAnimation);

                fade[fade.size()-1]->LoadContent(images[fade.size()-1],"",position);
                fade[fade.size()-1]->IsActive() = true;
            }
        }
    }
}

void SplashScreen::UnloadContent()
{
    GameScreen::UnloadContent();
    al_destroy_font(font);
    for(int i=0 ; i < fade.size() ; i++)
    {
        al_destroy_bitmap(images[i]);
        delete fade[i];
    }
    fade.clear();
}

void SplashScreen::Update(ALLEGRO_EVENT ev)
{

    if(fade[imageNumber]->Alpha() == 255)
        imageNumber++;
    if(imageNumber>= fade.size() -1|| input.IsKeyPressed(ev,ALLEGRO_KEY_ENTER))
    {
        ScreenManager::GetInstance().AddScreen("TitleScreen");
    }
    int position[2] = {0,0};
    fade[imageNumber - 1]->Update(fAnimation);


}
void SplashScreen::Draw(ALLEGRO_DISPLAY *display)
{
    fade[imageNumber]->Draw(display);

}
