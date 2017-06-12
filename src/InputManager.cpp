#include "InputManager.h"
using namespace std;

InputManager::InputManager()
{
    //ctor
}

InputManager::~InputManager()
{
    //dtor
}
void InputManager::Update()
{
    al_get_keyboard_state(&keyState);

}
bool InputManager::IsKeyPressed(ALLEGRO_EVENT ev, int key)
{
    if(ev.type == ALLEGRO_EVENT_KEY_DOWN)
    {
        if(ev.keyboard.keycode == key)
        {
            return true;
        }
    }
    return false;
}
bool InputManager::IsKeyPressed(ALLEGRO_EVENT ev, vector <int> keys)
{
    if(ev.type == ALLEGRO_EVENT_KEY_DOWN)
    {
        for(int i=0; i<keys.size(); i++)
        {
            if(ev.keyboard.keycode == keys[i])
            {
                return true;
            }
        }
    }
    return false;
}
bool InputManager::IsKeyReleased(ALLEGRO_EVENT ev, int key)
{
    if(ev.type == ALLEGRO_EVENT_KEY_UP)
    {
        if(ev.keyboard.keycode == key)
        {
            return true;
        }
    }
}
bool InputManager::IsKeyReleased(ALLEGRO_EVENT ev, vector <int> keys)
{
    if(ev.type == ALLEGRO_EVENT_KEY_UP)
    {
        for(int i=0; i<keys.size(); i++)
        {
            if(ev.keyboard.keycode == keys[i])
            {
                return true;
            }
        }
    }
    return false;
}

bool InputManager::IsKeyDown(int key)
{
    if(al_key_down(&keyState,key))
        return true;
    return false;

}
