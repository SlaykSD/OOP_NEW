#include "Effect.h"
#include "Enemy.h"
#include <iostream>
void Effect::update(sf::Time dt, float* hp)
{
	time += dt;
	coldown += dt;
	if (time >= TIME_MAX)
	{
		time = TIME_MAX;
	}
	int t = type;
	const sf::Time maxTime = sf::seconds(1.2 / 7.f);
	if (t == 2)
	{
		if (coldown > maxTime)
		{
			coldown = sf::Time::Zero;
			*hp -= (float)quantity / 10.f;
			std::cout << " Give damage " << *hp << std::endl;
		}
	}
}

void Effect::returnState( float* speed, float* incDamage)
{
	int t = type;
	if (t == 1)
	{
		*speed = real_speed;
	}
	if (t == 3)
	{
		*incDamage = 0;
	}
}
Effect::Effect(EffectType typ, float* hp, float* speed, float* incDamage) : quantity(30), time(sf::Time::Zero), type(typ), real_speed(0)
{
	int t = type;
	switch (t)
	{
	case(1):
		//target->setColor(sf::Color::Blue);
		real_speed = *speed;
		(*speed) = ((real_speed) * (1 - ((float)quantity / 100)));
		break;
	case(2):
		//target->setColor(sf::Color::Green);
		//*hp -= quantity / 100;
		//target->setHP(real_hp);
		break;

	case(3):
		//target->setColor(sf::Color::Yellow);
		*incDamage = ((float)quantity / 100);
		break;
	default:
		break;
	}

}
bool Effect::checkTime()
{
	if (time == TIME_MAX)
		return true;
	return false;
}

Effect::Effect(const Effect& c) :Effect()
{
	if (this != &c)
	{
		quantity = c.quantity;
		type = c.type;
		time = c.time;
		real_speed = c.real_speed;
		coldown = c.coldown;
	}
}
const Effect& Effect::operator=(const Effect& c)
{
	if (this != &c)
	{
		quantity = c.quantity;
		type = c.type;
		time = c.time;
		real_speed = c.real_speed;
		coldown = c.coldown;
	}
	return *this;
}