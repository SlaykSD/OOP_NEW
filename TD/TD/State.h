#pragma once
#include <SFML/Graphics.hpp>
class State
{
public:
	virtual bool handleEvent(const sf::Event& event) = 0;
	virtual bool update(sf::Time dt) = 0;
};

