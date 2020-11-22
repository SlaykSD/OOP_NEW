#pragma once
#include "Bulding.h"

class Trap : public Bulding
{
public:
	Trap(const Tile* tile);
	virtual void update(sf::Time);
	void draw(sf::RenderWindow* window);
private:
	sf::Font font;
	sf::Text textCastle;
	double demage;
	int cost;
	double range;
	//эфект
};

