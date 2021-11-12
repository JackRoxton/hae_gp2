#include "pch.h"
#include "particle.hpp";

particle::particle() {
	int t = 10;
	shape = sf::CircleShape(t);
	shape.setFillColor(sf::Color::Yellow);
	shape.setOrigin(sf::Vector2f(t, t));
}

void particle::create(float _px, float _py, float _dx, float _dy) {
	for (int i = 0; i < px.size(); ++i)
	{
		if (!alive[i]) { //cherche si un est en vie
			px[i] = _px;
			py[i] = _py;
			dx[i] = _dx;
			dy[i] = _dy;
			alive[i] = true;
			return;
		}
	}
	px.push_back(_px);
	py.push_back(_py);
	dx.push_back(_dx);
	dy.push_back(_dy);
	alive.push_back(true);
	
}

void particle::update(double dt) {
	for (int i = 0; i < px.size(); ++i) {
		if (alive[i]) {
			px[i] += dx[i] * dt;
			py[i] += dy[i] * dt;
			if (px[i] > 3000 || px[i] < -100
				|| py[i] > 3000 || py[i] < -100) {
				alive[i] = false;
			}
		}
	}
}

void particle::draw(sf::RenderWindow& win) {
	int idx = 0;
	const int sz = px.size();
	while (idx < sz) {
		if (alive[idx]) {
			shape.setPosition(px[idx], py[idx]);
			win.draw(shape);
		}
		idx++;
	}
}