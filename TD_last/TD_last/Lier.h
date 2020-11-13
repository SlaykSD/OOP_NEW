#pragma once
#include "Bulding.h"
class Lier :public Bulding
{
public:
	Lier(Tile* tile);
	virtual void update(sf::Time);
private:
	void generateWave();
	sf::Time beginTime;
	int numberWaves;

};

