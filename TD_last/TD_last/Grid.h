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

const Tile& getTile(int i, int  j)const;

void draw();

std::vector<std::vector<Tile>> getTiles() const { return tileMap; }

void setTiles(const std::vector<std::vector<Tile>> newMap) 
{
    tileMap = newMap;
}

int findObjects(Objects* obj, sf::Sprite tile);

bool setTiles(std::vector<Layer> tmp, int, int, Objects*);

int setTextureTower(sf::Vector2i Position, sf::RenderWindow *window);

void setTexture(sf::Texture);

void setRectGrid(std::vector<sf::Rect<int>> rectG);

private: 
    int _width;
    int _height;
    int tileWidth, tileHeight;
    std::vector<sf::Rect<int>> subRects;//������������� ����� �� ID
    Texture texture;
    std::vector<std::vector<Tile>> tileMap;
};

#endif //_GRID_H