#include "Entity.hpp"

void Entity::syncSprite() {
	shape->setPosition(xx, yy);
}

void Entity::update(double dt) {
	dx *= 0.9;
	dy *= 0.9;

	xr += dx;
	yr += dy;

	if (xr > 1) {
		xr--;
		cx++;
	}
	if (xr < 0){
		xr++;
		cx--;
	}
	if (yr > 1) {
		yr--;
		cy++;
	}
	if (yr < 0) {
		yr++;
		cy--;
	}

	if (hasCollision(cx + 1, cy) && xr >= 0.7) {
		xr = 0.7;
	}
	if (hasCollision(cx - 1, cy) && xr <= 0.3) {
		xr = 0.3;
	}
	if (hasCollision(cx, cy + 1) && yr >= 0.7) {
		yr = 0.7;
	}
	if (hasCollision(cx, cy - 1) && yr <= 0.3) {
		yr = 0.3;
	}

	xx = (cx * stride) + (xr * stride);
	yy = (cy * stride) + (yr * stride);
	syncSprite();
}

void Entity::draw(sf::RenderWindow& window) {
	for (auto e : World::entities) {
		if(shape)
		window.draw(*e.shape);
	}
}

void Entity::setCoords(float x, float y) {
	xx = x;
	yy = y;
	cx = xx / stride;
	cy = yy / stride;
	xr = (xx-cx*stride) / stride;
	yr = (yy-cy*stride) / stride;
}

bool Entity::hasCollision(float _cx, float _cy) {
	for (int i = 0; i < World::entities.size(); i++) {
		if (World::entities[i].cx == _cx && World::entities[i].cy == _cy)
			return true;
	}
	return false;
}