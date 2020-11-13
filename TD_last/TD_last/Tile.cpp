/**
 * Project TD_daigram_classes
 */


#include "Tile.h"

/**
 * Tile implementation
 */


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
int Tile::getDraw(sf::RenderWindow* window)const
{
	window->draw(sprite);
	return 10;
}
//Tile& Tile::operator= (const Tile& t)
//{
//
//}

//const Tile& Tile::operator=(const Tile&)
//{
//	;
//}