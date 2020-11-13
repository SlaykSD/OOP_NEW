#pragma once
#include "Bulding.h"

class Tower: public Bulding
{
public:
	Tower(const Tile* tile);
	virtual void update(sf::Time);
	void draw(sf::RenderWindow* window);
private:
	void lvlUP();
	int level;
	const int LEVEL_MAX = 2;
	TableStateTower table;
};

