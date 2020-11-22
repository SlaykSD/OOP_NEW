#pragma once
#include "Enemy.h"

class LightInfantry:public Enemy
{
public:
	LightInfantry(std::list<sf::Vector2i>);
	void draw(sf::RenderWindow* window);
private:
	sf::Texture texture;
	int n;
};

