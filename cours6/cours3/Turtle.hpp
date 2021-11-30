#pragma once
#include <SFML/Graphics.hpp>
#include <SFML/Graphics/RenderWindow.hpp>
#include <SFML/Graphics/Sprite.hpp>

enum CmdType {
	Forward,
	Turn,
	DrawUp,
	DrawDown,
	DrawColor,
};

struct Cmd {
public:
	float currentVal = 0;
	float originalVal = 0;
	CmdType command = Forward;
	Cmd* next = nullptr;

	Cmd(CmdType c, float val) {
		command = c;
		currentVal = val;
		originalVal = val;
	}

	Cmd * append(Cmd * cmd) {
		if (next == nullptr) {
			next = cmd;
		}
		else {
			next->append(cmd);
		}
		return this;
	}

	Cmd * popFirst() {
		Cmd * cmd = next;
		delete this;
		return cmd;
	}
};

class Turtle{
public:
	
	sf::CircleShape body;
	sf::RectangleShape head;
	bool drawState = true;
	sf::Color drawColor = sf::Color::Magenta;
	float penColor[3] = {(float) 204 / 255,(float)77 / 255,(float)5 / 255 };
	float timer = 1.0f;
	sf::RenderTexture drawText;

	Cmd * cmds = nullptr;
	//Cmd * archive = nullptr;

	/*int runSpeed = 10;
	float turnSpeed = 10;*/

	Turtle() {
		transform.translate(sf::Vector2f(200, 200));
		body = sf::CircleShape(32);
		body.setOrigin(32, 32);
		body.setFillColor(sf::Color::Green);
		head = sf::RectangleShape(sf::Vector2f(16, 16));
		head.setOrigin(-28, 8);
		head.setFillColor(sf::Color::Red);

		drawText.create(1280, 720);
	}

	void draw(sf::RenderWindow& window);
	void update(double dt);

	void goForward(int pxl);
	void turn(int deg);
	void doDraw(bool state);
	void changeColor(sf::Color color);

	void drawBehind(sf::RenderWindow& window);

	void applyCmd(Cmd* cmd);
	void addCmd(Cmd* cmd);

	void reset();

	void saveAll(FILE * file);
	void saveOnce(FILE * file,Cmd* cmd);

protected:
	sf::Transform transform;
};