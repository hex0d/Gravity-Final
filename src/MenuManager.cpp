#include "MenuManager.h"
#include "ScreenManager.h"

MenuManager::MenuManager()
{

}

MenuManager::~MenuManager()
{
}

void MenuManager::SetMenuItems()
{
    for(int i = 0; i<menuItens.size(); i++)
    {
        if(menuImages.size() == i)
        {
            menuImages.push_back(NULL);
        }
    }
    for(int i = 0; i<menuImages.size(); i++)
    {
        if(menuItens.size() == i)
        {
            menuItens.push_back("");
        }
    }

}
void MenuManager::SetAnimation()
{
    float *pos = position;
    for(int i = 0; i<menuItens.size(); i++)
    {
        Animation a;
        animation.push_back(a);
        animation[animation.size()-1].LoadContent(menuImages[i],menuItens[i],
                pos);
        if(axis == 2)
            *(pos+1) += 34;
        else if(axis == 1)
            *(pos) += al_get_text_width(font, menuItens[i].c_str());
    }

}

void MenuManager::LoadContent(string id)
{
    fileManager.LoadContent("Load/Menus.leo", attributes, contents, id);
    for(int i = 0 ; i < attributes.size(); i++)
    {
        for(int j = 0 ; j < attributes[i].size() ; j++ )
        {
            if(attributes[i][j] == "Item")
            {
                menuItens.push_back(contents[i][j]);
            }
            else if (attributes [i][j] == "ItemLink")
                menuLinks.push_back(contents[i][j]);
            else if (attributes[i][j] == "Axis")
            {
                axis = atoi(contents[i][j].c_str());
            }
            else if (attributes[i][j] == "Image")
            {
                menuImages.push_back(al_load_bitmap(contents[i][j].c_str()));
            }
            else if (attributes[i][j] == "Font")
            {
                font = al_load_font(contents[i][j].c_str(),30,NULL);
            }
            else if (attributes[i][j] == "Align")
            {
                align = contents[i][j];
            }
            else if (attributes[i][j] == "Animation")
            {
                animationType.push_back(contents[i][j]);
            }
            else if ( attributes[i][j] == "Position")
            {
                stringstream str;
                str << contents[i][j];
                string value;
                int counter= 0;

                while (std::getline(str,value,' '))
                {
                    position[counter] = atof(value.c_str());
                    counter++;
                }
            }


        }

    }
    SetMenuItems();
    SetAnimation();
    itemNumber =0 ;

}

void MenuManager::UnloadContent()
{
    al_destroy_font(font);
    for(int i = 0 ; i < menuImages.size(); i++)
    {
        al_destroy_bitmap(menuImages[i]);
    }

    animation.clear();
    menuItens.clear();
    menuImages.clear();
    animationType.clear();
    attributes.clear();
    contents.clear();

    for(int i = 0; i<menuImages.size(); i++)
    {
        al_destroy_bitmap(menuImages[i]);
    }
}
void MenuManager::Update(ALLEGRO_EVENT ev,InputManager &input)
{
    if(input.IsKeyPressed(ev,ALLEGRO_KEY_UP))
        itemNumber--;
    else if (input.IsKeyPressed(ev,ALLEGRO_KEY_DOWN))
        itemNumber++;
    if (input.IsKeyPressed(ev, ALLEGRO_KEY_ENTER))
    {
        ScreenManager::GetInstance().AddScreen(menuLinks[itemNumber]);
    }
    if (itemNumber < 0 )
        itemNumber = 0;
    else if (itemNumber > menuItens.size()-1)
        itemNumber =menuItens.size()-1;
    for(int i = 0 ; i < animation.size(); i++)
    {
        for(int j = 0 ; j < animationType.size(); j++)
        {
            if(itemNumber == i )
                animation[i].IsActive()=true;
            else
                animation[i].IsActive()= false;

            if(animationType[j] == "Fade")
            {
                fAnimation.Update(animation[i]);
            }

        }
    }
}


void MenuManager::Draw(ALLEGRO_DISPLAY *display)
{
    for(int i = 0 ; i < animation.size(); i++)
    {
        animation[i].Draw(display);

    }
}


