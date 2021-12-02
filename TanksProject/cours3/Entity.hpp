#pragma once
#include "SFML/Graphics/Shape.hpp"
#include <SFML/Graphics/Rect.hpp>
#include <SFML/Graphics/RenderWindow.hpp>

using namespace sf;

enum EType {
	Player,
	IA,
	Wall,
	Brick,
	Hole,
	Missile,
};

class Entity {
public :
	Shape* spr = nullptr;
	Vector2f position;
	Vector2f direction;
	EType type;

	Entity(EType _type,  Shape * _spr) {
		type = _type;
		spr = _spr;
	}

	~Entity() {
		if (spr) {
			delete spr;
			spr = nullptr;
		}
	}

	void move(Vector2f dir);
	void update(double dt);
	void draw(RenderWindow& window);
};

