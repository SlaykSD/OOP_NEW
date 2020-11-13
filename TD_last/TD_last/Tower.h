#pragma once
#include "Bulding.h"

class Tower: public Bulding
{
public:
	Tower(Tile* tile);
	virtual void update(sf::Time);
private:
	void lvlUP();
	int level;
	const int LEVEL_MAX = 2;
	TableStateTower table;
};

