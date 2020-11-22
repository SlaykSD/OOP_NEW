#include "Enemy.h"


void Enemy::update(sf::Time dt)
{
	if (visible)
	{
		std::list <sf::Vector2i>::iterator it = checkPoints.begin();
		if (points == 0)
		{
			checkPoints.erase(it);
			it = checkPoints.begin();
			points++;
		}
		if (!checkPoints.empty())
		{
			if ((int)sprite.getPosition().x != (*it).x)
			{
				if (sprite.getPosition().x < (*it).x)
				{
					float fluctuation_x = sprite.getPosition().x + dt.asSeconds() * this->speed;
					if (fluctuation_x > (*it).x)
						fluctuation_x = (*it).x;
					sprite.setPosition(fluctuation_x, sprite.getPosition().y);
				}
				else
				{
					float fluctuation_x = sprite.getPosition().x - dt.asSeconds() * this->speed;
					if (fluctuation_x < (*it).x)
						fluctuation_x = (*it).x;
					sprite.setPosition(fluctuation_x, sprite.getPosition().y);
				}
			}
			if ((int)sprite.getPosition().y != (*it).y)
			{
				if (sprite.getPosition().y < (*it).y)
				{
					float fluctuation_y = sprite.getPosition().y + dt.asSeconds() * this->speed;
					if (fluctuation_y > (*it).y)
						fluctuation_y = (*it).y;
					sprite.setPosition(sprite.getPosition().x,fluctuation_y);
				}
				else
				{
					float fluctuation_y = sprite.getPosition().y - dt.asSeconds() * this->speed;
					if (fluctuation_y < (*it).y)
						fluctuation_y = (*it).y;
					sprite.setPosition(sprite.getPosition().x, fluctuation_y);
				}
			}
			if (((int)sprite.getPosition().y == (*it).y) && ((int)sprite.getPosition().x == (*it).x))
			{
				checkPoints.erase(it);
			}
		}
	}
}
Enemy::Enemy() :HP_MAX(250), hp(250), money(40), speed(100.f), visible(false), points(0)
{
}
Enemy::Enemy(std::list <sf::Vector2i> Points, EnemyType Type) : Enemy()
{
	name = Type;
	checkPoints = Points;
	sf::Vector2f pos;
	std::list <sf::Vector2i>::iterator it = Points.begin();
	pos.x = (*it).x;
	pos.y = (*it).y;
	sprite.setPosition(pos);
}