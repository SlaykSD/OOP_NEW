
#include "GameState.h"

GameState::GameState(sf::RenderWindow* window1): window(window1), level("oneMapObject.tmx") , eManager(level)
{
//	eManager.setParameters(level);
}

bool GameState::handleEvent(const sf::Event& event)
{
	if (event.type == Event::MouseButtonPressed)
	{
		if (event.key.code == Mouse::Right)
		{
			std::cout << "right" << std::endl;
			sf::Vector2i vec = sf::Mouse::getPosition(*window);
			if (level.getGrid().getTile(vec.y / level.GetTileSize().y, vec.x / level.GetTileSize().x)->getState() == 0)
			{
				Tower tower(level.getGrid().getTile(vec.y / level.GetTileSize().y, vec.x / level.GetTileSize().x));
				level.setTower(vec, window);
				eManager.addTower(tower);
				//this->curr = lvl->getGrid().getTile(vec.y / lvl->GetTileSize().y, vec.x / lvl->GetTileSize().x).getSprite();
				std::cout << "right-click - succesfuly" << std::endl;
			}
			return true;
		}
		//Здесь должна быть обратока выбор постройки и выбор альтертатив для улучшения

		if (event.key.code == Mouse::Left)
		{
			std::cout << "left" << std::endl;
			return true;//Здесь должна быть обработка выделения строения
		}
	}
	else
	{
		return false;
	}

}
bool GameState::update(sf::Time dt)
{
	return true;
}
void GameState::setEManager(Level* lvl)
{
	eManager.setParameters(*lvl);
}
void GameState::draw()
{
	level.DrawMap(*window);
	level.DrawGrid(*window);
	eManager.draw(window);
}
const Level& GameState::getLevel()const
{
	return level;
}