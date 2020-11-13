#pragma once
#include "Entity.h"
#include "Tile.h"

class Tile;
struct TableStateTower 
{
	int cost;
	double range;
	double demage;
	int speed;
	TableStateTower() :cost(100), range(100), demage(50), speed(1) { ; }
	//Не хватает эфекта
};

class Bulding:public Entity
{
public:
	Bulding(Tile* tile);
	void setTile(Tile* tile);
	virtual void update(sf::Time) = 0;
private:
	Tile* _tile;
};

