#pragma once
#include "System.h"
#include "Entity.h"
#include "Lier.h"
#include "Castle.h"
//#include "EntityManager.h"

class DamageSystem : public System
{
public:
	DamageSystem();
	DamageSystem(EntityManager*);
	~DamageSystem() = default;
	virtual void update(sf::Time);
private:
	int handleEnemies(Lier*);
	void dealDamage(EnemyWave* wave, Enemy* enemy, Castle* castle);
	std::vector<Lier*>liers;
	std::vector<Castle*>castles;
};

