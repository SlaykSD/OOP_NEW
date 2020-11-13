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
	//�� ������� ������
};

class Bulding:public Entity
{
public:
	Bulding(const Tile* tile);
	void setTile(const Tile* tile);
	const Tile * getTile();
	virtual void update(sf::Time) = 0;
private:
	Tile _tile;
};

