#pragma once
#include "State.h"
#include <iostream>

/*!
\brief The system States of the game

Includes only the game state at the moment
\todo ADD state of Game Over
*/
class StateManager
{
public:
	void notifyUpdate(sf::Time dt);
	void notifyProcessEvent(const sf::Event& event);
	void addState(State* state);
private: 
	std::vector<State*> _states;
};

