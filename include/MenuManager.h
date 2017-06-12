#pragma once

#include "Animation.h"
#include "FadeAnimation.h"
#include "FileManager.h"
#include <allegro5/allegro.h>
#include <vector>
#include <sstream>

using namespace std;
class MenuManager
{
public:
    MenuManager();
    virtual ~MenuManager();
    void LoadContent(string id);
    void UnloadContent();
    void Update(ALLEGRO_EVENT ev,InputManager &input);
    void Draw(ALLEGRO_DISPLAY *display);
    std::vector< std::vector<std::string> > attributes;
    std::vector< std::vector<std::string> > contents;
protected:

private:
    vector<string> menuLinks;
    vector<string> menuItens;
    vector<ALLEGRO_BITMAP*> menuImages;
    vector<Animation> animation;
    vector<string> animationType;
    vector<Animation*> tempAnimation;
    FadeAnimation fAnimation;
    int itemNumber;
    FileManager fileManager;
    float position[2];
    int axis;
    string align;
    ALLEGRO_FONT *font;
    void SetMenuItems();
    void SetAnimation();


};
