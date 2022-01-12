#pragma once
#include "SFML/Graphics/Shape.hpp"
#include <SFML/Graphics/Rect.hpp>
#include <SFML/Graphics/RenderWindow.hpp>
#include <SFML/Graphics/RectangleShape.hpp>
#include "World.hpp"

using namespace sf;

enum EType {
	_Player,
	_IA,
	_Wall,
	_Brick,
	_Hole,
	_MissilePl,
	_MissileIA
};

class Entity {
public:
	Shape* spr = nullptr;
	Vector2f position;
	Vector2f direction;
	RectangleShape * gun = nullptr;
	Entity * missile = nullptr;
	EType type;
	float timer = 3;
	float speed = 1;
	bool doDraw = true;

	Vector2f cleanPosition;

	Entity(EType _type, Shape * _spr,sf::Vector2f pos) {
		type = _type;
		spr = _spr;
		position = pos;
		if (type == _Player || type == _IA) {
			gun = new RectangleShape(sf::Vector2f(20, 8));
			gun->setOrigin(0, 4);
			if (type == _IA) {
				speed = 0.5;	
			}
		}
		else if (type == _MissileIA || type == _MissilePl) {
			speed = 1.5;
			
		}
		if (type == _MissileIA || type == _Player) {
			doDraw = false;
		}
	}
	Entity(EType _type, Shape * _spr, sf::Vector2f pos,Entity* _missile) {
		type = _type;
		spr = _spr;
		position = pos;
		if (type == _Player || type == _IA) {
			gun = new RectangleShape(sf::Vector2f(20, 8));
			gun->setOrigin(0, 4);
			if (type == _IA) {
				speed = 0.5;
			}
				missile = _missile;
		}
	}

	~Entity() {
		if (spr) {
			delete spr;
			spr = nullptr;
		}
		if (gun) {
			delete gun;
			gun = nullptr;
		}
		if (missile) {
			missile->doDraw = false;
			missile->~Entity();
		}
	}

	void move(Vector2f dir);
	void update(double dt, RenderWindow& window);
	void draw(RenderWindow& window);
};


