#pragma once
#include "Bulding.h"
#include "Effect.h"

enum TowerType;

struct TableStateTower
{
	float range;
	float damage;
	float attackSpeed;	
	EffectType type_ef;
	TableStateTower() : range(100), damage(50), attackSpeed(1) { ; }
	bool up();
	//Не хватает эфекта
};

class Tower: public Bulding
{
public:
	Tower(const Tower&);
	Tower(const Tile* tile, TowerType);
	virtual void update(sf::Time);
	void draw(sf::RenderWindow* window);
	TowerType getTowerType()const { return type; }
	int getLevel()const { return level; }
	const Tower& operator=(const Tower&);
	void lvlUP();
private:
	void setTexture(int);
	TowerType type;
	int level;
	const int LEVEL_MAX = 2;
	TableStateTower table;
	std::vector<sf::Texture> texturpack;//contain texture level 1 and 2
};

