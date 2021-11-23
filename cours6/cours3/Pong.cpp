#include "pch.h"
#include <iostream>
#include <string>
#include <filesystem>

#include <cstdio>
#include <cstdlib>
#include "Chrono.hpp"
#include <algorithm>
#include <vector>
#include <direct.h>

#include <SFML/Graphics.hpp>
#include <SFML/Main.hpp>
#include <SFML/Window.hpp>
#include <SFML/Audio.hpp>
#include "Turtle.hpp"

int main() {
	Turtle * turtle = new Turtle();
	int turtleRunSpeed = 10;
	float turtleTurnSpeed = 10;

	char tmp[256];
	_getcwd(tmp, 256);
	cout << "Current working directory: " << tmp << endl;

	sf::RenderWindow window(sf::VideoMode(1280, 720), "SFML works!");
	window.setVerticalSyncEnabled(true);
	//window.setFramerateLimit(60);

	double tStart = getTimeStamp();
	double tEnterFrame = getTimeStamp();
	double tExitFrame = getTimeStamp();
	bool mouseLeftWasPressed = false;


	while (window.isOpen()) {
		sf::Event event;
		double dt = tExitFrame - tEnterFrame;
		tEnterFrame = getTimeStamp();
		while (window.pollEvent(event)) {
			if (event.type == sf::Event::Closed)
				window.close();
		}

	FILE * file = nullptr;
	//fscanf;
	//fprintf;
	//fclose;

		if (sf::Keyboard::isKeyPressed(sf::Keyboard::O)) {
			fopen_s(&file,"res/ui.txt", "rb");

			if (!file)
				printf("file error ");

			char line[256] = {};
			if (!feof(file)) {
				while (true) {
					int64_t nb = 0;
					fscanf_s(file, "%s %lld\n", line, 256, nb);
					std::string s = line;
					if (s == "Forward") {
						turtle->goForward(nb);
					}
					if (s == "Turn") {
						turtle->goForward(nb);
					}
					if (s == "DrawUp") {
						turtle->doDraw(true);
					}
					if (s == "DrawDown") {
						turtle->doDraw(false);
					}
					if (s == "Color") {
						//turtle->changeColor(sf::Color(unsigned int)nb)
					}
					if (feof(file)) {
						break;
					}
				}
				fclose(file);
			}
		}



		if (sf::Keyboard::isKeyPressed(sf::Keyboard::Up) || sf::Keyboard::isKeyPressed(sf::Keyboard::Z)) {
			turtle->addCmd(new Cmd(Forward,turtleRunSpeed));
		}
		if (sf::Keyboard::isKeyPressed(sf::Keyboard::Down) || sf::Keyboard::isKeyPressed(sf::Keyboard::S)) {
			turtle->addCmd(new Cmd(Forward, -turtleRunSpeed));
		}
		if (sf::Keyboard::isKeyPressed(sf::Keyboard::Left) || sf::Keyboard::isKeyPressed(sf::Keyboard::Q)) {
			turtle->addCmd(new Cmd(Turn, -turtleTurnSpeed));
		}
		if (sf::Keyboard::isKeyPressed(sf::Keyboard::Right) || sf::Keyboard::isKeyPressed(sf::Keyboard::D)) {
			turtle->addCmd(new Cmd(Turn, turtleTurnSpeed));
		}
		if (sf::Keyboard::isKeyPressed(sf::Keyboard::W)) {
			turtle->addCmd(new Cmd(DrawUp, 0));
		}
		if (sf::Keyboard::isKeyPressed(sf::Keyboard::X)) {
			turtle->addCmd(new Cmd(DrawDown, 0));
		}

		if (sf::Keyboard::isKeyPressed(sf::Keyboard::R)) {
			turtle->changeColor(sf::Color::Red);
		}
		if (sf::Keyboard::isKeyPressed(sf::Keyboard::G)) {
			turtle->changeColor(sf::Color::Green);
		}
		if (sf::Keyboard::isKeyPressed(sf::Keyboard::B)) {
			turtle->changeColor(sf::Color::Blue);
		}



		/*auto pos = player->position;
		double deltaX = dt * 600;
		double deltaY = dt * 600;
		bool keyHit = false;

		if (sf::Keyboard::isKeyPressed(sf::Keyboard::Left) || sf::Keyboard::isKeyPressed(sf::Keyboard::Q)) {
			pos.x -= deltaX;
			keyHit = true;
		}
		if (sf::Keyboard::isKeyPressed(sf::Keyboard::Right) || sf::Keyboard::isKeyPressed(sf::Keyboard::D)) {
			pos.x += deltaX;
			keyHit = true;
		}
		if (sf::Keyboard::isKeyPressed(sf::Keyboard::Up) || sf::Keyboard::isKeyPressed(sf::Keyboard::Z)) {
			pos.y -= deltaY;
			keyHit = true;
		}
		if (sf::Keyboard::isKeyPressed(sf::Keyboard::Down) || sf::Keyboard::isKeyPressed(sf::Keyboard::S)) {
			pos.y += deltaY;
			keyHit = true;
		}
		if (keyHit)
		{
			player->position = pos;
		}*/
		/*bool mouseLeftIsPressed = sf::Mouse::isButtonPressed(sf::Mouse::Left);
		bool mouseIsReleased = (!mouseLeftIsPressed && mouseLeftWasPressed);

		sf::Vector2f mousePos = sf::Vector2f(sf::Mouse::getPosition(window));

		if (mouseLeftIsPressed && !mouseLeftWasPressed) {
		}

		if (mouseLeftIsPressed)
			mouseLeftWasPressed = true;
		
		if (sf::Keyboard::isKeyPressed(sf::Keyboard::Up)) {
			sf::Vector2i windowPos = window.getPosition();
			window.setPosition(sf::Vector2i(100 + rand() % 25, 100 + rand() % 25));
		}*/

		window.clear();

		turtle->update();
		turtle->draw(window);

		window.display();
		tExitFrame = getTimeStamp();

	}

	return 0;
}