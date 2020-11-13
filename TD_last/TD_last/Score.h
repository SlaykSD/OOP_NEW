#pragma once
#include "Entity.h"
class Score:public Entity
{
public:
	Score();
	virtual void update(sf::Time);
	void draw(sf::RenderWindow* window);
private:
	sf::Font font;
	sf::Text textGold;
	sf::Text textScore;
	int gold;
	int score;

};

