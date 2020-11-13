#include "Bulding.h"
void Bulding::setTile(const Tile* tile)
{
	_tile = *tile;
}
Bulding::Bulding(const Tile* tile)
{
	_tile = *tile;
}
const Tile* Bulding::getTile()
{
	return &this->_tile;
}