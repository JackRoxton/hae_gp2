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

#include "Entity.hpp"

#include "imgui/imgui.h"
#include "imgui\imgui-SFML.h"

int main() {
	sf::RenderWindow window(sf::VideoMode(1280, 720), "SFML works!");
	window.setVerticalSyncEnabled(true);
	window.setFramerateLimit(60);

	sf::CircleShape* shp = new sf::CircleShape(8);
	shp->setOutlineThickness(2);
	shp->setOutlineColor(sf::Color::Green);
	shp->setFillColor(sf::Color::Yellow);
	shp->setOrigin(4, 8);
	Entity * player = new Entity(shp, window.getSize().x/Entity::stride * 0.5, window.getSize().y/Entity::stride);

	sf::CircleShape* _shp = new sf::CircleShape(8);
	_shp->setOutlineThickness(2);
	_shp->setOutlineColor(sf::Color::Magenta);
	_shp->setFillColor(sf::Color::Red);
	_shp->setOrigin(4, 8);
	Entity * ball = new Entity(_shp, window.getSize().x / Entity::stride * 0.25, window.getSize().y / Entity::stride);

	ImGui::SFML::Init(window);
	sf::Clock deltaClock;


	double tStart = getTimeStamp();
	double tEnterFrame = getTimeStamp();
	double tExitFrame = getTimeStamp();

	while (window.isOpen()) {
		sf::Event event;
		double dt = tExitFrame - tEnterFrame;
		tEnterFrame = getTimeStamp();
		while (window.pollEvent(event)) {
			ImGui::SFML::ProcessEvent(window, event);
			if (event.type == sf::Event::Closed)
				window.close();
		}

	#pragma region Move

		float speed = 7.5f;
		if (sf::Keyboard::isKeyPressed(sf::Keyboard::Z) || sf::Keyboard::isKeyPressed(sf::Keyboard::Up)) {
			player->dy = -speed *dt;
		}
		if (sf::Keyboard::isKeyPressed(sf::Keyboard::Q) || sf::Keyboard::isKeyPressed(sf::Keyboard::Left)) {
			player->dx = -speed *dt;
		}
		if (sf::Keyboard::isKeyPressed(sf::Keyboard::S) || sf::Keyboard::isKeyPressed(sf::Keyboard::Down)) {
			player->dy = speed *dt;
		}
		if (sf::Keyboard::isKeyPressed(sf::Keyboard::D) || sf::Keyboard::isKeyPressed(sf::Keyboard::Right)) {
			player->dx = speed *dt;
		}

	#pragma endregion

		ImGui::SFML::Update(window, deltaClock.restart());

		//ImGui::ShowDemoWindow();

		ImGui::Begin("Coords");
		ImGui::Value("cx", player->cx);
		ImGui::Value("cy", player->cy);
		ImGui::Value("xx", player->xx);
		ImGui::Value("yy", player->yy);
		ImGui::Value("xr", player->xr);
		ImGui::Value("yr", player->yr);

		ImGui::Value("cx", ball->cx);
		ImGui::Value("cy", ball->cy);
		ImGui::Value("xx", ball->xx);
		ImGui::Value("yy", ball->yy);
		ImGui::Value("xr", ball->xr);
		ImGui::Value("yr", ball->yr);
		ImGui::End();
	
		player->update(dt);
		ball->update(dt);

		window.clear();

		ImGui::SFML::Render(window);
		player->draw(window);
		ball->draw(window);

		window.display();
		tExitFrame = getTimeStamp();
	}
	ImGui::SFML::Shutdown();

	return 0;
}