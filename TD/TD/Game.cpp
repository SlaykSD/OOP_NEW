
#include "Game.h"

namespace Game_def {

	void Game::run() {
		const sf::Time frameTime = sf::seconds(1.f / 60.f);
		sf::Clock clock;
		sf::Time passedTime = sf::Time::Zero;

		while (window.isOpen())
		{

			sf::Time elapsedTime = clock.restart();
			passedTime += elapsedTime;
			if (pause)
			{
				passedTime = Time::Zero;
				pause = false;
			}

			// Physics, logics etc
			while (passedTime > frameTime)
			{
				passedTime -= frameTime;

				processEvent();
				if (pause)
				{
					passedTime = Time::Zero;
				}
				update(frameTime);

			}
			draw();
			window.display();
		}
	}
	void Game::processEvent()
	{
		sf::Event event;
		while (window.pollEvent(event))
		{
			if (event.type == sf::Event::Closed)
				window.close();
			if (event.type == sf::Event::MouseButtonPressed)
			{
				if (event.key.code == sf::Mouse::Right)
					pause = true;
			}
			manager.notifyProcessEvent(event);
		}
	}
	void Game::update(Time frameTime) {
		manager.notifyUpdate(frameTime);
	}

	void Game::draw() {
		gState.draw();
	}

	Game::Game() :
		window(sf::VideoMode(640, 640), "TD_betta"),
		gState(&window),
		pause(false),
		dSys(),
		mSys()
	{
		manager.addState(&gState);
		gState.addSystem(&dSys);
		gState.addSystem(&mSys);
	}
}