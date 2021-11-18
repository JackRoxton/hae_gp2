#include "pch.h"
#include "World.hpp"

void World::collide(double dt) {
	for (auto e : entities) {
		FloatRect eHB = e->spr->getGlobalBounds();
		Vector2f oldPos = e->spr->getPosition();
		e->update(dt);
		for (auto f : entities) {
			FloatRect fHB = f->spr->getGlobalBounds();
			if (/*e != f &&*/ e->type != f->type) {
				if (eHB.intersects(fHB)) {
					if (e->type == Ball) {
						audio->ballPong.play();

						if (f->type == Wall) {
							if (fHB.width > fHB.height) {
								e->direction.y *= -1;
								e->cleanPosition.y += eHB.height;
							}
							else {
								if (fHB.left > e->cleanPosition.x)
									e->cleanPosition.x -= eHB.width;
								else
									e->cleanPosition.x += eHB.width;

								e->direction.x *= -1;
							}
							e->spr->setPosition(e->cleanPosition);
							e->position = e->cleanPosition;
						}

						if (f->type == Brick || f->type == PlayerObject) {
							if ((e->cleanPosition.y < fHB.top)) {
								e->direction.y *= -1;
								//e->cleanPosition.y -= eHB.height;
							}
							if ((e->cleanPosition.y > (fHB.top + fHB.height))){
								e->direction.y *= -1;
								//e->cleanPosition.y += eHB.height;
							}
							else if(e->cleanPosition.x < fHB.left){
								e->direction.x *= -1;
								//e->cleanPosition.x -= eHB.width;
							}
							else {
								e->direction.x *= -1;
								//e->cleanPosition.x += eHB.width;
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

Audio::Audio() {
	if (ballPongBuffer.loadFromFile("res/pickupCoin.wav"))
		ballPong.setBuffer(ballPongBuffer);
	if (musicBuffer.loadFromFile("res/BeepBox-Song.wav"))
		music.setBuffer(musicBuffer);
	music.play();
	music.setLoop(true);
}