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

void Turtle::update(double dt) {

	if (cmds) {  // if ou while ?
		applyCmd(cmds);
		cmds = cmds->popFirst();
	}
}

void Turtle::goForward(int pxl) { //faire ça 100/val% fois en multipliant pxl par val% pour un smooth ?
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

	//ajouter un timer ou un smooth pour pas que ça se téléporte depuis le fichier
	if (!cmd) {
		return;
	}
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
	if(archive == nullptr)
		archive = cmd;
	else
		archive = archive->append(cmd);//boucle infinie ?

	if (cmds == nullptr){
		cmds = cmd;
	}
	else {
		cmds = cmds->append(cmd);
	}
}

void Turtle::reset() {
	transform = transform.Identity;
	transform.translate(200, 200);
	drawText.clear(sf::Color(0,0,0,0));
	while (cmds) {
		cmds = cmds->popFirst();
	}
}

void Turtle::saveAll(FILE * file) {
	fopen_s(&file, "res/save.txt", "a");

	saveOnce(file,archive);

	fflush(file);
	fclose(file);
}

void Turtle::saveOnce(FILE * file, Cmd* cmd) {

	switch (cmd->command)
	{
	case Forward: {
		char fwd[] = "Forward\n";
		fwrite(fwd, strlen(fwd), 1, file);
		//fprintf(file,"Forward\n");
		break;
	}
	case Turn: {
		char t[] = "Turn\n";
		fwrite(t, strlen(t), 1, file);
		break;
	}
	case DrawUp: {
		char du[] = "DrawUp\n";
		fwrite(du, strlen(du), 1, file);
		break; 
	}
	case DrawDown: {
		char dd[] = "DrawDown\n";
		fwrite(dd, strlen(dd), 1, file);
		break;
	}
	}

}