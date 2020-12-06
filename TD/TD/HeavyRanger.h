#pragma once
#include "Enemy.h"

class HeavyRanger:public Enemy
{
public:
	HeavyRanger(best_list::List <sf::Vector2i>);
	void draw(sf::RenderWindow* window);
private:
	sf::Texture texture;
};


