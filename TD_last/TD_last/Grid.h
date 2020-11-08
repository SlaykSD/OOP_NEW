/**
 * Project TD_daigram_classes
 */
#ifndef _GRID_H
#define _GRID_H

#include "Tile.h"
#include <SFML/Graphics.hpp>

struct Objects {
    std::vector<sf::Sprite*> roads;
    std::vector<sf::Sprite*> castles;
    std::vector<sf::Sprite*> liers;
};

struct Layer//����
{
    int opacity;//�������������� ����
    std::vector<sf::Sprite> tiles;//���������� � ������ �����
};
class Grid {
public: 

Grid();

Grid(const Grid&);

Tile getTile(int i, int  j);

void draw();

bool pushTile();
std::vector<std::vector<Tile>> getTiles() const { return tileMap; }

void setTiles(const std::vector<std::vector<Tile>> newMap) 
{
    tileMap = newMap;
}

int findObjects(Objects* obj, sf::Sprite tile);

bool setTiles(std::vector<Layer> tmp, int, int, Objects*);


private: 
    int _width;
    int _height;
    Texture texture;
    std::vector<std::vector<Tile>> tileMap;
   // Tile map[weight][height];
};

#endif //_GRID_H