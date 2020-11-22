#pragma once
#include "System.h"
#include "Entity.h"
class DamageSystem : public System
{
public:
	DamageSystem();
	~DamageSystem() = default;
	virtual void update(sf::Time);
private:
	std::vector<Entity*>liers;
};

