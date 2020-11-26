#pragma once
#include "Effect.h"
#include "Entity.h"
#include <list>
class EnemyWave;

enum EnemyType
{
	Light_Infantry = 1,
	Heavy_Infantry,
	Heavy_Ranhger
};
class Enemy : public Entity
{
public:
	Enemy();
	Enemy(std::list <sf::Vector2i>, EnemyType);

	void setEnemyWave(EnemyWave* wave);

	void update(sf::Time);
	int controlEffects(sf::Time);
	void updateEf(sf::Time);
	void removeEffects();
	//virtual  void draw(sf::RenderWindow *) = 0;
	void setVisible(bool vis) { visible = vis; }
	bool getVisible()const { return visible; }
	const sf::Vector2f getPosition()const { return sprite.getPosition(); }
	EnemyType getName()const { return name; }
	float  gethp()const { return hp; }
	const std::list <sf::Vector2i>* getPointsList()const { return &checkPoints; }
	void setColor(sf::Color col) {
		sprite.setColor(col);
	}
	void setOrigin();
	void reSetOrigin();
	void selfdestruction();
	bool takeDamage(float damage, EffectType type);
	int getGold()const { return money; }
	bool addEffect(EffectType);
	int findEffect(EffectType);
	void setHP(float ef_hp) { hp = ef_hp; }
	float getHP() { return hp; }
	void setSpeed(float ef_speed) { speed = ef_speed; }
	float getSpeed() { return speed; }
	void setIncreaseDamage(float tmp) { increaseDamage = tmp; }
protected:

	int points;
	bool visible;
	float speed;
	float hp;
	const int HP_MAX;
	float increaseDamage;
	std::vector<Effect> effects;
	int money;
	sf::Sprite sprite;
	sf::RectangleShape rectHealthbar;
	std::list <sf::Vector2i> checkPoints;
	EnemyType name;
	sf::Texture healthbar;
	EnemyWave* _wave;
};


