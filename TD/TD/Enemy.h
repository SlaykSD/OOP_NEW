#pragma once
#include "Effect.h"
#include "Entity.h"
#include "List.h"
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
	Enemy(best_list::List <sf::Vector2i>, EnemyType);
	void setEnemyWave(EnemyWave* wave);

	//Work with effects

	int controlEffects(sf::Time);
	bool addEffect(EffectType);
	int findEffect(EffectType);
	void updateEf(sf::Time);
	void removeEffects();

	void setSpeed(float ef_speed) { speed = ef_speed; }
	float getSpeed() { return speed; }
	void setIncreaseDamage(float tmp) { increaseDamage = tmp; }

	//work with moving	
	void update(sf::Time);
	void setVisible(bool vis) { visible = vis; }
	bool getVisible()const { return visible; }
	const sf::Vector2f getPosition()const { return sprite.getPosition(); }
	
	//Interaction with tower
	EnemyType getName()const { return name; }
	float  gethp()const { return hp; }
	const best_list::List <sf::Vector2i>* getPointsList()const { return &checkPoints; }
	void setColor(sf::Color col) {
		sprite.setColor(col);
	}
	void setOrigin();
	void reSetOrigin();

	//main functions (work with hp)
	void selfdestruction();
	bool takeDamage(float damage, EffectType type);
	int getGold()const { return money; }
	void setHP(float ef_hp) { hp = ef_hp; }
	float getHP() { return hp; }
	
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
	best_list::List <sf::Vector2i> checkPoints;
	EnemyType name;
	sf::Texture healthbar;
	EnemyWave* _wave;
};


