#include "Entity.hpp"
#include "SFML/Window/Mouse.hpp"

using namespace sf;

int clamp(int a,int limitmax,int limitmin) {
	if (a > limitmax) {
		a = limitmax;
	}
	else if (a < limitmin){
		a = limitmin;
	}
	return a;
}

int nrm(int a, int up, int dwn) {
	if (a > 0) {
		a = up;
	}
	else if (a < 0) {
		a = dwn;
	}
	return a;
}

void Entity::move(sf::Vector2f dir) {
	direction += dir;
	direction.x = clamp(direction.x, 100 * speed, -100 * speed);
	direction.y = clamp(direction.y, 100 * speed, -100 * speed);
}


void Entity::update(double dt, RenderWindow& window) {
	spr->setPosition(position.x += (direction.x * dt)*speed, position.y += (direction.y * dt)*speed);
	if (type == _MissilePl) {
		spr->setRotation(atan2((position.x + (direction.x * dt)*speed) - position.x,
			- ((position.y + (direction.y * dt)*speed) - position.y)) * 57.2958);
		timer -= dt;
		if (timer <= 0) {
			this->~Entity();
			return;
		}
	}
	else if (type == _MissileIA) {//durée de vie
		spr->setRotation(atan2((position.x + (direction.x * dt)*speed) - position.x,
			-((position.y + (direction.y * dt)*speed) - position.y)) * 57.2958);
		if (doDraw) {
			timer -= dt;
		}
		if (timer <= 0) {
			this->position = Vector2f(1200, 700);
			this->doDraw = false;
			timer = 3;
		}
		return;
	}
	else if (type == _Player) {
		spr->setRotation(atan2((position.x + (direction.x * dt)*speed) - position.x,
			-((position.y + (direction.y * dt)*speed) - position.y)) * 57.2958);

		gun->setPosition(position.x, position.y);
		sf::Vector2f characterToMouse(sf::Mouse::getPosition(window).y - gun->getPosition().y,
			sf::Mouse::getPosition(window).x - gun->getPosition().x);
		float angle = atan2(characterToMouse.x, characterToMouse.y);
		gun->setRotation(angle * 57.2958);

		direction = sf::Vector2f(0, 0);
	}
	else if (type == _IA) {
		spr->setRotation(atan2((position.x + direction.x) - position.x,
			-((position.y + direction.y) - position.y)) * 57.2958);
		gun->setRotation(spr->getRotation()-90);

		gun->setPosition(position.x, position.y);
		timer -= dt;
		if (timer <= 0) {
			float val1 = rand() % 100;
			if (val1 > 49) {
				val1 -= 100;
			}
			float val2 = rand() % 100;
			if (val2 > 49) {
				val2 -= 100;
			}
			this->move(sf::Vector2f(val1, val2));

			float shoot = rand() % 3;
			if (shoot == 0) {
				missile->position = position;
				missile->move(Vector2f(nrm(direction.x,100,-100),nrm(direction.y,100,-100)));
				missile->doDraw = true;
			}

			timer = 1 + rand() % 2;
		}
	}
}

void Entity::draw(RenderWindow& window) {
	if (doDraw) {
		if (spr)
			window.draw(*spr);

		if (type == _Player || type == _IA) {
			window.draw(*gun);
		}
	}
}


