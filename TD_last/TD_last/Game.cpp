
#include "Game.h"

namespace Game_def {

	void Game::run() {
		const sf::Time frameTime = sf::seconds(1.f / 60.f);
		sf::Clock clock;
		sf::Time passedTime = sf::Time::Zero;

		while (window.isOpen())
		{

			//float time = clock.getElapsedTime().asMicroseconds();
			//std::cout << time<<"\n";
			//clock.restart();
			//time = time / 800;
			sf::Time elapsedTime = clock.restart();
			passedTime += elapsedTime;

			// Physics, logics etc
			while (passedTime > frameTime)
			{
				passedTime -= frameTime;

				processEvent();
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
			gState.notifyProcessEvent(event);
		}
	}
	void Game::update(Time frameTime) {
		gState.notifyUpdate(frameTime);
	}

	void Game::draw() {
		gState.draw();
	}

	Game::Game() :
		window(sf::VideoMode(640, 640), "TD_betta"),
		gState(&window)
	{
	}
}