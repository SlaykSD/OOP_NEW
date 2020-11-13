#pragma once
#include <string>
#include <vector>
#include <map>
#include <SFML/Graphics.hpp>
#include <iostream>
#include "tinyxml/tinyxml.h"
#include "State.h"
#include "Grid.h"
#include <list>
#include <map>

struct RoadOjects 
{
	std::map<std::string,std::list <sf::Vector2i>> roads;
};

class Level//главный класс - уровень
{
public:
	Level();
	Level(std::string filename);
	bool LoadFromFile(std::string filename);//возвращает false если не получилось загрузить
	void DrawMap(sf::RenderWindow& window);//рисуем в окно
	void DrawGrid(sf::RenderWindow& window);//риусем объекты
	sf::Vector2i GetTileSize();//получаем размер тайла
	bool setTower(sf::Vector2i Position, sf::RenderWindow* window);
	const Grid& getGrid()const { return logicalGrid;}
	std::map<std::string, std::list <sf::Vector2i>>* getRoad(){ return &roadList.roads; }
private:
	int findRoadID(int ID)const;
	int findCastleID(int ID)const;
	int findLierID(int ID)const;
	int width, height, tileWidth, tileHeight;//в tmx файле width height в начале,затем размер тайла
	int firstTileID;//получаем айди первого тайла
	sf::Rect<float> drawingBounds;//размер части карты которую рисуем
	RoadOjects roadList;
	sf::Texture tilesetImage;//текстура карты
	std::vector<Layer> layers;//Тайлы (карта сама)
	Grid logicalGrid;
	Objects obj;
};

const int roadID[]
{
	153,154,155,156,
	176,177,178,179,
	199,200,201,202,
	222,223,224,225
};
const int N = sizeof(roadID) / sizeof(roadID[0]);

const int castleID[]
{
	40,44,63,67,
	86,90,109,113
};
const int Nl = sizeof(roadID) / sizeof(roadID[0]);

const int lierID[]
{
	41,64,87,110,
	45,68,91,114
};
const int Nc = sizeof(roadID) / sizeof(roadID[0]);

