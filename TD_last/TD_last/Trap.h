#pragma once
#include "Bulding.h"

class Trap : public Bulding
{
public:
	Trap(Tile* tile);
	virtual void update(sf::Time);
private:
	double demage;
	int cost;
	double range;
	//эфект
};

