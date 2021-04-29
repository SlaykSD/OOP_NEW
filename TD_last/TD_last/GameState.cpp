
#include "GameState.h"
#include "Tile.h"


GameState::GameState(sf::RenderWindow* window1): window(window1), level("oneMapObject.tmx") , eManager(level)
{
//	eManager.setParameters(level);4
}

bool GameState::handleEvent(const sf::Event& event)
{
	if (event.type == Event::MouseButtonPressed)
	{
		if (event.key.code == Mouse::Right)
		{
			std::cout << "right" << std::endl;
			sf::Vector2i vec = sf::Mouse::getPosition(*window);
			int state = level.getGrid().getTile(vec.y / level.GetTileSize().y, vec.x / level.GetTileSize().x)->getState();
			if ((state == 0)&&(eManager.getGold()>=110))
			{
				Texture widget_buy;
				widget_buy.loadFromFile("widget_buy.jpg");
				sf::Sprite menu1(widget_buy);
				menu1.setTextureRect(IntRect(0, 0, 64, 64));

				sf::Sprite menu2(widget_buy);
				menu2.setTextureRect(IntRect(0, 64, 64, 64));

				menu1.setPosition(vec.y,vec.x);
				menu2.setPosition(vec.y, vec.x + 64);
				bool isMenu =1;
				int menuNumb = 0;
				while (isMenu)
				{
					menuNumb = 0;
					if (menu1.getTextureRect().contains(Mouse::getPosition(*window))) { menu1.setColor(Color::Red); menuNumb = 1; }
					if (menu2.getTextureRect().contains(Mouse::getPosition(*window))) { menu1.setColor(Color::Red); menuNumb = 2; }
					if (Mouse::isButtonPressed(Mouse::Left))
					{

						if (menuNumb != 0)
						{
							Tower tower(level.getGrid().getTile(vec.y / level.GetTileSize().y, vec.x / level.GetTileSize().x));
							level.setTower(vec, menuNumb-1);
							eManager.addTower(tower);
							isMenu = false;
						}
					}
					window->draw(menu1);
					window->draw(menu2);
					window->display();
				}

				//Tower tower(level.getGrid().getTile(vec.y / level.GetTileSize().y, vec.x / level.GetTileSize().x));
				//level.setTower(vec, window);
				//eManager.addTower(tower);
				//this->curr = lvl->getGrid().getTile(vec.y / lvl->GetTileSize().y, vec.x / lvl->GetTileSize().x).getSprite();
				std::cout << "right-click - succesfuly" << std::endl;
			}
			if (state == 4)
			{

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