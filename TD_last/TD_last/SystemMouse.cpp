#include "SystemMouse.h"
#include <iostream>
bool SystemMouse::handleEvent(const sf::Event& event)
{
	if (event.type == Event::MouseButtonPressed)
	{
		if (event.key.code == Mouse::Right)
		{
			std::cout << "right" << std::endl;
			sf::Vector2i vec = sf::Mouse::getPosition(*window);
			if (lvl->getGrid().getTile(vec.y / lvl->GetTileSize().y, vec.x / lvl->GetTileSize().x).getState() == 0)
			{
				lvl->setTower(vec, window);
				this->curr = lvl->getGrid().getTile(vec.y / lvl->GetTileSize().y, vec.x / lvl->GetTileSize().x).getSprite();
				std::cout << "right-click - succesfuly" << std::endl;
			}
			return true;
		}
		//Здесь должна быть обратока выбор постройки и выбор альтертатив для улучшения

		if (event.key.code == Mouse::Left)
		{
			std::cout << "left" << std::endl;
			return true;//Здесь должна быть обработка выделения строения
		}
	}
	else
	{
		return false;
	}
}
 SystemMouse::SystemMouse(sf::RenderWindow* window_):window(window_)
{}
bool SystemMouse::update(sf::Time dt)
{
	return true;
}
void SystemMouse::draw(sf::RenderWindow& window)
{
	window.draw(curr);
}