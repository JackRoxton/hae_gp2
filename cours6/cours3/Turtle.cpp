#include "pch.h"
#include "Turtle.hpp"

void Turtle::draw(sf::RenderWindow& window) {
	window.draw(body);
	window.draw(head);
	if (drawState)
		drawBehind();
}

void Turtle::goForward(int pxl) {	//avancer dans la direction du regard
	sf::Vector2f bP = sf::Vector2f(bodyPos.x + pxl, bodyPos.y);
	sf::Vector2f hP = sf::Vector2f(headPos.x + pxl, headPos.y);
	body.setPosition(bP);
	head.setPosition(hP);
	bodyPos = body.getPosition();
	headPos = head.getPosition();
}

void Turtle::goBackwards(int pxl) {
	goForward(-pxl);
}

void Turtle::turn(int deg) {
	body.setRotation(rotation + deg);
	head.setRotation(body.getRotation());
	rotation = body.getRotation();
}

void Turtle::doDraw() {
	drawState = true;
}

void Turtle::doNotDraw() {
	drawState = false;
}

void Turtle::drawBehind() {

}

void Turtle::changeColor(sf::Color color) {
	drawColor = color;
}

void Turtle::applyCmd(Cmd * cmd) {
	
	if (cmd->command == Forward){
		goForward(runSpeed);
	}
	else if (command == Backward) {
		goBackwards(runSpeed);
	}
	else if (command == Turn) {
		turn(turnSpeed);
	}
}

void Turtle::addCmd(Cmd * cmd) {
	Cmd * nextCmd = new Cmd();
	nextCmd->currentCmd = command;
}