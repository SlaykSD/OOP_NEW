#pragma once
#include "Bulding.h"
#include <list>

class Lier :public Bulding
{
public:
	Lier(const Tile* tile, std::list <sf::Vector2i>);
	virtual void update(sf::Time);
	void draw(sf::RenderWindow* window);
private:
	sf::Font font;
	sf::Text textLier;
	std::list <sf::Vector2i> checkPoints;//way from lier to castle. Mass of coordinate
	void generateWave();
	sf::Time beginTime;
	int numberWaves;
	int wave;

};

