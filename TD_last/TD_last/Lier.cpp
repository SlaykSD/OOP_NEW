#include "Lier.h"

Lier::Lier(Tile* tile):Bulding(tile),numberWaves(3), beginTime (Time::Zero)
{
}
void Lier::update(sf::Time frameTime)
{
	beginTime += frameTime;
}