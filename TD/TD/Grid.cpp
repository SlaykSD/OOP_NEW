#include <iostream>
#include "Grid.h"
class Tile;
/**
 * Grid implementation
 */
Grid::Grid() :_height(10), _width(10), tileHeight(64), tileWidth(64)
{
}
Grid::Grid(const Grid& grid) : Grid()
{
	std::vector<std::vector<Tile>> copy = grid.getTiles();
	this->setTiles(copy);
}
bool Grid::setTiles(std::vector<Layer> tmp, int width, int height, Objects* obj)
{
	//�������� ��� ����� �������
	_width = width;
	_height = height;
	try {
		int n = 0;
		for (int i = 0; i < height; ++i)
		{
			std::vector<Tile> newTileList;
			for (int j = 0; j < width; j++)
			{
				sf::Sprite newTile(tmp[0].tiles[n]);
				/*newTile.setPosition(tmp[0].tiles[n].getPosition());
				newTile.setColor(tmp[0].tiles[n].getColor());*/

				Tile tile;
				tile.setTileNumber(n);
				tile.setState(findObjects(obj, tmp[0].tiles[n]));
				tile.setSprite(newTile);
				//tile.setTexture(texture, subRects[n]);
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
const Tile* Grid::getTile(int i, int j)const
{
	return &tileMap[i][j];
}

void Grid::draw(sf::RenderWindow& window) {
	for (int i = 0; i < _height; i++)
	{
		for (int j = 0; j < _width; j++)
		{
			window.draw(tileMap[i][j].getSprite());
		}
	}
}

int Grid::findObjects(Objects* obj, sf::Sprite tile)
{
	int size = obj->roads.size();
	for (int i = 0; i < size; i++)
	{
		if (obj->roads[i].getPosition() == tile.getPosition())
			return 1;
	}
	size = obj->castles.size();
	for (int i = 0; i < size; i++)
	{
		if (obj->castles[i].getPosition() == tile.getPosition())
			return 2;
	}
	size = obj->liers.size();
	for (int i = 0; i < size; i++)
	{
		if (obj->liers[i].getPosition() == tile.getPosition())
			return 3;
	}
	return 0;
}
int Grid::setTextureTower(sf::Vector2i Position, int type)
{
	try {
		int x = Position.x / tileWidth, y = Position.y / tileHeight;
		if (type > 0)
		{
			tileMap[y][x].setState(4);
		}
		else
		{
			tileMap[y][x].setState(0);
		}
		return 1;
	}
	catch (...)
	{
		std::cout << "Probably need set tileWeight and tile Height" << std::endl;
		return 0;
	}
}
bool Grid::setSpriteMagic(int type, int x, int y)
{
	sf::Image widget; //������� ������ Image (�����������)
	sf::Sprite sprite;
	sf::Texture textur;
	if (type == 2)//frost
	{
		widget.loadFromFile("magic_tower_f.png");//��������� � ���� ����
		widget.createMaskFromColor(sf::Color(255, 255, 255));
		textur.loadFromImage(widget);
		sprite.setTexture(textur);
		sprite.setTextureRect(sf::IntRect(0, 0, 64, 64));
		return true;
	}
	if (type == 3)//frost
	{
		widget.loadFromFile("magic_tower_p.png");//��������� � ���� ����
		widget.createMaskFromColor(sf::Color(255, 255, 255));
		textur.loadFromImage(widget);
		sprite.setTexture(textur);
		sprite.setTextureRect(sf::IntRect(0, 0, 64, 64));
	}
	if (type == 4)//frost
	{
		widget.loadFromFile("magic_tower_m.png");//��������� � ���� ����
		widget.createMaskFromColor(sf::Color(255, 255, 255));
		textur.loadFromImage(widget);
		sprite.setTexture(textur);
		sprite.setTextureRect(sf::IntRect(0, 0, 64, 64));
	}
	tileMap[y][x].setTexture(textur, sprite.getTextureRect());
	return true;
}
void Grid::setTexture(sf::Texture t)
{
	texture = t;
}

void Grid::setRectGrid(std::vector<sf::Rect<int>> rectG)
{
	this->subRects = rectG;
}