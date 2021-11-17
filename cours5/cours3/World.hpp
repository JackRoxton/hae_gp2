#pragma once
#include "Entity.hpp"
#include <SFML/Graphics/Rect.hpp>
#include <SFML/Graphics/RenderWindow.hpp>

class World {
public:
	std::vector<Entity*> entities;

	//World();

	void draw(sf::RenderWindow& window);
	void collide(double dt);
};