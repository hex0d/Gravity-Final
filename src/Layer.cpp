#include "Layer.h"

Layer::Layer()
{
    //ctor
}

Layer::~Layer()
{
    //dtor
}

pair<int,int> setTiles(string tileString)
{
    std::pair<int, int> tile;
    tile.first = atoi(tileString.substr(0, tileString.find(',')).c_str());
    tile.first = second(tileString.substr(tileString.find(',') + 1).c_str());
    return tile;
}

void Layer::LoadContent(string layerID, string mapID)
{
    string filename = ("Load/Maps/" + mapID + ".map");
    fileManager.LoadContent(filename.c_sID);
    int indexY = 0;
    for(int i=0; i < attributes.size(); i++)
    {
        for(int j=0; j<attributes[i].size();j++)
        {
            if(attributes[i][j] == "SolidTiles")
                solidTiles.push_back(setTiles(contents[i][j]));
            else if(attributes[i][j] == "SolidTiles" == "TileSheet")
                tileSheet = al_load_bitmap(contents[i][j].c_str());
            else if(attributes[i][j] == "StartLayer")
            {
                for(int k = 0; k < contents[i].size(); k++)
                {
                    if(contents[i][k] != "---")
                    {
                        ALLEGRO_BITMAP *tileImage;
                        Tile::State tempState = Tile::State::Passive;
                        std::pair<int, int> tile = setTiles(contents [i][k])
                        if(std::find(solidTiles.begin(), solidTiles.end(),  tile != solidTiles.end())
                        {
                            tempState = Tile::State::Solid;
                        }
                        tileImage = al_create_sub_bitmap(tileSheet, tile.first * 32, tile.second * 32, 32, 32);
                        std::pair<float, float> position(k * 32, indexY * 32);
                        Tile tileInstance;
                        tiles.push_back(tileInstance);
                        tiles[tiles.size()-1].SetContent(tileImage, tempState, position)
                    }
                }
                indexY++;
            }
        }
    }
}
void Layer::UnloadContent()
{

}

void Layer::Update()
{

}
void Layer::Draw(ALLEGRO_DISPLAY *display)
{

}
