#pragma once
#include <SFML/Graphics.hpp>
class EntityManager;

/*!
\brief Abstract class for the implementation of the system of interaction between entities
*/
class System
{
public:
	System() = default;
	virtual ~System() = default;
	virtual void update(sf::Time) = 0; //!virtual function for handle every tick of time
	void setManager(EntityManager* manager);
protected:
	EntityManager* _manager;
};

