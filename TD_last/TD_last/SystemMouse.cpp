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
			lvl->setTower(vec, window);
			this->curr = lvl->getGrid().getTile(vec.y / lvl->GetTileSize().y, vec.x/lvl->GetTileSize().x).getSprite();
			std::cout << "right-click - succesfuly" << std::endl;
			return true;
		}
		//����� ������ ���� �������� ����� ��������� � ����� ����������� ��� ���������

		if (event.key.code == Mouse::Left)
		{
			std::cout << "left" << std::endl;
			return true;//����� ������ ���� ��������� ��������� ��������
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
void SystemMouse::draw(sf::RenderWindow& window)
{
	window.draw(curr);
}