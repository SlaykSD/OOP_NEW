#include "Tile.h"


void Tile::setState(int i) {
	
	switch (i)
	{
	case(0):
		state = Type::forest;
		break;
	case(1):
		state = Type::road;
		break;
	case(2):
		state = Type::castle;
		break;
	case(3):
		state = Type::lier;
		break;
	case(4):
		state = Type::tower;
		break;
	case(5):
		state = Type::trap;
		break;
	}
}
int Tile:: getTileNumber()const
{
	return tileNumber;
}
void Tile::setTileNumber(int numb) 
{
	tileNumber = numb;
}
void Tile::setTexture(sf::Texture& t, sf::IntRect rect)
{
	this->sprite.setTexture(t);
	this->sprite.setTextureRect(rect);
}
int Tile::getState() const
{
	return state;
}
const sf::Sprite Tile::getSprite()const
{
	return sprite;
}

void Tile::setOrigin(float w, float h)
{
	sprite.setOrigin(w, h);
}
const sf::Sprite* Tile::getSpriteV()
{
	return &sprite;
}
void Tile::setRotation(float angle)
{
	sprite.setRotation(angle);
}
void Tile::setPositionToCenter()
{
	sf::Vector2f pos = sprite.getPosition();
	sf::Vector2f center(sprite.getTextureRect().width / 2, sprite.getTextureRect().height / 2);
	pos = pos + center;
	sprite.setPosition(pos);
}
void Tile::setPosition(sf::Vector2f pos)
{
	if ((pos.x > sprite.getTextureRect().width * 9)||
		(pos.y > sprite.getTextureRect().height * 9)||
		(pos.x <0)|| (pos.y<0))
	{
		throw "going beyond";
	}
	else
	{
		sprite.setPosition(pos);
	}
}