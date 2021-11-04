#include "pch.h"
#include <iostream>
#include <SFML/Graphics.hpp>
#include <SFML/Main.hpp>

int posx = 400, posy = 400;
int dt = 5;
bool keypress = false;

/*class bullet {
	sf::CircleShape bult;
	bult.setRadius(10.f);
	bult.setFillColor(sf::Color::Magenta);
};*/

int main()
{
	sf::RenderWindow window(sf::VideoMode(1280, 720), "SFML works!");
	window.setVerticalSyncEnabled(true);
	window.setFramerateLimit(60);
	sf::RectangleShape shape;
	shape.setSize(sf::Vector2f(50, 75));
	shape.setFillColor(sf::Color::Green);
	shape.setPosition(posx, posy);
	sf::RectangleShape gun;
	gun.setSize(sf::Vector2f(100, 25));
	gun.setFillColor(sf::Color::White);
	gun.setOrigin(10,10);
	gun.setPosition(posx, posy);
	sf::CircleShape mouse;
	mouse.setRadius(10.f);
	mouse.setFillColor(sf::Color::Yellow);
	mouse.setPosition(sf::Vector2f(sf::Mouse::getPosition()));

	
	/*sf::Font fHumble;
	if (!fHumble.loadFromFile("res/The Humble.ttf"))
		printf("font not loaded\n");
	sf::Text tdt;
	tdt.setFont(fHumble);
	tdt.setCharacterSize(45);*/

	bool bulletAlive = false;
	float bulletTargetAngle;
	sf::CircleShape bullet;

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
				posx -= dt; keypress = true;
			if (sf::Keyboard::isKeyPressed(sf::Keyboard::Right))
				posx += dt; keypress = true;
			if (sf::Keyboard::isKeyPressed(sf::Keyboard::Up))
				posy -= dt; keypress = true;
			if (sf::Keyboard::isKeyPressed(sf::Keyboard::Down))
				posy += dt; keypress = true;

			if (keypress) {
			shape.setPosition(posx, posy);
			gun.setPosition(posx+25, posy+10);
			keypress = false;
			}
			mouse.setPosition(sf::Vector2f(sf::Mouse::getPosition(window)));
			sf::Vector2f characterToMouse(mouse.getPosition().y - shape.getPosition().y,
											mouse.getPosition().x - shape.getPosition().x);
			float angle = atan2(characterToMouse.x, characterToMouse.y);
			gun.setRotation(angle * 57.2958);
			
			if (sf::Mouse::isButtonPressed(sf::Mouse::Left) && !bulletAlive)
			{
				bullet.setRadius(10.f);
				bullet.setFillColor(sf::Color::Magenta);
				bullet.setPosition(gun.getPosition());
				bulletAlive = true;
				bulletTargetAngle = angle * 57.2958;
			}
			if (bulletAlive)
				bullet.setPosition();
		}


		window.clear();
		window.draw(shape);
		window.draw(gun);
		window.draw(mouse);
		if(bulletAlive)
		window.draw(bullet);
		//window.draw(tdt);
		window.display();
	}

	return 0;
}