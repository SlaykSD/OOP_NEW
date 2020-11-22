#pragma once
#include "Entity.h"
class Score:public Entity
{
public:
	Score();
	virtual void update(sf::Time);
	int  getGold()const;
	void draw(sf::RenderWindow* window);
	bool setGold(int);
private:
	sf::Font font;
	sf::Text textGold;
	sf::Text textScore;
	int gold;
	int score;

};

