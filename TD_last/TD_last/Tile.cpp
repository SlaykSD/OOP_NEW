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

int Tile::getState() {
	return state;
}
void Tile::draw() {
	;
}