#pragma once
#include <iostream>
#include <SFML/Graphics/RenderWindow.hpp>
#include <SFML/Graphics/CircleShape.hpp>

class particle {
public:
	sf::CircleShape shape;

	std::vector<float> px, py, dx, dy;

	std::vector<bool> alive;

	particle();

	void create(float px, float py, float dx, float dy);
	void update(double dt);
	void draw(sf::RenderWindow& window);
};