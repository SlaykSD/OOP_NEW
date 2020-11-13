#pragma warning(disable : 4996)
#include "Lier.h"
#include <iostream>
Lier::Lier(const Tile* tile, std::list <sf::Vector2i> list ):Bulding(tile),numberWaves(3), beginTime (Time::Zero), checkPoints (list),wave(0)
{

}
void Lier::draw(sf::RenderWindow* window)
{
	if (!font.loadFromFile("CyrilicOld.ttf"))
	{
		std::cout << "Error of downdload FONT of the text" << std::endl;
	}
	textLier.setFont(font);
	textLier.setCharacterSize(24);
	//textLier.setColor(Color::Magenta);
	sf::Vector2f pos;
	pos = this->getTile()->getSprite().getPosition();
	pos.x -= 10;
	pos.y -= 10;
	textLier.setPosition(pos.x, pos.y);
	std::string strLier = std::to_string(this->wave) + "/" + std::to_string(this->numberWaves);
	textLier.setString(strLier);
	window->draw(textLier);
}
void Lier::update(sf::Time frameTime)
{
	beginTime += frameTime;
}