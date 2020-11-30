#pragma once
#include "Trap.h"
#include "Lier.h"
#include "Castle.h"
#include "Tower.h"
#include "System.h"
#include "level.h"
#include "Score.h"
#include <iostream>
#include <SFML/Graphics.hpp>


const int WIDTH = 64,
HEIGHT = 64;
class GameState;
class Trap;
class Lier;
class Castle;
class Tower;
enum TowerType
{
	SimpleTower = 1, // ID- 249,250
	MagicTowerF,
	MagicTowerP,
	MagicTowerM
};
struct TableCostTower
{
	const enum SimpleTowerCost
	{
		S_TOWER_1 = 110,
		S_TOWER_2 = 150
	};
	const enum MagicTowerCost
	{
		M_TOWER_1_F = 150,
		M_TOWER_2_F = 170,
		M_TOWER_1_P = 130,
		M_TOWER_2_P = 150,
		M_TOWER_1_M = 120,
		M_TOWER_2_M = 150
	};
	const int costKillEnemy; //Возможно поменятеся
	TableCostTower() :costKillEnemy(20) { ; }
	const int getInfo(TowerType type, int)const;
};
class EntityManager
{
public:
	void destroyEnemy(Enemy*);
	EntityManager(Level&);
	bool setParameters(Level lvl);
	bool update(sf::Time frameTime);
	void draw(sf::RenderWindow* window);
	void addTower(Tower& tower);
	int getGold()const;
	int setGold(int);
	bool checkGold(TowerType, int);
	bool lvlUP(sf::Vector2i vec);
	bool removeTower(sf::Vector2i vec);
	//void addTrap(Tower tower);
	void addSystem(System*, int);
	std::vector<Lier*> getLiers();
	std::vector<Castle*> getCastles();
	std::vector<Trap*> getTraps();
	std::vector<Tower*> getTowers();
	//
	void setGState(GameState*);
private:
	void addSystems();
	void applyChanges();
	void addStates();
	int findTower(sf::Vector2i);
	void addState(Entity* state);
	GameState* gState;
	TableCostTower costTable;
	Score score;
	std::vector <System*> systems;
	std::vector<Entity*> _entities;
	std::vector<Trap> traps;
	std::vector<Lier> liers;
	std::vector<Castle> castles;
	std::vector<Tower> towers;
};

template< typename TContainer >
static bool EraseFromUnorderedByIndex(TContainer& inContainer, size_t inIndex)
{
	if (inIndex < inContainer.size())
	{
		if (inIndex != inContainer.size() - 1)
			inContainer[inIndex] = inContainer.back();
		inContainer.pop_back();
		return true;
	}
	return false;
}