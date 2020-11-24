#pragma once
#include "Bulding.h"
#include"EnemyWave.h"
#include <list>

class Lier :public Bulding
{
public:
	Lier(const Tile* tile, std::list <sf::Vector2i>);
	virtual void update(sf::Time);
	void draw(sf::RenderWindow* window);
	std::vector<EnemyWave*> getWaves();
private:
	EnemyWave generateWave();
	sf::Font font;
	sf::Text textLier;
	std::list <sf::Vector2i> checkPoints;//way from lier to castle. Mass of coordinate
	std::vector<EnemyWave> waves;
	sf::Time beginTime;
	const sf::Time cooldownWave;
	const int numberWaves;
	int numberWave;

};

