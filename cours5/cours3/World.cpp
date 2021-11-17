#include "pch.h"
#include "World.hpp"

void World::collide(double dt) {//faire par type ou une constante (vu que ce sont des rectangles?)
	for (auto e : entities) {
		FloatRect eHB = e->spr->getGlobalBounds();
		Vector2f oldPos = e->spr->getPosition();
		e->update(dt);
		for (auto f : entities) {
			FloatRect fHB = f->spr->getGlobalBounds();
			if(e != f && e->type != f->type){ 
				if (eHB.intersects(fHB)) {// avec des contains ou intersect
					if (e->type == Ball) {
						if (f->type == Wall){
							if (fHB.width > fHB.height) {
								e->direction.y *= -1;
							}
							else {
								e->direction.x *= -1;
							}
							e->spr->setPosition(e->cleanPosition);
							e->position = e->cleanPosition;
						}
						if (f->type == Brick || f->type == PlayerObject) {
							if ((e->cleanPosition.y < fHB.top) || (e->cleanPosition.y > (fHB.top + fHB.height))) {
								e->direction.y *= -1;
							}
							else {
								e->direction.x *= -1;
							}
							e->spr->setPosition(e->cleanPosition);
							e->position = e->cleanPosition;
						}
					}
				}
				else if (e->type == Ball) {
					e->cleanPosition = oldPos;
				}
			}
		}
	}
}

void World::draw(RenderWindow& window) {
	for (auto e : entities) {
		e->draw(window);
	}
}