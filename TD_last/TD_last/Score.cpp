#include "Score.h"
#include <string>
#include <iostream>
Score::Score():score(0),gold(300)
{
	if (!font.loadFromFile("CyrilicOld.ttf"))
	{
		std::cout << "Error of downdload FONT of the text" << std::endl;
	}
	textGold.setFont(font);
	textGold.setCharacterSize(30);
	textScore.setFont(font);
	textScore.setCharacterSize(30);
	sf::Vector2i pos,pos0;
	pos0.x = 64 * 1;
	pos.x = 64 * 5;
	textGold.setPosition(pos.x, pos.y);
	textScore.setPosition(pos0.x, pos0.y);
}
void Score::update(sf::Time)
{

}

void  Score::draw(sf::RenderWindow* window)
{
	std::string strGold = "Your money: "+std::to_string(gold);
	textGold.setString(strGold);
	std::string strScore = "Score: " + std::to_string(score);
	textScore.setString(strScore);
	window->draw(textGold);
	window->draw(textScore);
}