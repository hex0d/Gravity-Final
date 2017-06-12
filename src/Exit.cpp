#include "Exit.h"
#include "allegro5/allegro.h"
#include "ScreenManager.h"

Exit::Exit()
{
    //ScreenManager::GetInstance().UnloadContent();
    al_destroy_display(display);
    //al_destroy_event_queue(event_queue);
    //al_destroy_timer(timer);


}

Exit::~Exit()
{
    //dtor
}

