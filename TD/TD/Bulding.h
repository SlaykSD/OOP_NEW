#pragma once
#include "Entity.h"
#include "Tile.h"

class Tile;

class Bulding:public Entity
{
public:
	Bulding();
	Bulding(const Tile* tile);
	void setTile(const Tile* tile);
	const Tile * getTile();
	virtual void update(sf::Time) = 0;

protected:
	Tile _tile;
};
