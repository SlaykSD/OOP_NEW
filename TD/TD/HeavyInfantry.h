#pragma once
#include "Enemy.h"
class HeavyInfantry :public Enemy
{

public:
	HeavyInfantry(best_list::List <sf::Vector2i>);
	void draw(sf::RenderWindow* window);
private:
	sf::Texture texture;
};


