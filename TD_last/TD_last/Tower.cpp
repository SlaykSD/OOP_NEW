#include "Tower.h"

Tower::Tower(const Tile* tile):Bulding(tile),LEVEL_MAX(2), level(1)
{}
void Tower::update(sf::Time)
{

}
void Tower ::draw(sf::RenderWindow* window)
{
	this->getTile()->getDraw(window);
}