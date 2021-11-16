#include "pch.h"
#include "World.hpp"

void World::collide() {//faire par type ou une constante ( vu que ce sont des rectangles?)
	for (auto e : entities) {
		for (auto f : entities) {
			if(e != f){ 
				if (e->hitBox.intersects(f->hitBox)) {//collide constant parceque why not ?? // soucis de hitbox ? à tester // avec des contains ou intersect
					printf("%d",f->type);
					if (e->type == Ball) {
						if (e->position.x > f->position.x + f->hitBox.width) { // avec des pos.x ou des hitBox.left ? https://www.sfml-dev.org/documentation/2.5.1/classsf_1_1Rect.php#aa49960fa465103d9cb7069ceb25c7c32
							e->direction.x *= -1;
						}
					}
				}
			}
		}
	}
}

void World::update(double dt) {
	for (auto e : entities) {
		e->update(dt);
	}
}

void World::draw(RenderWindow& window) {
	for (auto e : entities) {
		e->draw(window);
	}
}