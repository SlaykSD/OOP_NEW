#pragma once
#include "Enemy.h"

class LightInfantry:public Enemy
{
public:
	LightInfantry(best_list::List <sf::Vector2i>);
	void draw(sf::RenderWindow* window);
private:
	sf::Texture texture;
};

