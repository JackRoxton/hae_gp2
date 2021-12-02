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

#include "FileWatcher.hpp"

#include "imgui/imgui.h"
#include "imgui\imgui-SFML.h"

int main() {
	sf::RenderWindow window(sf::VideoMode(1280, 720), "Tanks works!");
	window.setVerticalSyncEnabled(true);
	//window.setFramerateLimit(60);
	//ImGui::SFML::Init(window);
	//sf::Clock deltaClock;

	char tmp[256];
	_getcwd(tmp, 256);
	cout << "Current working directory: " << tmp << endl;


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


		



		//ImGui::SFML::Update(window, deltaClock.restart());
		//ImGui::ShowDemoWindow();
		window.clear();
		//ImGui::SFML::Render(window);
		window.display();
		tExitFrame = getTimeStamp();
	}
	//ImGui::SFML::Shutdown();

	return 0;
}