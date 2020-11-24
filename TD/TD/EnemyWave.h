#pragma once
#include "Enemy.h"
class EnemyWave :public Entity
{
public:
	EnemyWave(std::list <sf::Vector2i>,int);//�������� ����� �� ���� �����
	void draw(sf::RenderWindow* window);
	virtual void update(sf::Time);//���������� ����� �����
	std::vector<Enemy*> getEnemies()const;
	bool removeEnemy(Enemy*);
private:
	int curr;
	const sf::Time cooldown;
	sf::Time elapsedTime;
	std::vector<Enemy*> wave;
};

