#include "level.h"
///////////////////////////////////////
Level::Level():width(0),height(0),tileHeight(0),tileWidth(0),firstTileID(0)
{ }
Level::Level(std::string filename):Level()
{
	this->LoadFromFile(filename);
}
bool Level::LoadFromFile(std::string filename)//двоеточия-обращение к методам класса вне класса 
{
	TiXmlDocument levelFile(filename.c_str());//загружаем файл в TiXmlDocument

	// загружаем XML-карту
	if (!levelFile.LoadFile())//если не удалось загрузить карту
	{
		std::cout << "Loading level \"" << filename << "\" failed." << std::endl;//выдаем ошибку
		return false;
	}

	// работаем с контейнером map
	TiXmlElement* map;
	map = levelFile.FirstChildElement("map");

	// пример карты: <map version="1.0" orientation="orthogonal"
	// width="10" height="10" tilewidth="34" tileheight="34">
	width = atoi(map->Attribute("width"));//извлекаем из нашей карты ее свойства
	height = atoi(map->Attribute("height"));//те свойства, которые задавали при работе в 
	tileWidth = atoi(map->Attribute("tilewidth"));//тайлмап редакторе
	tileHeight = atoi(map->Attribute("tileheight"));

	// Берем описание тайлсета и идентификатор первого тайла
	TiXmlElement* tilesetElement;
	tilesetElement = map->FirstChildElement("tileset");
	firstTileID = atoi(tilesetElement->Attribute("firstgid"));

	// source - путь до картинки в контейнере image
	TiXmlElement* image;
	image = tilesetElement->FirstChildElement("image");
	std::string imagepath = image->Attribute("source");

	// пытаемся загрузить тайлсет
	sf::Image img;

	if (!img.loadFromFile(imagepath))
	{
		std::cout << "Failed to load tile sheet." << std::endl;//если не удалось загрузить тайлсет-выводим ошибку в консоль
		return false;
	}


	img.createMaskFromColor(sf::Color(255, 255, 255));//для маски цвета.сейчас нет маски
	tilesetImage.loadFromImage(img);
	tilesetImage.setSmooth(false);//сглаживание

	// получаем количество столбцов и строк тайлсета
	int columns = tilesetImage.getSize().x / tileWidth;
	int rows = tilesetImage.getSize().y / tileHeight;

	// вектор из прямоугольников изображений (TextureRect)
	std::vector<sf::Rect<int>> subRects;

	for (int y = 0; y < rows; y++)
		for (int x = 0; x < columns; x++)
		{
			sf::Rect<int> rect;

			rect.top = y * tileHeight;
			rect.height = tileHeight;
			rect.left = x * tileWidth;
			rect.width = tileWidth;

			subRects.push_back(rect);
		}

	this->logicalGrid.setRectGrid(subRects);
	// работа со слоями
	TiXmlElement* layerElement;
	layerElement = map->FirstChildElement("layer");

	Objects* obj = new Objects; // Структура с объектами сетки:D

	while (layerElement)
	{
		Layer layer;

		// если присутствует opacity, то задаем прозрачность слоя, иначе он полностью непрозрачен
		if (layerElement->Attribute("opacity") != NULL)
		{
			float opacity = strtod(layerElement->Attribute("opacity"), NULL);
			layer.opacity = 255 * opacity;
		}
		else
		{
			layer.opacity = 255;
		}

		//  контейнер <data> 
		TiXmlElement* layerDataElement;
		layerDataElement = layerElement->FirstChildElement("data");

		if (layerDataElement == NULL)
		{
			std::cout << "Bad map. No layer information found." << std::endl;
		}

		//  контейнер <tile> - описание тайлов каждого слоя
		TiXmlElement* tileElement;
		tileElement = layerDataElement->FirstChildElement("tile");

		if (tileElement == NULL)
		{
			std::cout << "Bad map. No tile information found." << std::endl;
			return false;
		}

		int x = 0;
		int y = 0;

		while (tileElement)
		{
			int tileGID = atoi(tileElement->Attribute("gid"));
			int subRectToUse = tileGID - firstTileID;
			//Ищем ID объектов
			int roadIDentifcation = findRoadID(subRectToUse), lierIDentifcation = -1, castleIDentifcation=-1;
			if (roadIDentifcation < 0)
			{
				lierIDentifcation = findLierID(subRectToUse);
				if (lierIDentifcation < 0)
				{
					castleIDentifcation = findCastleID(subRectToUse);
				}
			}
			// Устанавливаем TextureRect каждого тайла
			if (subRectToUse >= 0)
			{
				sf::Sprite sprite;
				sprite.setTexture(tilesetImage);
				sprite.setTextureRect(subRects[subRectToUse]);
				sprite.setPosition(x * tileWidth, y * tileHeight);
				sprite.setColor(sf::Color(255, 255, 255, layer.opacity));

				if (roadIDentifcation > 0)
					obj->roads.push_back(sprite);
				if (lierIDentifcation > 0)
					obj->liers.push_back(sprite);
				if (castleIDentifcation > 0)
					obj->castles.push_back(sprite);

				layer.tiles.push_back(sprite);//закидываем в слой спрайты тайлов
			}
			tileElement = tileElement->NextSiblingElement("tile");

			x++;
			if (x >= width)
			{
				x = 0;
				y++;
				if (y >= height)
					y = 0;
			}
		}

		layers.push_back(layer);

		layerElement = layerElement->NextSiblingElement("layer");
	}
	logicalGrid.setTiles(layers, width, height,obj);
	logicalGrid.setTexture(this->tilesetImage);
	delete obj;
	
	return true;
}

sf::Vector2i Level::GetTileSize()
{
	return sf::Vector2i(tileWidth, tileHeight);
}
void Level::DrawGrid(sf::RenderWindow& window)//риусем объекты
{
	logicalGrid.draw(window);
}
void Level::DrawMap(sf::RenderWindow& window)
{
	// рисуем все тайлы (объекты не рисуем!)
	for (int layer = 0; layer < layers.size(); layer++)
		for (int tile = 0; tile < layers[layer].tiles.size(); tile++)
			window.draw(layers[layer].tiles[tile]);
}
bool Level::handleEvent(const sf::Event& event)
{
	return true;
}
bool Level::update(sf::Time dt)
{
	return true;
}
int Level::findRoadID(int ID)const
{
	for(int i = 0; i < N; ++i)
		if(ID == roadID[i])
			return ID;
	return -1;
}
int Level::findCastleID(int ID)const
{
	for (int i = 0; i < Nc; ++i)
		if (ID == castleID[i])
			return ID;
	return -1;
}
int Level::findLierID(int ID)const
{
	for (int i = 0; i < Nl; ++i)
		if (ID == lierID[i])
			return ID;
	return -1;
}

bool Level:: setTower(sf::Vector2i Position, sf::RenderWindow* window)
{
	this->logicalGrid.setTextureTower(Position, window);
	return true;
}