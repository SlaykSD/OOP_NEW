#include "LightInfantry.h"


LightInfantry::LightInfantry(std::list<sf::Vector2i> l) :Enemy(l,EnemyType::Light_Infantry)
{
	sf::Rect <int> rect(0, 0, 64, 64);
	sf::Image widget; //������� ������ Image (�����������)
	widget.loadFromFile("light_infantry.png");//��������� � ���� ����
	widget.createMaskFromColor(sf::Color(255, 255, 255));
	texture.loadFromImage(widget);
	sprite.setTexture(texture);
	sprite.setTextureRect(rect);
	n = 20;
}
void LightInfantry::draw(sf::RenderWindow* window)
{
	if (visible)
	{
		sprite.setTexture(texture);
		window->draw(sprite);
	}
}