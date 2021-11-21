#pragma once
#include <SFML/Graphics.hpp>
#include <SFML/Graphics/RenderWindow.hpp>

enum CmdType {
	Forward,
	Turn,
};

struct Cmd {
public:
	Cmd* data;
	float currentCmd = 0;
	Cmd* next = nullptr;
};

class Turtle{
public:
	sf::Transform transform;
	float rotation;
	sf::CircleShape body;
	sf::RectangleShape head;
	bool drawState = true;
	sf::Color drawColor = sf::Color::Magenta;

	int runSpeed = 10;
	float turnSpeed = 10;

	Turtle() {
		transform.transformPoint(sf::Vector2f(200, 200));
		body = sf::CircleShape(32);
		body.setOrigin(32, 32);
		body.setFillColor(sf::Color::Green);
		head = sf::RectangleShape(sf::Vector2f(16, 16));
		head.setOrigin(-28, 8);
		head.setFillColor(sf::Color::Red);
	}

	void draw(sf::RenderWindow& window);

	void goForward(int pxl);
	void turn(int deg);
	void doDraw();
	void doNotDraw();
	void changeColor(sf::Color color);
	void drawBehind();

	void applyCmd(CmdType command);
	void addCmd(CmdType command);
};