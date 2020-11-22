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
	int state[4];// 0 - улучшение , 1- постройка, 2- удаление, 4- веделение
	Level *lvl;
	sf::Sprite curr;
	sf::RenderWindow* window;

};

