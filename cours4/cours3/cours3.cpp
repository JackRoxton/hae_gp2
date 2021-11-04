#include "pch.h"
#include <iostream>
#include <SFML/Graphics.hpp>

int posx = 400, posy = 400;
int main()
{
	sf::RenderWindow window(sf::VideoMode(1280, 720), "SFML works!");
	window.setVerticalSyncEnabled(true);
	window.setFramerateLimit(60);
	sf::CircleShape shape(100.f);
	shape.setFillColor(sf::Color::Green);
	shape.setPosition(posx, posy);

	/*sf:Font fArial;
	if(!fArial.loadFromFile(""))*/
	while (window.isOpen())
	{
		sf::Event event;
		while (window.pollEvent(event))
		{
			if (event.type == sf::Event::Closed)
				window.close();

			/*if (event.type == sf::Event::KeyPressed)
			{
				if (event.key.code == sf::Keyboard::Up)
					posy -= 5;
				if (event.key.code == sf::Keyboard::Down)
					posy += 5;
				if (event.key.code == sf::Keyboard::Left)
					posx -= 5;
				if (event.key.code == sf::Keyboard::Right)
					posx += 5;

				shape.setPosition(posx,posy);

				printf("%d, %d\n", posx, posy);
			}*/

			auto pos = shape.getPosition();
			if (sf::Keyboard::isKeyPressed(sf::Keyboard::Left))
				posx -= 5;
			if (sf::Keyboard::isKeyPressed(sf::Keyboard::Right))
				posx += 5;
			if (sf::Keyboard::isKeyPressed(sf::Keyboard::Up))
				posy -= 5;
			if (sf::Keyboard::isKeyPressed(sf::Keyboard::Down))
				posy += 5;

			shape.setPosition(posx, posy);
		}


		window.clear();
		window.draw(shape);
		window.display();
	}

	return 0;
}