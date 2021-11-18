#include "pch.h"
#include "Game.hpp"

void Game::createParticles() {

}

void Game::createShake(sf::RenderWindow& win) {
	win.setPosition(sf::Vector2i(100 + rand() % 25, 100 + rand() % 25));
}
