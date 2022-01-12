#pragma once
#include "Entity.hpp"
#include <SFML/Graphics/Rect.hpp>
#include <SFML/Graphics/RenderWindow.hpp>

#include "SFML/Audio/Sound.hpp"
#include "SFML/Audio/Music.hpp"
#include "SFML/Audio/SoundBuffer.hpp"
#include "Entity.hpp"

class Entity;
enum EType;

class Audio {
public:
	Audio();
	sf::Sound expl;
	sf::SoundBuffer explBuffer;
	sf::Sound over;
	sf::SoundBuffer overBuffer;

	sf::Music music;
};

enum GameState {
	_Menu,
	_Game,
	_GameOver,
	_GameWon
};

class World {
public:
	Audio* audio = nullptr;
	std::vector<Entity*> entities;

	int playerLives = 0;
	float IFrames = 1;
	int iaCount = 0;

	std::vector<Entity*> Level;

	GameState gameState = _Menu;           

	void collide(double dt, sf::RenderWindow& win);

	void ColMissile(Entity* e, Entity* f);
	void ColPlayerIa(Entity* e, Entity* f);
	void CreateMissile(sf::Vector2f pos, sf::Vector2f dir, EType type);

	void LoadLevel(Entity* player, int nb);
	void UnLoadLevel();

	void GameOver();
	void GameWon();
};
