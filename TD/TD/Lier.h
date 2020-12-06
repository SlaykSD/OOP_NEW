#pragma once
#include "Bulding.h"
#include"EnemyWave.h"
#include "List.h"

class Lier :public Bulding
{
public:
	Lier(const Tile* tile, best_list::List <sf::Vector2i>);
	virtual void update(sf::Time);
	void draw(sf::RenderWindow* window);
	std::vector<EnemyWave*> getWaves();
	void removeEn(Enemy*);
private:
	void generateWave();
	sf::Font font;
	sf::Text textLier;
	best_list::List <sf::Vector2i> checkPoints;//way from lier to castle. Mass of coordinate
	std::vector<EnemyWave> waves;
	sf::Time beginTime;
	const sf::Time cooldownWave;
	const int numberWaves;
	int numberWave;

};

