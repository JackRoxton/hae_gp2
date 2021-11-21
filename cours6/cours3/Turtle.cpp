#include "pch.h"
#include "Turtle.hpp"

void Turtle::draw(sf::RenderWindow& window) {
	window.draw(body,transform);
	window.draw(head,transform);
	if (drawState)
		drawBehind();
}

void Turtle::goForward(int pxl) {
	transform.translate(pxl,0);
}

void Turtle::turn(int deg) {
	transform.rotate(deg);
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

/*void Turtle::applyCmd(Cmd * cmd) {
	
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
}*/