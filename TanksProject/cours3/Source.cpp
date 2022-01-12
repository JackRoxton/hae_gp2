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

#include "World.hpp"
#include "Entity.hpp"

#include "imgui/imgui.h"
#include "imgui\imgui-SFML.h"

int main() {
	sf::RenderWindow window(sf::VideoMode(1280, 720), "Tanks works!");
	window.setVerticalSyncEnabled(true);
	window.setFramerateLimit(120);

	/*char tmp[256];
	_getcwd(tmp, 256);
	cout << "Current working directory: " << tmp << endl;*/

	World * world = new World;

	Entity * ePlayer = new Entity(_Player, new sf::RectangleShape(sf::Vector2f(25, 25)), sf::Vector2f(1000, 700));
	ePlayer->spr->setFillColor(sf::Color::Green);
	ePlayer->spr->setOrigin(12.5f,12.5f);

	RectangleShape * button1 = new RectangleShape(Vector2f(225, 100));
	button1->setPosition(60, 400);
	RectangleShape * button2 = new RectangleShape(Vector2f(225, 100));
	button2->setPosition(60, 575);
	RectangleShape * button3 = new RectangleShape(Vector2f(225, 100));
	button3->setPosition(420, 575);


	sf::Texture menutxt;
	menutxt.loadFromFile("res/EcranTitre.png");
	sf::Sprite menuspr;
	menuspr.setTexture(menutxt);

	sf::Texture wontxt;
	wontxt.loadFromFile("res/GameWon.png");
	sf::Sprite wonspr;
	wonspr.setTexture(wontxt);

	sf::Texture overtxt;
	overtxt.loadFromFile("res/GameOver.png");
	sf::Sprite overspr;
	overspr.setTexture(overtxt);

	sf::Texture hearttxt;
	hearttxt.loadFromFile("res/Heart.png");
	sf::Sprite heartspr;
	heartspr.setTexture(hearttxt);
	heartspr.setScale(0.10,0.10);

	Audio * _audio = new Audio();
	world->audio = _audio;

	_audio->music.play();


	world->entities.push_back(ePlayer);

	float timerShoot = 1;
	float timerScreen = 5;

	double tStart = getTimeStamp();
	double tEnterFrame = getTimeStamp();
	double tExitFrame = getTimeStamp();

	auto mousePress = Mouse::isButtonPressed(Mouse::Left);
	/*bool aKey = false;
	bool bKey = false;*/

	while (window.isOpen()) {

		sf::Event event;
		double dt = tExitFrame - tEnterFrame;
		tEnterFrame = getTimeStamp();
		while (window.pollEvent(event)) {
			if (event.type == sf::Event::Closed)
				window.close();
		}	

		if (Keyboard::isKeyPressed(sf::Keyboard::D) && world->gameState == _Game) {
			ePlayer->move(sf::Vector2f(100, 0));
		}
		if (Keyboard::isKeyPressed(sf::Keyboard::Q) && world->gameState == _Game) {
			ePlayer->move(sf::Vector2f(-100, 0));
		}
		if (Keyboard::isKeyPressed(sf::Keyboard::Z) && world->gameState == _Game) {
			ePlayer->move(sf::Vector2f(0, -100));
		}
		if (Keyboard::isKeyPressed(sf::Keyboard::S) && world->gameState == _Game) {
			ePlayer->move(sf::Vector2f(0, 100));
		}

		/*if (Keyboard::isKeyPressed(sf::Keyboard::A) && !aKey) {
			world->LoadLevel(ePlayer,1);
			aKey = true;
		}
		if (Keyboard::isKeyPressed(sf::Keyboard::B) && !bKey) {
			world->UnLoadLevel();
			bKey = true;
		}*/


		if (timerShoot > 0) {
			timerShoot -= dt;
		}

		if (world->gameState == _Menu) {
			ePlayer->position = Vector2f(1000, 800);
			ePlayer->doDraw = false;
		}

		if (Mouse::isButtonPressed(Mouse::Left) && !mousePress){
			if (world->gameState == _Menu) {
				//buttons
				if (sf::Mouse::getPosition(window).x > button1->getPosition().x && sf::Mouse::getPosition(window).x < (button1->getPosition().x + button1->getSize().x)) {
					if (sf::Mouse::getPosition(window).y > button1->getPosition().y && sf::Mouse::getPosition(window).y < (button1->getPosition().y + button1->getSize().y)) {
						world->LoadLevel(ePlayer, 1);
					}
				}
				if (sf::Mouse::getPosition(window).x > button2->getPosition().x && sf::Mouse::getPosition(window).x < (button2->getPosition().x + button2->getSize().x)) {
					if (sf::Mouse::getPosition(window).y > button2->getPosition().y && sf::Mouse::getPosition(window).y < (button2->getPosition().y + button2->getSize().y)) {
						world->LoadLevel(ePlayer, 2);
					}
				}
				if (sf::Mouse::getPosition(window).x > button3->getPosition().x && sf::Mouse::getPosition(window).x < (button3->getPosition().x + button3->getSize().x)) {
					if (sf::Mouse::getPosition(window).y > button3->getPosition().y && sf::Mouse::getPosition(window).y < (button3->getPosition().y + button3->getSize().y)) {
						world->LoadLevel(ePlayer, 3);
					}
				}
			}
			else if (world->gameState == _Game && timerShoot <= 0) {
				//player shoot;
				sf::Vector2f characterToMouse(sf::Mouse::getPosition(window).x - ePlayer->spr->getPosition().x,
					sf::Mouse::getPosition(window).y - ePlayer->spr->getPosition().y);
				world->CreateMissile(ePlayer->gun->getPosition(),characterToMouse,_MissilePl);
				timerShoot = 1;
			}
		}
		mousePress = Mouse::isButtonPressed(Mouse::Left);

		window.clear();
		world->collide(dt,window);
		if (world->gameState == _Game) {
			if (world->IFrames > 0) {
				world->IFrames -= dt;
			}
			
			for (int i = 0; i < world->playerLives; i++) {
				heartspr.setPosition(Vector2f(1200,100+100*i));
				window.draw(heartspr);
			}
		}
		else if (world->gameState == _Menu) {
			window.draw(menuspr);
		}
		else if (world->gameState == _GameOver) {
			window.draw(overspr);
			timerScreen -= dt;
			if (timerScreen <= 0) {
				world->gameState = _Menu;
				timerScreen = 5;
			}
		}
		else if (world->gameState == _GameWon) {
			window.draw(wonspr);
			timerScreen -= dt;
			if (timerScreen <= 0) {
				world->gameState = _Menu;
				timerScreen = 5;
			}
		}
		window.display();
		tExitFrame = getTimeStamp();
	}

	return 0;
}