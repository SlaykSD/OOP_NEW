#pragma once
#include "Enemy.h"
class EnemyWave :public Entity
{
public:
	EnemyWave(std::list <sf::Vector2i>,int);//Create wave
	void draw(sf::RenderWindow* window);
	virtual void update(sf::Time);//update all of enemy in wave
	std::vector<Enemy*> getEnemies()const;
	bool removeEnemy(Enemy*);
private:
	int curr;
	const sf::Time cooldown = sf::seconds(3.f);
	sf::Time elapsedTime;
	std::vector<Enemy*> wave;
};

