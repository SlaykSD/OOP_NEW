#pragma once
#include <SFML/Graphics.hpp>
class EntityManager;

class System
{
public:
	System() = default;
	virtual ~System() = default;
	virtual void update(sf::Time) = 0;
	void setManager(EntityManager* manager);
protected:
	EntityManager* _manager;
};

