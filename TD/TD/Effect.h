#pragma once
#include <SFML/Graphics.hpp>
#include "EffectType.h"
class Enemy;

class Effect
{
public:
	Effect() = default;
	Effect(EffectType, float* hp, float* speed, float* incDamage);
	Effect(const Effect& c);
	const Effect& operator=(const Effect& c);
	void update(sf::Time, float*);
	void returnState(float*, float*);
	EffectType getType()const { return type; }
	void setTime(sf::Time newTime) { time = newTime; }
	bool checkTime();
private:
	EffectType type;
	int quantity;
	sf::Time time;
	const sf::Time TIME_MAX = sf::seconds(2.f);
	float real_speed;
	sf::Time coldown;
};

