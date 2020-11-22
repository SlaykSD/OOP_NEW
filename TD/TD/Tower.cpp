#include "Tower.h"
#include "EntityManager.h"

Tower::Tower(const Tile* tile, TowerType typ):Bulding(tile),LEVEL_MAX(2), level(1),table(), type(typ)
{
	int t = type;
	setTexture(t);
	sf::Rect <int> rect(0,0,64,64);
	_tile.setTexture(texturpack[0], rect);

}
void Tower::update(sf::Time)
{

}
void Tower ::draw(sf::RenderWindow* window)
{
	_tile.setTexture(texturpack[level - 1]);
	window->draw(_tile.getSprite());
}

void Tower::setTexture(int type)
{
	if (type == 1)
	{
		sf::Image widget; //создаем объект Image (изображение)
		widget.loadFromFile("simple_tower.png");//загружаем в него файл
		widget.createMaskFromColor(sf::Color(255, 255, 255));
		sf::Texture textur;
		textur.loadFromImage(widget);
		sf::Image widget2; //создаем объект Image (изображение)
		widget2.loadFromFile("simple_tower_2.png");//загружаем в него файл
		widget2.createMaskFromColor(sf::Color(255, 255, 255));
		sf::Texture textur2;
		textur2.loadFromImage(widget2);

		texturpack.push_back(textur);
		texturpack.push_back(textur2);
		table.type_ef = EffectType::none;
	}
	if (type == 2)//frost
	{
		sf::Image widget; //создаем объект Image (изображение)
		widget.loadFromFile("magic_tower_f.png");//загружаем в него файл
		widget.createMaskFromColor(sf::Color(255, 255, 255));
		sf::Texture textur;
		textur.loadFromImage(widget);
		sf::Image widget2; //создаем объект Image (изображение)
		widget2.loadFromFile("magic_tower_f_2.jpg");//загружаем в него файл
		widget2.createMaskFromColor(sf::Color(255, 255, 255));
		sf::Texture textur2;
		textur2.loadFromImage(widget2);

		texturpack.push_back(textur);
		texturpack.push_back(textur2);
		table.type_ef = EffectType::frost;
	}
	if (type == 3)//frost
	{
		sf::Image widget; //создаем объект Image (изображение)
		widget.loadFromFile("magic_tower_p.png");//загружаем в него файл
		widget.createMaskFromColor(sf::Color(255, 255, 255));
		sf::Texture textur;
		textur.loadFromImage(widget);
		sf::Image widget2; //создаем объект Image (изображение)
		widget2.loadFromFile("magic_tower_p_2.jpg");//загружаем в него файл
		widget2.createMaskFromColor(sf::Color(255, 255, 255));
		sf::Texture textur2;
		textur2.loadFromImage(widget2);

		texturpack.push_back(textur);
		texturpack.push_back(textur2);
		table.type_ef = EffectType::poison;
	}
	if (type == 4)//frost
	{
		sf::Image widget; //создаем объект Image (изображение)
		widget.loadFromFile("magic_tower_m.png");//загружаем в него файл
		widget.createMaskFromColor(sf::Color(255, 255, 255));
		sf::Texture textur;
		textur.loadFromImage(widget);
		sf::Image widget2; //создаем объект Image (изображение)
		widget2.loadFromFile("magic_tower_m_2.jpg");//загружаем в него файл
		widget2.createMaskFromColor(sf::Color(255, 255, 255));
		sf::Texture textur2;
		textur2.loadFromImage(widget2);

		texturpack.push_back(textur);
		texturpack.push_back(textur2);
		table.type_ef = EffectType::m_weakness;
	}
}

void Tower::lvlUP()
{
	if (level + 1 <= LEVEL_MAX)
	{
		this->level++;
		table.up();
	}
}

bool TableStateTower::up()
{
	damage += 30;
	attackSpeed += 0.2;
	range += 40;
	return true;
}
Tower::Tower(const Tower& c)
{
	if (this != &c)
	{
		this->_tile = c._tile;
		this->level = c.level;
		this->type = c.type;
		this->texturpack = c.texturpack;
		this->table = c.table;
	}
}
const Tower& Tower::operator=(const Tower& c) 
{
	if (this != &c)
	{
		this->_tile = c._tile;
		this->level = c.level;
		this->type = c.type;
		this->texturpack = c.texturpack;
		this->table = c.table;
	}
	return *this;
}