#pragma once

#include<allegro5/allegro.h>
#include "InputManager.h"
#include "FileManager.h"

#include<vector>
#include<string>
class GameScreen
{
protected:
    InputManager input;
    std::vector< std::vector<std::string> > attributes;
    std::vector< std::vector<std::string> > contents;
    FileManager fileManager;
public:
    GameScreen();
    virtual ~GameScreen();
    virtual void UnloadContent();
    virtual void LoadContent();
    virtual void Update (ALLEGRO_EVENT ev);
    virtual void Draw (ALLEGRO_DISPLAY *display);
    InputManager GetInput();
};
