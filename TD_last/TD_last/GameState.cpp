
#include "GameState.h"

GameState::GameState(sf::RenderWindow* window1): window(window1), eManager (), sysMouse(window)
{
	level.LoadFromFile("realmap_forest.tmx");
	eManager.setParameters(&level);
	sysMouse.setLvl(&level);
	this->addState(&sysMouse);
	
}
void GameState::setEManager(Level* lvl)
{
	eManager.setParameters(lvl);
}
void GameState::draw()
{
	level.DrawMap(*window);
	level.DrawGrid(*window);
}
const Level& GameState::getLevel()const
{
	return level;
}