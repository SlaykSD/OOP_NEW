#include "EntityManager.h"
#include "Tile.h"
#include "Grid.h"
#include <math.h>
#include <string>

EntityManager::EntityManager(Level& lvl):score()
{
	std::vector<std::vector<Tile>> tileMap = lvl.getGrid().getTiles();
	int size_y = tileMap.size();
	int size_x = tileMap[0].size();
	std::map<std::string, std::list <sf::Vector2i>>* lierRoads = lvl.getRoad();
	for (int i = 0; i < size_y; i++)
	{
		for (int j = 0; j < size_x; j++)
		{
			//road- 1, castle -2, lier -3, tower -4
			if (tileMap[i][j].getState() == 2)
			{
				Castle  castle(&tileMap[i][j]);
				this->castles.push_back(castle);
			}
			if (tileMap[i][j].getState() == 3)
			{
				for (int k = 1; k <= lierRoads->size(); k++)
				{
					std::string key = "solid" + std::to_string(k);
					std::map<std::string, std::list <sf::Vector2i>>::iterator it_m = lierRoads->find(key);
					std::list <sf::Vector2i> tmp = (*it_m).second;
					std::list <sf::Vector2i>::iterator it = tmp.begin();
					if ((((*it).x - 32) == (int)tileMap[i][j].getSprite().getPosition().x) && (((*it).y - 32) == (int)tileMap[i][j].getSprite().getPosition().y))
					{
						Lier lier(&tileMap[i][j], tmp);
						this->liers.push_back(lier);
						break;
					}
				}
			}
			if (tileMap[i][j].getState() == 4)
			{
				Tower tower(&tileMap[i][j]);
				this->towers.push_back(tower);
			}
		}
	}
}

bool EntityManager::setParameters(Level lvl)
{
	//	lvl.getGrid().getTile()
	std::vector<std::vector<Tile>> tileMap = lvl.getGrid().getTiles();
	int size_y = tileMap.size();
	int size_x = tileMap[0].size();
	std::map<std::string, std::list <sf::Vector2i>>* lierRoads = lvl.getRoad();
	for (int i = 0; i < size_y; i++)
	{
		for (int j = 0; j < size_x; j++)
		{
			//road- 1, castle -2, lier -3, tower -4
			if (tileMap[i][j].getState() == 2)
			{
				Castle  castle(&tileMap[i][j]);
				this->castles.push_back(castle);
			}
			if (tileMap[i][j].getState() == 3)
			{
				for (int k = 1; k <= lierRoads->size(); k++)
				{
					std::string key = "solid" + std::to_string(k);
					std::map<std::string, std::list <sf::Vector2i>>::iterator it_m = lierRoads->find(key);
					std::list <sf::Vector2i> tmp = (*it_m).second;
					std::list <sf::Vector2i>::iterator it = tmp.begin();
					if ((((*it).x - 32) == (int)tileMap[i][j].getSprite().getPosition().x) && (((*it).y - 32 )== (int)tileMap[i][j].getSprite().getPosition().y))
					{
						Lier lier(&tileMap[i][j], tmp);
						this->liers.push_back(lier);
						break;
					}
				}
			}
			if (tileMap[i][j].getState() == 4)
			{
				Tower tower(&tileMap[i][j]);
				this->towers.push_back(tower);
			}
		}
	}
	return true;
}
bool EntityManager::update(sf::Time frameTime)
{
	int size = _entities.size();
	for (int i = 0; i < size; i++)
		_entities[i]->update(frameTime);
	return true;
}
void EntityManager::addState(Entity* enty)
{
	this->_entities.push_back(enty);
}
void EntityManager::draw(sf::RenderWindow* window)
{
	score.draw(window);
	std::vector<Tower>::iterator it= towers.begin();
	for (it; it!=towers.end(); ++it)
	{
		(*it).draw(window);
	}

	std::vector<Castle>::iterator it1 = castles.begin();
	for (it1; it1 != castles.end(); ++it1)
	{
		(*it1).draw(window);
	}
	std::vector<Lier>::iterator it2 = liers.begin();
	for (it2; it2 != liers.end(); ++it2)
	{
		(*it2).draw(window);
	}
	//this->towers.
	
}

int EntityManager::getGold()const
{
	return score.getGold();
}
void EntityManager::addTower(Tower tower)
{
	this->towers.push_back(tower);
}