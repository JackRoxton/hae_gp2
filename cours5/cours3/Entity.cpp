#include "pch.h"
#include "Entity.hpp"

using namespace sf;

void Entity::move(sf::Vector2f dir) {
	direction = dir;
}

void Entity::update(double dt) {
	spr->setPosition(position.x += (direction.x * dt),position.y += (direction.y * dt));
}

void Entity::draw(RenderWindow& window) {
	window.draw(*spr);
}
