#include "pch.h"
#include "World.hpp"

void World::collide(double dt, sf::RenderWindow& win) {
	for (auto e : entities) {
		if (e->spr) {

			FloatRect eHB = e->spr->getGlobalBounds();
			Vector2f oldPos = e->spr->getPosition();
			//breakBricks();
			e->update(dt);
			for (auto f : entities) {
				if (f->spr) {

					FloatRect fHB = f->spr->getGlobalBounds();
					if (/*e != f &&*/ e->type != f->type) {
						if (eHB.intersects(fHB)) {
							if (e->type == Ball) {
								audio->ballPong.play();

								if (f->type == Wall) {
									if (fHB.width > fHB.height) {
										e->direction.y *= -1;
										e->cleanPosition.y += eHB.height/2;
									}
									else {
										if (fHB.left > e->cleanPosition.x) {
											e->cleanPosition.x -= eHB.width/2;
										}
										else {
											e->cleanPosition.x += eHB.width/2;
										}
										e->direction.x *= -1;
									}
									e->spr->setPosition(e->cleanPosition);
									e->position = e->cleanPosition;
								}

								if (f->type == Brick) {
									if ((e->cleanPosition.y < fHB.top)) {
										e->direction.y *= -1;
										e->cleanPosition.y -= eHB.height/2;
									}
									else if ((e->cleanPosition.y > (fHB.top + fHB.height))){
										e->direction.y *= -1;
										e->cleanPosition.y += eHB.height/2;
									}
									else if(e->cleanPosition.x < fHB.left){
										e->direction.x *= -1;
										e->cleanPosition.x -= eHB.width/2;
									}
									else if (e->cleanPosition.x > (fHB.left + fHB.width)) {
										e->direction.x *= -1;
										e->cleanPosition.x += eHB.width/2;
									}
									e->spr->setPosition(e->cleanPosition);
									e->position = e->cleanPosition;
									//toBreak.push_back(f);
									f->~Entity();//faire fonctionner le breackBricks
									game->createShake(win);
								}

								if (f->type == PlayerObject) { // à changer
									if ((e->cleanPosition.y < fHB.top)) {
										e->direction.y *= -1;
										e->cleanPosition.y -= eHB.height / 2;
									}
									if ((e->cleanPosition.y > (fHB.top + fHB.height))) {
										e->direction.y *= -1;
										e->cleanPosition.y += eHB.height / 2;
									}
									if (e->cleanPosition.x < fHB.left) {
										e->direction.x *= -1;
										e->cleanPosition.x -= eHB.width / 2;
									}
									if (e->cleanPosition.x > (fHB.left + fHB.width)) {
										e->direction.x *= -1;
										e->cleanPosition.x += eHB.width / 2;
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
	}
}

void World::breakBricks() {
	for (auto b : toBreak) {
		for (auto e : entities) {
			if (b == e) {
				//entities.erase(e);
				//toBreak.erase(e);
				delete e;
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
	if (music.openFromFile("res/BeepBoxSong.wav")) {
		music.play();
		music.setLoop(true);
	}
}