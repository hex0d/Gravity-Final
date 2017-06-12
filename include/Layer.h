#pragma once

#include "Tile.h"
#include "FileManager.h"
#include <string>
#include <vector>
#include <algorithm>

using namespace std;

class Layer
{
    public:
        Layer();
        ~Layer();
        void LoadContent(string layerID, string mapID);
        void UnloadContent();
        void Update();
        void Draw(ALLEGRO_DISPLAY *display);

    protected:

    private:
        FileManager fileManager;
        vector < vector < string > > attributes;
        vector < vector < string > > contents;
        vector < pair <int, int > > solidTiles;
        vector <Tile> tiles;

        pair<int,int> setTiles(string tileString);

        ALLEGRO_BITMAP *tileSheet;


};
