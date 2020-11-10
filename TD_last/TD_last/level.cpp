#include "level.h"
///////////////////////////////////////
Level::Level():width(0),height(0),tileHeight(0),tileWidth(0),firstTileID(0)
{ }
Level::Level(std::string filename):Level()
{
	this->LoadFromFile(filename);
}
bool Level::LoadFromFile(std::string filename)//���������-��������� � ������� ������ ��� ������ 
{
	TiXmlDocument levelFile(filename.c_str());//��������� ���� � TiXmlDocument

	// ��������� XML-�����
	if (!levelFile.LoadFile())//���� �� ������� ��������� �����
	{
		std::cout << "Loading level \"" << filename << "\" failed." << std::endl;//������ ������
		return false;
	}

	// �������� � ����������� map
	TiXmlElement* map;
	map = levelFile.FirstChildElement("map");

	// ������ �����: <map version="1.0" orientation="orthogonal"
	// width="10" height="10" tilewidth="34" tileheight="34">
	width = atoi(map->Attribute("width"));//��������� �� ����� ����� �� ��������
	height = atoi(map->Attribute("height"));//�� ��������, ������� �������� ��� ������ � 
	tileWidth = atoi(map->Attribute("tilewidth"));//������� ���������
	tileHeight = atoi(map->Attribute("tileheight"));

	// ����� �������� �������� � ������������� ������� �����
	TiXmlElement* tilesetElement;
	tilesetElement = map->FirstChildElement("tileset");
	firstTileID = atoi(tilesetElement->Attribute("firstgid"));

	// source - ���� �� �������� � ���������� image
	TiXmlElement* image;
	image = tilesetElement->FirstChildElement("image");
	std::string imagepath = image->Attribute("source");

	// �������� ��������� �������
	sf::Image img;

	if (!img.loadFromFile(imagepath))
	{
		std::cout << "Failed to load tile sheet." << std::endl;//���� �� ������� ��������� �������-������� ������ � �������
		return false;
	}


	img.createMaskFromColor(sf::Color(255, 255, 255));//��� ����� �����.������ ��� �����
	tilesetImage.loadFromImage(img);
	tilesetImage.setSmooth(false);//�����������

	// �������� ���������� �������� � ����� ��������
	int columns = tilesetImage.getSize().x / tileWidth;
	int rows = tilesetImage.getSize().y / tileHeight;

	// ������ �� ��������������� ����������� (TextureRect)
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
	// ������ �� ������
	TiXmlElement* layerElement;
	layerElement = map->FirstChildElement("layer");

	Objects* obj = new Objects; // ��������� � ��������� �����:D

	while (layerElement)
	{
		Layer layer;

		// ���� ������������ opacity, �� ������ ������������ ����, ����� �� ��������� �����������
		if (layerElement->Attribute("opacity") != NULL)
		{
			float opacity = strtod(layerElement->Attribute("opacity"), NULL);
			layer.opacity = 255 * opacity;
		}
		else
		{
			layer.opacity = 255;
		}

		//  ��������� <data> 
		TiXmlElement* layerDataElement;
		layerDataElement = layerElement->FirstChildElement("data");

		if (layerDataElement == NULL)
		{
			std::cout << "Bad map. No layer information found." << std::endl;
		}

		//  ��������� <tile> - �������� ������ ������� ����
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
			//���� ID ��������
			int roadIDentifcation = findRoadID(subRectToUse), lierIDentifcation = -1, castleIDentifcation=-1;
			if (roadIDentifcation < 0)
			{
				lierIDentifcation = findLierID(subRectToUse);
				if (lierIDentifcation < 0)
				{
					castleIDentifcation = findCastleID(subRectToUse);
				}
			}
			// ������������� TextureRect ������� �����
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

				layer.tiles.push_back(sprite);//���������� � ���� ������� ������
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
void Level::DrawGrid(sf::RenderWindow& window)//������ �������
{
	logicalGrid.draw(window);
}
void Level::DrawMap(sf::RenderWindow& window)
{
	// ������ ��� ����� (������� �� ������!)
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