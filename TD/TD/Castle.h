#pragma once
#include "Bulding.h"

class Castle : public Bulding
{
public:
	Castle(const Tile *tile);
	virtual void update(sf::Time);
	void draw(sf::RenderWindow* window);
	bool takeDamage(float damage) 
	{
		hp -= damage;
		if (hp < 0)
			hp = 0;
		return true;
	}
private:
	sf::Font font;
	sf::Text textCastle;
	float hp;
	const int HP_MAX;

};

