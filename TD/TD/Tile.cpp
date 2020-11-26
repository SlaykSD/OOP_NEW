#include "Tile.h"


void Tile::setState(int i) {
	
	switch (i)
	{
	case(0):
		state = Type::forest;
		break;
	case(1):
		state = Type::road;
		break;
	case(2):
		state = Type::castle;
		break;
	case(3):
		state = Type::lier;
		break;
	case(4):
		state = Type::tower;
		break;
	}
}
int Tile:: getTileNumber()const
{
	return tileNumber;
}
void Tile::setTileNumber(int numb) 
{
	tileNumber = numb;
}
void Tile::setTexture(sf::Texture& t, sf::IntRect rect)
{
	this->sprite.setTexture(t);
	this->sprite.setTextureRect(rect);
}
int Tile::getState() const
{
	return state;
}
const sf::Sprite Tile::getSprite()const
{
	return sprite;
}
int Tile::getDraw(sf::RenderWindow* window)const
{
	window->draw(sprite);
	return 10;
}

bool Tile::setMagicTower(int type)
{
	if (type == 2)//frost
	{
		sf::Image widget; //создаем объект Image (изображение)
		widget.loadFromFile("magic_tower_f.png");//загружаем в него файл
		widget.createMaskFromColor(sf::Color(255, 255, 255));
		sf:: Texture textur;
		textur.loadFromImage(widget);
		sprite.setTexture(textur);
		sprite.setTextureRect(sf::IntRect(0, 0, 64, 64));
		return true;
	}
	if (type == 3)//frost
	{
		sf::Image widget; //создаем объект Image (изображение)
		widget.loadFromFile("magic_tower_p.png");//загружаем в него файл
		widget.createMaskFromColor(sf::Color(255, 255, 255));
		sf::Texture textur;
		textur.loadFromImage(widget);
		sprite.setTexture(textur);
		sprite.setTextureRect(sf::IntRect(0, 0, 64, 64));
	}
	if (type == 4)//frost
	{
		sf::Image widget; //создаем объект Image (изображение)
		widget.loadFromFile("magic_tower_m.png");//загружаем в него файл
		widget.createMaskFromColor(sf::Color(255, 255, 255));
		sf::Texture textur;
		textur.loadFromImage(widget);
		sprite.setTexture(textur);
		sprite.setTextureRect(sf::IntRect(0, 0, 64, 64));
	}

}
void Tile::setOrigin(float w, float h)
{
	sprite.setOrigin(w, h);
}
const sf::Sprite* Tile::getSpriteV()
{
	return &sprite;
}
void Tile::setRotation(float angle)
{
	sprite.setRotation(angle);
}
void Tile::setPositionToCenter()
{
	sf::Vector2f pos = sprite.getPosition();
	sf::Vector2f center(sprite.getTextureRect().width / 2, sprite.getTextureRect().height / 2);
	pos = pos + center;
	sprite.setPosition(pos);
}
//Tile& Tile::operator= (const Tile& t)
//{
//
//}

//const Tile& Tile::operator=(const Tile&)
//{
//	;
//}