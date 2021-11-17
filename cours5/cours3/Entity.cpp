#include "pch.h"
#include "Entity.hpp"

using namespace sf;

void Entity::move(sf::Vector2f dir) {
	direction = dir;
}

void Entity::update(double dt) {
	spr->setPosition(position.x += (direction.x * dt)*speed,position.y += (direction.y * dt)*speed);
}

void Entity::draw(RenderWindow& window) {
	window.draw(*spr);
}
