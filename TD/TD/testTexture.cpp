#include "EnemyWave.h"




//int main()
//{
//	sf::RenderWindow window(sf::VideoMode(640, 640), "SFML works!");
//	std::list <sf::Vector2i> points;
//	for (int i = 0; i < 14; i++)
//	{
//		sf::Vector2i tmp;
//		tmp.x = rand()/400;
//		tmp.y = rand() / 400;
//		points.push_back(tmp);
//	}
//	EnemyWave wave(points, 1);
//	const sf::Time frameTime = sf::seconds(1.f / 60.f);
//	sf::Clock clock;
//	sf::Time passedTime = sf::Time::Zero;
//
//	while (window.isOpen())
//	{
//
//		sf::Time elapsedTime = clock.restart();
//		passedTime += elapsedTime;
//
//		// Physics, logics etc
//		sf::Event event;
//		while (window.pollEvent(event))
//		{
//			if (event.type == sf::Event::Closed)
//				window.close();
//		}
//		while (passedTime > frameTime)
//		{
//			passedTime -= frameTime;
//			wave.update(frameTime);
//
//		}
//		window.clear();
//		wave.draw(&window);
//		window.display();
//	}
//	return 1;
//}