#pragma once

#include <SFML/Graphics.hpp>
#include "Type.h"

class Tile {
public: 
    
void setState(int );
void setSprite(const sf::Sprite& tmp) { sprite = tmp;}
void setTileNumber(int);
void setColor(sf::Color col) { sprite.setColor(col); }
const sf::Sprite getSprite()const;
int getState() const;
int getTileNumber() const;  
void setTexture(sf::Texture&, sf::IntRect);
void setTexture(sf::Texture& t) { sprite.setTexture(t); }
int getDraw(sf::RenderWindow* window)const;
bool setMagicTower(int);
const sf::Sprite* getSpriteV();

protected: 
    Type state;
    int tileNumber;
    sf::Sprite sprite;
    
};
