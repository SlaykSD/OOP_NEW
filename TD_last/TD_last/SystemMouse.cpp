#include "SystemMouse.h"
#include <iostream>
bool SystemMouse::handleEvent(const sf::Event& event)
{
	if (event.type == Event::MouseButtonPressed)
	{
		if (event.key.code == Mouse::Right)
		{
			std::cout << "right" << std::endl;
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
bool SystemMouse::update(sf::Time dt)
{
	return true;
}