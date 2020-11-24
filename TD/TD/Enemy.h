#pragma once
#include "Entity.h"
#include "Effect.h"
#include <list>

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
	Enemy(std::list <sf::Vector2i> , EnemyType );
	void update(sf::Time);
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
protected:

	int points;
	bool visible;
	float speed;
	float hp;
	const int HP_MAX;
	std::vector<Effect> ef;
	int money;
	sf::Sprite sprite;
	std::list <sf::Vector2i> checkPoints;
	EnemyType name;
	//sf::Texture texture;
};


