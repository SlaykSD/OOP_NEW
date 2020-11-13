#pragma once
#include "State.h"
#include <iostream>
class StateManager
{
public:
	void notifyUpdate(sf::Time dt);
	void notifyProcessEvent(const sf::Event& event);
	void addState(State* state);
private: 
	std::vector<State*> _states;
};

