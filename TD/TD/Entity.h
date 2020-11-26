#pragma once
#include <SFML/Graphics.hpp>
class EntityManager;

class Entity
{
public:
	Entity() = default;
	virtual void update(sf::Time)=0;
	void setEManager(EntityManager*);
	EntityManager* getEManager()
	{
		return _manager;
	}
protected:
	EntityManager* _manager;
};

