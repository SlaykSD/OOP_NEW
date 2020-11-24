#include "EnemyWave.h"
#include "LightInfantry.h"
#include "HeavyInfantry.h"
#include "HeavyRanger.h"
#include <iostream>

EnemyWave::EnemyWave(std::list <sf::Vector2i> list, int type) :cooldown(sf::seconds(3.f)),curr(0)
{
	if (type == 1)
	{
		auto light1 = new LightInfantry(list);
		auto light2 = new LightInfantry(list);
		auto light3 = new LightInfantry(list);
		auto heavy1 = new HeavyInfantry(list);
		wave.push_back(light1);
		wave.push_back(light2);
		wave.push_back(light3);
		wave.push_back(heavy1);
	}
}
void EnemyWave::update(sf::Time dt)
{
	elapsedTime += dt;
	int size = wave.size();
	if (elapsedTime > cooldown)
	{
		elapsedTime = sf::Time::Zero;
		if (size > curr)
		{
			if (curr == 2)
			{
				std::cout << "2-oq poshol"<<std::endl;
			}
			bool g = true;
			wave[curr]->setVisible(g);
			curr++;
		}
	}
	for (int i = 0; i < size; i++)
	{
		wave[i]->update(dt);
	}
}
void EnemyWave::draw(sf::RenderWindow* window)
{
	int size = wave.size();
	for (int i = 0; i < size; i++)
	{
		if (wave[i]->getName() == 1)
		{
			//B objB;
			////objB.g(&App);                     //Вызовется g() из объекта типа A, как и должно быть
			//A* ptrA = (A*)(&objB); //берём адрес objB, приводим его к типу указателя на A и                         //записываем в ptrA
			//B* ptrB = (B*)(ptrA);
			LightInfantry* enemy = (LightInfantry*)(wave[i]);
			enemy->draw(window);
		}
		if (wave[i]->getName() == 2)
		{
			auto enemy = (HeavyInfantry*)(wave[i]);
			enemy->draw(window);
		}
		if (wave[i]->getName() == 3)
		{
			auto enemy = (HeavyRanger*)(wave[i]);
			enemy->draw(window);
		}
	}
}

std::vector<Enemy*> EnemyWave::getEnemies()const
{
	return this->wave;
}
bool EnemyWave::removeEnemy(Enemy* enemy)
{
	curr--;
	int size = wave.size();
	//find enemy
	int i;
	for (i = 0; i < size; i++)
	{
		if (enemy == wave[i])
			break;
	}
	try {
		delete wave[i];//Если не сработает можно попробовать умный указатель https://askdev.ru/q/kak-izbezhat-utechki-pamyati-pri-ispolzovanii-vektora-ukazateley-na-dinamicheski-vydelennye-obekty-v-c-41431/
		wave.erase(wave.begin() + i);
	}
	catch (...)
	{
		std::cout << "Momore doesnot free (delete enemy)" << std::endl;
		return false;
	}
	return true;
}