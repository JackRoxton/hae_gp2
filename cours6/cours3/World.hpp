#pragma once
#include "Entity.hpp"
#include <SFML/Graphics/Rect.hpp>
#include <SFML/Graphics/RenderWindow.hpp>

#include "SFML/Audio/Sound.hpp"
#include "SFML/Audio/Music.hpp"
#include "SFML/Audio/SoundBuffer.hpp"
#include "Game.hpp"

class Audio {
public:
	Audio();
	sf::Sound ballPong;
	sf::SoundBuffer ballPongBuffer;

	sf::Music music;
};

class World {
public:
	Audio* audio = nullptr;
	Game* game = nullptr;
	std::vector<Entity*> entities;
	std::vector<Entity*> toBreak;

	//World();

	void draw(sf::RenderWindow& window);
	void collide(double dt, sf::RenderWindow& win);
	void breakBricks();
};