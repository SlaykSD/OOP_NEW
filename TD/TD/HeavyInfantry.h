#pragma once
#include "Enemy.h"
class HeavyInfantry :public Enemy
{

public:
	HeavyInfantry(std::list<sf::Vector2i>);
	void draw(sf::RenderWindow* window);
private:
	sf::Texture texture;
	int n;
};


