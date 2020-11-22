#pragma once
#include "Enemy.h"

class HeavyRanger:public Enemy
{
public:
	HeavyRanger(std::list<sf::Vector2i>);
	void draw(sf::RenderWindow* window);
private:
	sf::Texture texture;
};


