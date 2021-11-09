#pragma once
#include "SFML/Graphics/Shape.hpp"
class Entity {
public :
	sf::Shape* spr = nullptr;
	sf::FloatRect hitBox;

	Entity(sf::Shape* _spr) {
		hitBox.width = 32;
		hitBox.height = 32;
	}
};

class EntityManager {
public:
	std::vector<Entity*> repository;
};