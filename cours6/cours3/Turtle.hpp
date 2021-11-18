#pragma once
#include <SFML/Graphics.hpp>
#include <SFML/Graphics/RenderWindow.hpp>

enum CmdType {
	Forward,
	Backward,
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
	//sf::Transform au cazou
	sf::CircleShape body;
	sf::Vector2f bodyPos;
	sf::RectangleShape head;
	sf::Vector2f headPos;
	float rotation;
	bool drawState = true;
	sf::Color drawColor = sf::Color::Magenta;

	int runSpeed = 10;
	float turnSpeed = 10;

	Turtle() {
		body = sf::CircleShape(32);
		body.setPosition(200,200);
		body.setOrigin(32, 32);
		body.setFillColor(sf::Color::Green);
		bodyPos = body.getPosition();
		head = sf::RectangleShape(sf::Vector2f(16, 16));
		head.setPosition(200,200);
		head.setOrigin(-28, 8);
		head.setFillColor(sf::Color::Red);
		headPos = head.getPosition();
		rotation = body.getRotation();
	}

	void draw(sf::RenderWindow& window);

	void goForward(int pxl);
	void goBackwards(int pxl);
	void turn(int deg);
	void doDraw();
	void doNotDraw();
	void changeColor(sf::Color color);
	void drawBehind();

	void applyCmd(CmdType command);
	void addCmd(CmdType command);
};