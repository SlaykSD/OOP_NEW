#pragma once
#include "System.h"
#include "Tower.h"
#include "Lier.h"
#include "Castle.h"



//struct Target
//{
//	Enemy* en;
//	float distance_t;
//	float distance_c;
//};
struct Targets
{
	/*std::vector<Target> targets;*/
	std::vector<Enemy*> targets;
	std::vector<float> distances_t;
	std::vector<float> distances_c;
	Targets() = default;
	Targets(std::vector<Enemy*>, std::vector<float>, std::vector<float>);
};

class MoveSystem : public System
{
public:

	MoveSystem() = default;
	MoveSystem(EntityManager*);
	~MoveSystem() = default;
	virtual void update(sf::Time);
private:
	//functions
	Targets detectTargets(Lier*, Tower*);
	Enemy* choosePriorityTarget(Targets*);

	Targets firstPriority(Targets*);
	Targets secondPriority(Targets*);
	Targets thirdPriority(Targets*);
	float getDistance(sf::Vector2f);
	float getDistanceToCastle(Enemy*);
	//attribute

	std::vector<Tower*> towers;
	std::vector<Lier*> liers;
	std::vector<Castle*>castles;
};

