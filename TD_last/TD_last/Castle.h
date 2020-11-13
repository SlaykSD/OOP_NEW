#pragma once
#include "Bulding.h"

class Castle : public Bulding
{
public:
	Castle(Tile *tile);
	virtual void update(sf::Time);
private:
	double hp;
	const int HP_MAX;
	int money;

};

