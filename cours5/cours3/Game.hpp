#pragma once
#include <SFML/Graphics/RenderWindow.hpp>

class Game {
public:
	int particle = 0;
	int shake = 0;
	int score = 0;

	void createParticles();
	void createShake(sf::RenderWindow& win);
};