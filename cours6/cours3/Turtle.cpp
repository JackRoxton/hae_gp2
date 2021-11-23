#include "pch.h"
#include "Turtle.hpp"

void Turtle::draw(sf::RenderWindow& window) {
	window.draw(body,transform);
	window.draw(head,transform);

	drawText.display();
	sf::Sprite s;
	s.setTexture(drawText.getTexture());
	window.draw(s);



	if (drawState)
		drawBehind(window);
}

void Turtle::update() {


	while (cmds) {
		applyCmd(cmds);
		cmds = cmds->popFirst();
	}
}

void Turtle::goForward(int pxl) {
	transform.translate(pxl,0);
}

void Turtle::turn(int deg) {
	transform.rotate(deg);
}

void Turtle::doDraw(bool state) {
	drawState = state;
}

void Turtle::drawBehind(sf::RenderWindow& window) {
	sf::CircleShape tmp = sf::CircleShape(1);
	tmp.setFillColor(drawColor);
	drawText.draw(tmp,transform);
}

void Turtle::changeColor(sf::Color color) {
	drawColor = color;
}



void Turtle::applyCmd(Cmd * cmd) {

	if (!cmd) {
		return;
	}

	//appliquer
	switch (cmd->command)
	{
	case Forward: goForward(cmd->currentVal);
	break;
	case Turn: turn(cmd->currentVal);
	break;
	case DrawUp: doDraw(true);
	break;
	case DrawDown: doDraw(false);
	break;
	}

}

void Turtle::addCmd(Cmd * cmd) {

	//ajouter commande
	if (cmds == nullptr)
		cmds = cmd;
	else
		cmds = cmds->append(cmd);

}