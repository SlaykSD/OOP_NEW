#include <iostream>
#include "Grid.h"
/**
 * Grid implementation
 */
Grid::Grid()
{
}
Grid::Grid(const Grid& grid)
{
	std::vector<std::vector<Tile>> copy = grid.getTiles();
	this->setTiles(copy);
}
bool Grid::pushTile()
{
	return true;
}
bool Grid::setTiles(std::vector<Layer> tmp, int width, int height, Objects* obj)
{
	//Копируем все кроме текстур
	_width = width;
	_height = height;
	try {
		int n = 0;
		for (int i = 0; i < height; ++i)
		{
			std::vector<Tile> newTileList;
			for (int j = 0; j < width; j++)
			{
				sf::Sprite newTile;
				newTile.setPosition(tmp[0].tiles[n].getPosition());
				newTile.setColor(tmp[0].tiles[n].getColor());

				Tile tile;
				tile.setTileNumber(n);
				tile.setState(findObjects(obj,tmp[0].tiles[n]));
				tile.setSprite(newTile);
				newTileList.push_back(tile);
				++n;
			}
			tileMap.push_back(newTileList);
		}
	}
	catch (...)
	{
		std::cout << "We have some trabl on setTiles";
		return false;
	}
	return true;
}
Tile Grid::getTile(int i, int j)
{
	return tileMap[i][j];
}

void Grid::draw() {

}

int Grid::findObjects(Objects* obj, sf::Sprite tile)
{
	int size = obj->roads.size();
	for (int i = 0; i < size; i++)
	{
		if (obj->roads[i]->getPosition() == tile.getPosition())
			return 1;
	}
	size = obj->castles.size();
	for (int i = 0; i < size; i++)
	{
		if (obj->castles[i]->getPosition() == tile.getPosition())
			return 2;
	}
	size = obj->liers.size();
	for (int i = 0; i < size; i++)
	{
		if (obj->liers[i]->getPosition() == tile.getPosition())
			return 3;
	}
	return 0;
}
