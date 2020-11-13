#include "Lier.h"

Lier::Lier(Tile* tile, std::list <sf::Vector2i> list ):Bulding(tile),numberWaves(3), beginTime (Time::Zero), checkPoints (list)
{
}
void Lier::update(sf::Time frameTime)
{
	beginTime += frameTime;
}