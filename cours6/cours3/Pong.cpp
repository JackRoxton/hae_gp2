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
	sf::RenderWindow window(sf::VideoMode(1280, 720), "SFML works!");
	window.setVerticalSyncEnabled(true);
	//window.setFramerateLimit(60);

	ImGui::SFML::Init(window);


	sf::Clock deltaClock;

	Turtle * turtle = new Turtle();
	int turtleRunSpeed = 10;
	float turtleTurnSpeed = 10;

	char tmp[256];
	_getcwd(tmp, 256);
	cout << "Current working directory: " << tmp << endl;


	double tStart = getTimeStamp();
	double tEnterFrame = getTimeStamp();
	double tExitFrame = getTimeStamp();
	bool mouseLeftWasPressed = false;

	bool flagO;
	bool flagOwp;
	FILE * file = nullptr;
	FileWatcher* fW = new FileWatcher();
	bool reinterpret = false;
	float timer = 0.0f;



	bool imguiBtSave = false;
	bool imguiBtLoad = false;
	bool imguiForward = false, imguiTurn = false;
	float imguiSpeed = 10, imguiTurnSpeed = 10;
	bool showTools = true;
	float bg[3] = {0,0,0};

	char commandText[256] = "";

	int nTxt = 0;


	while (window.isOpen()) {
		sf::Event event;
		double dt = tExitFrame - tEnterFrame;
		tEnterFrame = getTimeStamp();
		while (window.pollEvent(event)) {
		ImGui::SFML::ProcessEvent(window, event);
			if (event.type == sf::Event::Closed)
				window.close();
		}


		if (timer >= 0.5f) {
			if (fW->hasChanged()) {
				reinterpret = true;
				turtle->reset();
			}
			timer = 0.0f;
		}

		if (imguiBtSave) {
			turtle->saveAll(file);
		}
	
		flagO = sf::Keyboard::isKeyPressed(sf::Keyboard::O);
		if (reinterpret||imguiBtLoad) {
			fopen_s(&file,"res/ui.txt", "rb");

			if (!file)
				printf("file error ");

			char line[256] = {};
			if (file && !feof(file)) { //reinterpret
				while (true) { 
					int64_t nb = 0;
					fscanf_s(file, "%s %lld\n", line, 256, &nb);
					std::string s = line;
					if (s == "Forward") {
						turtle->addCmd(new Cmd(Forward, nb));
					}
					if (s == "Turn") {
						turtle->addCmd(new Cmd(Turn, nb));
					}
					if (s == "DrawUp") {
						turtle->addCmd(new Cmd(DrawUp, nb));
					}
					if (s == "DrawDown") {
						turtle->addCmd(new Cmd(DrawDown, nb));
					}
					if (s == "DrawColor") {
						//turtle->changeColor(sf::Color(unsigned int)nb) //couleurs en hexadécimal ou r g b
					}
					if (feof(file)) {
						break;
					}
				}
				fclose(file);
			}
			reinterpret = false;
		}
	flagOwp = sf::Keyboard::isKeyPressed(sf::Keyboard::O);

		/*if (sf::Keyboard::isKeyPressed(sf::Keyboard::Up) || sf::Keyboard::isKeyPressed(sf::Keyboard::Z)) {
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
		auto pos = player->position;
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
		}
		bool mouseLeftIsPressed = sf::Mouse::isButtonPressed(sf::Mouse::Left);
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

	if (imguiForward) {
		turtle->addCmd(new Cmd(Forward, imguiSpeed));
	}
	if (imguiTurn) {
		turtle->addCmd(new Cmd(Turn, imguiTurnSpeed));
	}

	if (sf::Keyboard::isKeyPressed(sf::Keyboard::Escape)) {
		if (showTools)
			showTools = false;
		else
			showTools = true;
	}




		ImGui::SFML::Update(window, deltaClock.restart());
		ImGui::ShowDemoWindow();

		//faire liste éditable en temps réel
		//pouvoir l'envoyer en commandes à la tortue

		if (showTools){
			ImGui::SetNextWindowBgAlpha(0.1f);
			ImGui::Begin("Window.exe");
			ImGui::ColorEdit3("PickDrawColor", turtle->penColor);

			ImGui::ColorEdit3("PickBgColor",bg);
			

			/*ImGui::Begin("Save-Loader");
			if (ImGui::Button("Load"))
				imguiBtLoad = true;
			else
				imguiBtLoad = false;

			if (ImGui::Button("Save"))
				imguiBtSave = true;
			else
				imguiBtSave = false;

			ImGui::End();*/

			if (ImGui::Button("Forward"))
				imguiForward = true;
			else
				imguiForward = false;

			if (ImGui::Button("Turn"))
				imguiTurn = true;
			else
				imguiTurn = false;

			ImGui::SliderFloat("speed", &imguiSpeed, -50.0f, 50.0f);
			ImGui::SliderFloat("turn speed", &imguiTurnSpeed, -50.0f, 50.0f);

			//ImGui::ProgressBar(0.5f);

			/*ImGui::Begin("CommandsInput");
			ImGui::InputTextMultiline("commands", commandText, IM_ARRAYSIZE(commandText));
			ImGui::End();*/
			static Cmd * head = nullptr;

			ImGui::Text("commands");

			if (ImGui::Button("+")) {
				auto p = new Cmd(Forward,imguiSpeed);

				if (nullptr == head) {
					head = p;
				}
				else {
					head = head->append(p);
				}
			}

			ImGui::Separator();

			int idx = 0;
			auto h = head;
			while (h) {
				ImGui::PushID(idx);
				ImGui::Value("idx", idx);
				//
				static const char* items[] = { "Forward",
												"Turn",
												"DrawUp",
												"DrawDown",};
				ImGui::Combo("CmdType", (int*)&h->command, items,IM_ARRAYSIZE(items));
				//
				if(h->command != DrawUp && h->command != DrawDown)
					ImGui::DragFloat("value", &h->currentVal);
				ImGui::NewLine();
				ImGui::Separator();
				h = h->next;
				idx++;
				ImGui::PopID();
			}



			if (ImGui::Button("Run")) {
				if (!turtle->cmds){
					turtle->cmds = head;
					head = nullptr;
				}
			}
			ImGui::SameLine();
			if (ImGui::Button("Load")) {
				FILE * file;
				fopen_s(&file, "res/save.txt","rb");
				char line[256] = {};
				if (file && !feof(file)) { //reinterpret
					while (true) {
						int64_t nb = 0;
						fscanf_s(file, "%s %lld\n", line, 256, &nb);
						std::string s = line;
						if (s == "Forward") {
							if (nullptr == head) {
								head = new Cmd(Forward, nb);
							}
							else {
								head = head->append(new Cmd(Forward, nb));
							}
						}
						if (s == "Turn") {
							if (nullptr == head) {
								head = new Cmd(Turn, nb);
							}
							else {
								head = head->append(new Cmd(Turn, nb));
							}
						}
						if (s == "DrawUp") {
							if (nullptr == head) {
								head = new Cmd(DrawUp, nb);
							}
							else {
								head = head->append(new Cmd(DrawUp, nb));
							}
						}
						if (s == "DrawDown") {
							if (nullptr == head) {
								head = new Cmd(DrawDown,nb);
							}
							else {
								head = head->append(new Cmd(DrawDown,nb));
							}
						}
						if (feof(file)) {
							break;
						}
					}
				}
				fclose(file);
			}
			ImGui::SameLine();
			if (ImGui::Button("Save")) {
				auto u = head;
				FILE * file;
				fopen_s(&file, "res/save.txt", "w");
				while (u){
					turtle->saveOnce(file, u);
					u = u->next;
				}
				fclose(file);

			}
			ImGui::SameLine();
			if (ImGui::Button("Clear")) {

			}

			ImGui::End();
		}

		window.clear(sf::Color(bg[0]*255, bg[1]*255, bg[2]*255));

		turtle->update(dt);
		turtle->draw(window);

		ImGui::SFML::Render(window);

		window.display();
		tExitFrame = getTimeStamp();
		timer += dt;
	}
	ImGui::SFML::Shutdown();

	return 0;
}