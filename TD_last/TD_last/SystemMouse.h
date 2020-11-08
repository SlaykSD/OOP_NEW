#pragma once
#include <SFML/Graphics.hpp>
#include "Grid.h"
#include "level.h"
class SystemMouse : public State
{
public:
	virtual bool handleEvent(const sf::Event& event);
	virtual bool update(sf::Time dt);
	void setLvl(Level* lev) { lvl = lev; }
private:
	int state[4];// 0 - ��������� , 1- ���������, 2- ��������, 4- ���������
	Level* lvl;
	sf::Mouse cursor;
};

