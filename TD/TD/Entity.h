#pragma once
//#include "EntityManager.h"
#include <SFML/Graphics.hpp>


class Entity
{
public:
	Entity() = default;
	virtual void update(sf::Time)=0;
};
