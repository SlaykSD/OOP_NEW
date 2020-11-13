#pragma once
#include "Trap.h"
#include "Lier.h"
#include "Castle.h"
#include "Tower.h"
#include "level.h"
#include <iostream>
#include <SFML/Graphics.hpp>

class Trap;
class Lier;
class Castle;
class Tower;

class EntityManager
{
public:
	EntityManager();
	bool setParameters(Level* lvl);
	bool update(sf::Time frameTime);

private:
	int  sortSimpleRoad(std::vector <Tile>);
	std::vector<Trap> traps;
	std::vector<Lier> liers;
	std::vector <Castle> castles;
	std::vector<Tower> towers;
};

