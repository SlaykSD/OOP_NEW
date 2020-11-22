#pragma once
#include "Trap.h"
#include "Lier.h"
#include "Castle.h"
#include "Tower.h"
#include "level.h"
#include "Score.h"
#include <iostream>
#include <SFML/Graphics.hpp>

class Trap;
class Lier;
class Castle;
class Tower;

class EntityManager
{
public:
	
	EntityManager(Level&);
	bool setParameters(Level lvl);
	bool update(sf::Time frameTime);
	void draw(sf::RenderWindow* window);
	void addTower(Tower tower);
	int getGold()const;
	//void addTrap(Tower tower);
private:
	void addState(Entity* state);
	Score score;
	std::vector<Entity*> _entities;
	std::vector<Trap> traps;
	std::vector<Lier> liers;
	std::vector <Castle> castles;
	std::vector<Tower> towers;
};
