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