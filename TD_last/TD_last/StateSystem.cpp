#include "StateSystem.h"

void StateSystem::notifyUpdate(sf::Time dt)
{
	int size = _states.size();
	for (int i = 0; i < size; i++)
		if (_states[i]->update(dt))
			break;
}

void StateSystem::notifyProcessEvent(const sf::Event& event)
{
	int size = _states.size();
	for (int i = 0; i < size; i++)
		if (_states[i]->handleEvent(event))
			break;
}
void StateSystem::addState(State* state)
{
	_states.push_back(state);
}