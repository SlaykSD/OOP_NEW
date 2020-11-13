#pragma once
#include <SFML/Graphics.hpp>
#include "level.h"

class SystemMouse : public State
{
public:
	SystemMouse(sf::RenderWindow*);
	virtual bool handleEvent(const sf::Event& event);
	virtual bool update(sf::Time dt);
	void draw(sf::RenderWindow& window);
	void setLvl(Level* lev) { lvl = lev; }
private:
	int state[4];// 0 - ��������� , 1- ���������, 2- ��������, 4- ���������
	Level *lvl;
	sf::Sprite curr;
	sf::RenderWindow* window;

};

