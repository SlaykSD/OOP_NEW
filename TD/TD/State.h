#pragma once
#include <SFML/Graphics.hpp>

/*!
\brief An abstract class that represents the state of the game*/
class State
{
public:
	virtual bool handleEvent(const sf::Event& event) = 0;//! virtual function for handle event
	virtual bool update(sf::Time dt) = 0;//!virtual function for handle every tick of time
};

