#pragma once
#include "Bulding.h"
#include "EffectType.h"
#include "Enemy.h"
enum TowerType;

struct TableStateTower
{
	float range;
	float damage;
	float attackSpeed;
	EffectType type_ef;
	TableStateTower() : range(100), damage(50), attackSpeed(1.5) { ; }
	bool up();
	void setEffect(TowerType type_t);
};

class Tower : public Bulding
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
	void setTarget(Enemy* tmp) 
	{
		target = tmp;
	}
	void removeColor() { target->setColor(sf::Color::White); }
	Enemy* getTarget()const { return target; }
	float  getRange()const { return  table.range; }
	void setOrigin();
	void setAngle(float angle) { angleOfRotation = angle; }
	float getAngle()const { return angleOfRotation; }
private:
	sf::Time elapsedTime;
	float angleOfRotation;
	Enemy* target;
	void setTexture(int);
	TowerType type;
	int level;
	const int LEVEL_MAX = 2;
	TableStateTower table;
	std::vector<sf::Texture> texturpack;//contain texture level 1 and 2
};

