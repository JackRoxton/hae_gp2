#pragma once
#include <iostream>
#include <SFML/Graphics/RenderWindow.hpp>
#include <SFML/Graphics/CircleShape.hpp>

class particle {
public:
	sf::CircleShape shape;
	sf::FloatRect hitBox;

	std::vector<float> px;
	std::vector<float> py;
	std::vector<float> dx;
	std::vector<float> dy;

	std::vector<bool> alive;

	particle();

	void create(float px, float py, float dx, float dy);
	void update(double dt);
	//void simpleBounce(sf::FloatRect HB);
	void draw(sf::RenderWindow& window);
};