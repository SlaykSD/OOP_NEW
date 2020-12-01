#pragma once
#include "Bulding.h"
#include "EffectType.h"
class Trap : public Bulding
{
public:
	Trap(const Tile* tile, EffectType type);
	Trap(const Trap& c);
	const Trap& operator=(const Trap& c);
	virtual void update(sf::Time);
	void draw(sf::RenderWindow* window);
	float  getDamage()const { return damage; }
	EffectType  getEffectType() const { return type; }
	float getRange()const { return range; }
	bool getMode()const { return explosion; }
	void  setMode(bool mode) { explosion = mode; }
	bool checkTime()const;
private:
	sf::Texture texture;
	EffectType type;
	sf::Time elapsedTime;
	bool explosion;
	const sf::Time timeDetonation = sf::seconds(1.f /2);
	float damage;
	float range;
};

