#pragma once
#include "Enemy.h"
class EnemyWave :public Entity
{
public:
	EnemyWave(std::list <sf::Vector2i>,int);//�������� ����� �� ���� �����
	void draw(sf::RenderWindow* window);
	virtual void update(sf::Time);//���������� ����� �����
private:
	int curr;
	const sf::Time cooldown;
	sf::Time elapsedTime;
	std::vector<Enemy*> wave;
	//std::vector<LightInfantry> lights;
	//std::vector<HeavyRanger> rangers;
	//std::vector<HeavyInfantry> lights;
};

