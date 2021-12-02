#pragma once
#include <SFML/Graphics.hpp>
#include <SFML/Graphics/RenderWindow.hpp>

class Entity {
public:
	sf::Shape * shape = nullptr;
	std::vector<Entity> entities;
	
	//Base coords
	int cx = 0, cy = 0;
	float xr = 0, yr = 0;
	//Result coords
	float xx = 0, yy = 0;
	//Movements
	float dx = 0, dy = 0;

	inline static const int stride = 32;
	

	Entity(sf::Shape* shp,float x,float y) {
		shape = shp;
		cx = x;
		cy = y;
		entities.push_back(*this);
		syncSprite();
	}

	~Entity() {

	}

	void syncSprite();
	void update(double dt);
	void draw(sf::RenderWindow& window);
	void setCoords(float x, float y);
	bool hasCollision(float x, float y);
};

