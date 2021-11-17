#include "pch.h"
#include <iostream>
#include <cstdio>
#include <cstdlib>
#include "Chrono.hpp"
#include <algorithm>
#include <vector>

#include <SFML/Graphics.hpp>
#include <SFML/Main.hpp>
#include <SFML/Window.hpp>
#include "particle.hpp"
#include "Entity.hpp"
#include "World.hpp"

int main() {

	//++AUDIO musique et sons	//pas de mp3

	sf::RenderWindow window(sf::VideoMode(1280, 720), "SFML works!");
	window.setVerticalSyncEnabled(true);
	window.setFramerateLimit(60);

	double tStart = getTimeStamp();
	double tEnterFrame = getTimeStamp();
	double tExitFrame = getTimeStamp();
	bool mouseLeftWasPressed = false;

	Entity * uWall = new Entity(Wall, new sf::RectangleShape(sf::Vector2f(1280, 10)));
	uWall->spr->setFillColor(sf::Color::Magenta);
	Entity * lWall = new Entity(Wall, new sf::RectangleShape(sf::Vector2f(10, 720)));
	lWall->spr->setFillColor(sf::Color::Magenta);
	lWall->spr->setOrigin(5, 0);
	Entity * rWall = new Entity(Wall, new sf::RectangleShape(sf::Vector2f(10, 720)));
	rWall->position = sf::Vector2f(1275, 0);
	rWall->spr->setOrigin(5, 0);
	rWall->spr->setFillColor(sf::Color::Magenta);

	Entity * player = new Entity(PlayerObject,new sf::RectangleShape(sf::Vector2f(75, 25)));
	player->position = sf::Vector2f(600, 600);
	//player->spr->setOrigin(sf::Vector2f(30, 6));
	
	Entity * ball = new Entity(Ball,new sf::CircleShape(10));
	ball->position = sf::Vector2f(player->position.x,player->position.y - 30);
	ball->spr->setFillColor(sf::Color::Green);
	ball->spr->setOrigin(10, 10);
	ball->speed = 1.25f;

	Entity * brick = new Entity(Brick, new sf::RectangleShape(sf::Vector2f(50,50)));
	brick->position = sf::Vector2f(600, 400);
	brick->spr->setFillColor(sf::Color::Red);

	World world;
	world.entities.push_back(player);
	world.entities.push_back(ball);
	world.entities.push_back(brick);

	world.entities.push_back(uWall);
	world.entities.push_back(lWall);
	world.entities.push_back(rWall);



	while (window.isOpen()) {
		sf::Event event;
		double dt = tExitFrame - tEnterFrame;
		tEnterFrame = getTimeStamp();
		while (window.pollEvent(event)) {
			if (event.type == sf::Event::Closed)
				window.close();
		}
		auto pos = player->position;
		double deltaX = dt * 500;
		double deltaY = dt * 500;
		bool keyHit = false;
		/*if (sf::Keyboard::isKeyPressed(sf::Keyboard::Left) || sf::Keyboard::isKeyPressed(sf::Keyboard::Q)) {
			pos.x -= deltaX;
			keyHit = true;
		}
		if (sf::Keyboard::isKeyPressed(sf::Keyboard::Right) || sf::Keyboard::isKeyPressed(sf::Keyboard::D)) {
			pos.x += deltaX;
			keyHit = true;
		}*/
		if (sf::Keyboard::isKeyPressed(sf::Keyboard::Left) || sf::Keyboard::isKeyPressed(sf::Keyboard::Q)) {
			pos.x -= deltaX;
			keyHit = true;
		}
		if (sf::Keyboard::isKeyPressed(sf::Keyboard::Right) || sf::Keyboard::isKeyPressed(sf::Keyboard::D)) {
			pos.x += deltaX;
			keyHit = true;
		}
		/*if (sf::Keyboard::isKeyPressed(sf::Keyboard::Up) || sf::Keyboard::isKeyPressed(sf::Keyboard::Z)) {
			pos.y -= deltaY;
			keyHit = true;
		}
		if (sf::Keyboard::isKeyPressed(sf::Keyboard::Down) || sf::Keyboard::isKeyPressed(sf::Keyboard::S)) {
			pos.y += deltaY;
			keyHit = true;
		}*/
		if (keyHit)
		{
			player->position = pos;
		}


		bool mouseLeftIsPressed = sf::Mouse::isButtonPressed(sf::Mouse::Left);
		bool mouseIsReleased = (!mouseLeftIsPressed && mouseLeftWasPressed);

		sf::Vector2f mousePos = sf::Vector2f(sf::Mouse::getPosition(window));

		if (mouseLeftIsPressed && !mouseLeftWasPressed) {
			auto pos = player->position;
			auto dir = mousePos - pos;
			float dirLen = std::sqrt(dir.x * dir.x + dir.y * dir.y);
			sf::Vector2f dxy(1, 0);
			if (dirLen) {
				dxy = dir / dirLen;
			}
			dxy *= 60.0f * 3;
			ball->move(dxy);
		}

		if (mouseLeftIsPressed)
			mouseLeftWasPressed = true;
		

		window.clear();

		world.draw(window);

		//player->update(dt);
		ball->update(dt);
		world.collide(dt);

		window.display();
		tExitFrame = getTimeStamp();

	}

	return 0;
}