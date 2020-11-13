#include "EntityManager.h"
#include "Tile.h"
#include "Grid.h"
#include <math.h>
EntityManager::EntityManager()
{

}

bool EntityManager::setParameters(Level* lvl)
{
	//	lvl.getGrid().getTile()
	std::vector<std::vector<Tile>> tileMap = lvl->getGrid().getTiles();
	int size_y = tileMap.size();
	int size_x = tileMap[0].size();
	std::vector <Tile> road;
	for (int i = 0; i < size_y; i++)
	{
		for (int j = 0; j < size_x; j++)
		{
			//road- 1, castle -2, lier -3, tower -4
			switch (tileMap[i][j].getState())
			{
			case(1):
				road.push_back(tileMap[i][j]);
				break;
			case(2):
				Castle  castle(&tileMap[i][j]);
				this->castles.push_back(castle);
				break;
			case(3):
				Lier lier(&tileMap[i][j]);
				this->liers.push_back(lier);
				break;
			case(4):
				Tower tower(&tileMap[i][j]);
				this->towers.push_back(tower);
				break;
			}
		}
	}
	std::vector<Tile>::iterator it = road.begin();
	std::vector<Tile>::iterator it2 = road.begin();
	for (it; it != road.end(); ++it)
	{
		Tile min = *it;
		for (it2; it2!=road.end(); ++it2)
		{
			Vector2f pos2 = (*it2).getSprite().getPosition();
			Vector2f pos1= (*it).getSprite().getPosition();
			if (sqrt(pos2.x *pos2.x +pos2.y*pos2.y) < sqrt(pos1.x * pos1.x + pos1.y * pos1.y))
			{
				min = *it2;
			}
		}
		road.erase()
	}
	return true;
}
bool EntityManager::update(sf::Time frameTime)
{
	return true;
}