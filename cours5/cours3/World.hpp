#pragma once
#include "Entity.hpp"
#include <SFML/Graphics/Rect.hpp>
#include <SFML/Graphics/RenderWindow.hpp>

#include "SFML/Audio/Sound.hpp"
#include "SFML/Audio/SoundBuffer.hpp"

/*class Audio {
public:
	Audio();
	sf::Sound ballPong;
	sf::SoundBuffer ballPongBuffer;

	sf::Sound music;
	SoundBuffer musicBuffer;
};*/

class World {
public:
	//Audio* audio = nullptr;
	std::vector<Entity*> entities;

	//World();

	void draw(sf::RenderWindow& window);
	void collide(double dt);
};