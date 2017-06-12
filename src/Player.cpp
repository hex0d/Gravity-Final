#include "Player.h"
#include "Includes.h"

using namespace std;


Player::Player()
{
    ph.setPlayer(this);
    go.setPlayer(this);
}

Player::~Player()
{

}
void Player::LoadContent()
{
    fm.LoadContent("Load/Player.leo",attributes,contents);
    for(int i = 0 ; i<attributes.size(); i++)
    {
        for( int j = 0 ; j < attributes[i].size(); j++)
        {
            if(attributes[i][j] == "Image")
                playerImage = al_load_bitmap(contents[i][j].c_str());
            else if(attributes[i][j] == "Position")
            {
                stringstream str;
                str << contents[i][j];
                string value;
                int counter= 0;

                while (std::getline(str,value,','))
                {
                    position[counter] = atof(value.c_str());
                    counter++;
                }
            }


        }
    }
    ySpeed = 5; //alterar no level
    xSpeed = 5; //alterar no level

    pAnimation.LoadContent(playerImage,"",position);

}
void Player::UnloadContent()
{
    attributes.clear();
    contents.clear();
    al_destroy_bitmap(playerImage);
    pAnimation.UnloadContent();

}
void Player::Update(ALLEGRO_EVENT ev, InputManager input)
{
    pAnimation.IsActive() = true;
    ssAnimation.Update(pAnimation);

    input.Update();


    if(input.IsKeyDown(ALLEGRO_KEY_SPACE)&& input.IsKeyDown(ALLEGRO_KEY_RIGHT))
        ph.playerMove(xSpeed,ySpeed,0);
    else if(input.IsKeyDown(ALLEGRO_KEY_SPACE)&& input.IsKeyDown(ALLEGRO_KEY_LEFT))
        ph.playerMove(xSpeed,ySpeed,1);
    else if(input.IsKeyDown(ALLEGRO_KEY_SPACE))
        ph.playerMove(0,ySpeed,2);
    else if(input.IsKeyDown(ALLEGRO_KEY_RIGHT))
        ph.playerMove(xSpeed,0,3);
    else if(input.IsKeyDown(ALLEGRO_KEY_LEFT))
        ph.playerMove(xSpeed,0,4);
    else
        pAnimation.IsActive() = false;

    pAnimation.CurrentFrame().second = direction;

    if(pAnimation.position[1] <= SCREENW - PLAYERSIZE && !input.IsKeyDown(ALLEGRO_KEY_SPACE))
        ph.playerMove(0,ySpeed,100); //100 - ANY NUMBER

    go.isDougrasDead();

}
void Player::Draw(ALLEGRO_DISPLAY *display)
{
    pAnimation.Draw(display);
}
