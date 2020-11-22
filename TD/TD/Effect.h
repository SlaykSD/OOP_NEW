#pragma once
#include "Entity.h"
enum EffectType 
{
	none = 0,
	frost ,
	poison,
	m_weakness
};
class Effect:public Entity
{
public:
	virtual void update(sf::Time);
private:
	EffectType type;
	int quantity;
	int	time;
	const int TIME_MAX = 10;
};

