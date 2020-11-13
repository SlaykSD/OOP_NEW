#pragma once
#include "Bulding.h"

class Castle : public Bulding
{
public:
	Castle(const Tile *tile);
	virtual void update(sf::Time);
	void draw(sf::RenderWindow* window);
private:
	sf::Font font;
	sf::Text textCastle;
	double hp;
	const int HP_MAX;

};

