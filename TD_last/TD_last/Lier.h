#pragma once
#include "Bulding.h"
#include <list>

class Lier :public Bulding
{
public:
	Lier(Tile* tile, std::list <sf::Vector2i>);
	virtual void update(sf::Time);
private:
	std::list <sf::Vector2i> checkPoints;//way from lier to castle. Mass of coordinate
	void generateWave();
	sf::Time beginTime;
	int numberWaves;

};

