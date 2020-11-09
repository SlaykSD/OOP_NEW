#pragma once
#include <SFML/Graphics.hpp>
#include "Grid.h"
#include "level.h"
class SystemMouse : public State
{
public:
	virtual bool handleEvent(const sf::Event& event);
	virtual bool update(sf::Time dt);
	void draw(sf::RenderWindow& window);
	void setLvl(Level* lev) { lvl = lev; }
	void setWindow(sf::RenderWindow* windows) { window = windows; }
private:
	int state[4];// 0 - ��������� , 1- ���������, 2- ��������, 4- ���������
	Level* lvl;
	sf::Sprite curr;
	sf::RenderWindow* window;
	sf::Mouse cursor;
};

