#pragma once
#include "System.h"

class MoveSystem : public System
{
public:
	MoveSystem() = default;
	~MoveSystem() = default;
	virtual void update(sf::Time) ;
};

