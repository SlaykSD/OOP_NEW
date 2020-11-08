#pragma once
//#include <SFML/Graphics.hpp>
#include "Game.h"
/*
#include <vector>
#include <iostream>
#include "level.h"
#include <list>


int main()
{
    sf::RenderWindow window(sf::VideoMode(640, 480), "hui");
    Level lvl;
    lvl.LoadFromFile("jopa3.tmx");
    sf::Vector2i tile;
    lvl.Draw(window);
    tile = lvl.GetTileSize();
    std::cout << tile.x << " and y:" << tile.y << std::endl;
	sf::Clock clock;
	while (window.isOpen())
	{

		float time = clock.getElapsedTime().asMicroseconds();

		clock.restart();
		time = time / 800;

		sf::Event event;
		while (window.pollEvent(event))
		{
			if (event.type == sf::Event::Closed)
				window.close();
		}
		lvl.Draw(window);
		window.display();
	}
    return 0;
}
*/
int main()
{
	Game_def::Game game;
	game.run();
	return 0;
}