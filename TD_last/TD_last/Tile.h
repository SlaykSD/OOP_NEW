#pragma once

#include <SFML/Graphics.hpp>
#include "Type.h"

using namespace sf;

class Tile {
public: 
    
void setState(int );
void setSprite(sf::Sprite tmp) { sprite = tmp;}
void setTileNumber(int);

//const Tile& operator= (const Tile& t);
const sf::Sprite getSprite()const;

//const Tile& operator=(const Tile&);
int getState() const;
    
int getTileNumber() const;
    
void setTexture(sf::Texture&, sf::IntRect);

int getDraw(sf::RenderWindow* window)const;

private: 
    Type state;
    int tileNumber;
    Sprite sprite;
    
};
