#include "PAnimation.h"

PAnimation::PAnimation()
{
    //ctor
}

PAnimation::~PAnimation()
{
    //dtor
}

void PAnimation::LoadContent(){
    playRight[0] = al_load_bitmap("1.png");
    playRight[1] = al_load_bitmap("2.png");
    playRight[2] = al_load_bitmap("3.png");
    playRight[3] = al_load_bitmap("4.png");
    playRight[4] = al_load_bitmap("5.png");
    playRight[5] = al_load_bitmap("6.png");
    playRight[6] = al_load_bitmap("7.png");
    playRight[7] = al_load_bitmap("8.png");
}
void PAnimation::Update(ALLEGRO_EVENT ev,InputManager &input){
    if(input.IsKeyPressed(ev,ALLEGRO_KEY_RIGHT)){
       frameNow = frameSwapTime % numFrames;

    }



}
void PAnimation::Draw(){
    al_draw_bitmap(playRight[frameNow],300,300,NULL);

}
