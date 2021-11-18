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
#include "particle.hpp"
#include "Entity.hpp"
#include "World.hpp"

#include "Game.hpp"

float catmull(float p0, float p1, float p2, float p3, float t) {
	auto q = 2.0f * p1;
	auto t2 = t * t;

	q += (-p0 + p2) * t;
	q += (2.0f * p0 - 5.0f * p1 + 4.0f * p2 - p3) * t2;
	q += (-p0 + 3 * p1 - 3 * p2 + p3) * t2 * t;

	return 0.5f * q;
}

void drawMountain(sf::RenderWindow& window) {

	sf::VertexArray arr;
	arr.setPrimitiveType(sf::LineStrip);
	sf::Color col = sf::Color::Green;

	float baseline = 350;

	sf::Vector2f a(0, baseline + 50);
	sf::Vector2f b(400, baseline - 150);
	sf::Vector2f c(1100, baseline + 32);
	sf::Vector2f d(window.getSize().x, baseline);
	col.a = 100;

	col = sf::Color::Magenta;
	for (int i = 0; i < 256; ++i) {
		float t = 1.0f * i / 256;
		float x = catmull(a.x, a.x, b.x, c.x, t);
		float y = catmull(a.y, a.y, b.y, c.y, t);
		arr.append(sf::Vertex(sf::Vector2f(x, y), col));
	}
	for (int i = 0; i < 256; ++i) {
		float t = 1.0f * i / 256;
		float x = catmull(a.x, b.x, c.x, d.x, t);
		float y = catmull(a.y, b.y, c.y, d.y, t);
		arr.append(sf::Vertex(sf::Vector2f(x, y), col));
	}

	for (int i = 0; i < 256; ++i) {
		float t = 1.0f * i / 256;
		float x = catmull(b.x, c.x, d.x, d.x, t);
		float y = catmull(b.y, c.y, d.y, d.y, t);
		arr.append(sf::Vertex(sf::Vector2f(x, y), col));
	}
	window.draw(arr);
}

void drawGround(sf::RenderWindow& window) {
	sf::VertexArray arr;
	arr.setPrimitiveType(sf::LineStrip);
	sf::Color col = sf::Color::Yellow;

	float baseline = 600 + 60;

	sf::Vector2f a(0, baseline);
	sf::Vector2f b(window.getSize().x, baseline);

	arr.append(sf::Vertex(a, col));
	arr.append(sf::Vertex(b, col));

	window.draw(arr);
}

int main() {

	sf::Texture bg;
	bg.loadFromFile("res/texture.jpg");
	bg.setSmooth(true);

	//cout << std::files::current_path;
	char tmp[256];
	_getcwd(tmp, 256);
	cout << "Current working directory: " << tmp << endl;

	sf::Sprite bgspr;
	bgspr.setTexture(bg);

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
	player->position = sf::Vector2f(700, 700);
	//player->spr->setOrigin(sf::Vector2f(30, 6));
	
	Entity * ball = new Entity(Ball,new sf::CircleShape(10));
	ball->position = sf::Vector2f(player->position.x,player->position.y - 30);
	ball->spr->setFillColor(sf::Color::Green);
	ball->spr->setOrigin(10, 10);
	ball->speed = 1.5f;

	Game * _game = new Game();

	World world;
	world.game = _game;
	world.entities.push_back(player);
	world.entities.push_back(ball);
	for (int i = 0; i < 10; i++)
	{
		for (int j = 0; j < 4; j++) {

		Entity * brick = new Entity(Brick, new sf::RectangleShape(sf::Vector2f(50,25)));
		brick->position = sf::Vector2f(160 + 100 * i, 100 + 60 * j);
		brick->spr->setFillColor(sf::Color::Red);
		brick->spr->setOutlineColor(sf::Color::Yellow);
		brick->spr->setOutlineThickness(2);
		world.entities.push_back(brick);
		}
	}



	world.entities.push_back(uWall);
	world.entities.push_back(lWall);
	world.entities.push_back(rWall);

	Audio * _audio = new Audio();
	world.audio = _audio;

	_audio->music.play();


	while (window.isOpen()) {
		sf::Event event;
		double dt = tExitFrame - tEnterFrame;
		tEnterFrame = getTimeStamp();
		while (window.pollEvent(event)) {
			if (event.type == sf::Event::Closed)
				window.close();
		}
		auto pos = player->position;
		double deltaX = dt * 600;
		double deltaY = dt * 600;
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
		
		if (sf::Keyboard::isKeyPressed(sf::Keyboard::Up)) {
			sf::Vector2i windowPos = window.getPosition();
			window.setPosition(sf::Vector2i(100 + rand() % 25, 100 + rand() % 25));
		}

		window.clear();

		window.draw(bgspr);
		world.draw(window);


		//player->update(dt);
		ball->update(dt);
		world.collide(dt,window);

		window.display();
		tExitFrame = getTimeStamp();

	}

	return 0;
}