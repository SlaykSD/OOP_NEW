#include "DamageSystem.h"
#include "EntityManager.h"
#include "Enemy.h"
DamageSystem::DamageSystem()
{

}
DamageSystem::DamageSystem(EntityManager* manager)
{
	this->setManager(manager);
	castles = this->_manager->getCastles();
	liers = this->_manager->getLiers();
}
void DamageSystem::update(sf::Time dt)
{
	int liers_s = liers.size();
	for (int i = 0; i < liers_s; i++)
	{
		handleEnemies(liers[i]);
	}
}

int DamageSystem::handleEnemies(Lier* lier)
{
	std::vector<EnemyWave*> waves;
	waves = lier->getWaves();
	int waves_s = waves.size();
	for (int i = 0; i < waves_s; i++)
	{
		std::vector<Enemy*> enemies = waves[i]->getEnemies();
		int size_en = enemies.size();
		if (size_en&&enemies[0]->getVisible())
		{
			for (int j = 0; j < size_en; j++)
			{
				//std::cout << "Enemy index " << j << "HP,Position, " << enemies[j]->getHP() << " {" << enemies[j]->getPosition().x << " | "<<enemies[j]->getPosition().y << "} " << std::endl;
				sf::Vector2f pos_e = enemies[j]->getPosition();
				pos_e.x = (int)pos_e.x;
				pos_e.y = (int)pos_e.y;
				int size_c = castles.size();
				for (int i_c = 0; i_c < size_c; i_c++)
				{
					sf::Vector2f pos = castles[i_c]->getTile()->getSprite().getPosition();
					//std::cout << "Position castles {" << pos.x << " | " << pos.y <<"} "<< std::endl;
					if (pos == pos_e)
					{
						
						dealDamage(waves[i],enemies[j], castles[i_c]);
					}
				}
			}
		}
	}
	return 1;
}

void DamageSystem::dealDamage(EnemyWave* wave,Enemy* enemy, Castle* castle)
{
	float hp_e = enemy->gethp();
	castle->takeDamage(hp_e);
	wave->removeEnemy(enemy);
}