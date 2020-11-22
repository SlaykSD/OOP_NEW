/**
 * Project TD_daigram_classes
 */
#ifndef _GRID_H
#define _GRID_H

#include "Tile.h"
#include <SFML/Graphics.hpp>


struct Objects {
    std::vector<sf::Sprite> roads;
    std::vector<sf::Sprite> castles;
    std::vector<sf::Sprite> liers;
};

struct Layer//слои
{
    int opacity;//непрозрачность слоя
    std::vector<sf::Sprite> tiles;//закидываем в вектор тайлы
};

class Grid {
public: 

Grid();

Grid(const Grid&);

const Tile* getTile(int i, int  j)const;

void draw(sf::RenderWindow &window);

const std::vector<std::vector<Tile>>& getTiles() const { return tileMap; }

void setTiles(const std::vector<std::vector<Tile>> newMap) 
{
    tileMap = newMap;
}

int findObjects(Objects* obj, sf::Sprite tile);

bool setTiles(std::vector<Layer> tmp, int, int, Objects*);

int setTextureTower(sf::Vector2i Position, int);

void setTexture(sf::Texture);

void setRectGrid(std::vector<sf::Rect<int>> rectG);

private: 
    bool setSpriteMagic(int type, int ,int);
    int _width;
    int _height;
    int tileWidth, tileHeight;
    std::vector<sf::Rect<int>> subRects;//Прямоугольная сетка по ID
    sf::Texture texture;
    std::vector<std::vector<Tile>> tileMap;

};

#endif //_GRID_H