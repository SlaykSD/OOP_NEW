
#ifndef _TILE_H
#define _TILE_H

#include <SFML/Graphics.hpp>
#include "Type.h"

using namespace sf;

class Tile {
public: 
    
void setState(int );
void setSprite(sf::Sprite tmp) { sprite = tmp;}
void setTileNumber(int);

const sf::Sprite& getSprite()const;

int getState();
    
int getTileNumber() const;
    
void setTexture(sf::Texture&, sf::IntRect);

private: 
    Type state;
    int tileNumber;
    Sprite sprite;
    
void draw();
};

#endif //_TILE_H