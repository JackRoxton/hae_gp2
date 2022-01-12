#include "World.hpp"
#include "SFML/Graphics.hpp"

void World::collide(double dt, sf::RenderWindow& win) {
	for (auto e : entities) {
		if (!e)
			return;
		if (e->spr) {
			FloatRect eHB = e->spr->getGlobalBounds();
			Vector2f oldPos = e->spr->getPosition();
			e->update(dt,win);
			for (auto f : entities) {
				if (f->spr) {
					FloatRect fHB = f->spr->getGlobalBounds();
					if (e->type != f->type) {
						if (eHB.intersects(fHB)) {
							if (e->type == _MissilePl || e->type == _MissileIA) {
								ColMissile(e,f);
							}
							else if (e->type == _Player || e->type == _IA) {
								ColPlayerIa(e,f);
							}
						}
						else {
							e->cleanPosition = oldPos;
						}
					}
				}
			}
			e->draw(win);
		}
		else {
			auto iter = std::find(entities.begin(), entities.end(), e);
			if (iter != entities.end())
				entities.erase(iter);
			e->~Entity();
		}
	}
}

void World::ColMissile(Entity* e, Entity* f) {
	if (!e->spr || !f->spr) {
		return;
	}
	FloatRect eHB = e->spr->getGlobalBounds();
	FloatRect fHB = f->spr->getGlobalBounds();
	if (f->type == _Wall) {
		if ((e->cleanPosition.y < fHB.top)) {
			e->cleanPosition.y -= eHB.height / 2;
			e->position = e->cleanPosition;
			e->direction.y *= -1;
		}
		else if ((e->cleanPosition.y > (fHB.top + fHB.height))) {
			e->cleanPosition.y += eHB.height / 2;
			e->position = e->cleanPosition;
			e->direction.y *= -1;
		}
		else if (e->cleanPosition.x < fHB.left) {
			e->cleanPosition.x -= eHB.width / 2;
			e->position = e->cleanPosition;
			e->direction.x *= -1;
		}
		else if (e->cleanPosition.x > (fHB.left + fHB.width)) {
			e->cleanPosition.x += eHB.width / 2;
			e->position = e->cleanPosition;
			e->direction.x *= -1;
		}
		e->spr->setPosition(e->cleanPosition);
		e->position = e->cleanPosition;
	}
	else if (f->type == _Brick) { 
		if (e->type == _MissileIA) {
			e->position = Vector2f(1200, 700);
			e->direction = Vector2f(0, 0);
			e->doDraw = false;
		}
		else {
			e->~Entity();
		}
		f->~Entity();
		audio->expl.play();
	}
	else if (e->type == _MissileIA && f->type == _Player){
		e->position = Vector2f(1200, 700);
		e->direction = Vector2f(0, 0);
		e->doDraw = false;
		if (IFrames < 0) {
			IFrames = 1;
			playerLives -= 1;
			if (playerLives == 0) {
				GameOver();
			}
		}
		audio->expl.play();
	}
	else if (e->type == _MissilePl && f->type == _IA) {
		e->~Entity();
		f->~Entity();
		iaCount -= 1;
		if (iaCount == 0) {
			GameWon();
		}
		audio->expl.play();
	}
}

void World::ColPlayerIa(Entity* e, Entity* f) {
	if (!e->spr || !f->spr) {
		return;
	}
	if (f->type == _Hole || f->type == _Brick || f->type == _Wall) {
		
		FloatRect eHB = e->spr->getGlobalBounds();
		FloatRect fHB = f->spr->getGlobalBounds();
		if ((e->cleanPosition.y < fHB.top)) {
			e->cleanPosition.y -= eHB.height / 8;
			e->position = e->cleanPosition;
		}
		else if ((e->cleanPosition.y > (fHB.top + fHB.height))) {
			e->cleanPosition.y += eHB.height / 8;
			e->position = e->cleanPosition;
		}
		else if (e->cleanPosition.x < fHB.left) {
			e->cleanPosition.x -= eHB.width / 8;
			e->position = e->cleanPosition;
		}
		else if (e->cleanPosition.x > (fHB.left + fHB.width)) {
			e->cleanPosition.x += eHB.width / 8;
			e->position = e->cleanPosition;
		}
	}
}

void World::CreateMissile(sf::Vector2f pos, sf::Vector2f dir, EType type) {
	Entity * newMissile = new Entity(type, new sf::RectangleShape(sf::Vector2f(6, 10)), pos);
	newMissile->spr->setOrigin(3, 5);
	float dirLen = std::sqrt(dir.x * dir.x + dir.y * dir.y);
	sf::Vector2f dxy(1, 0);
	if (dirLen) {
		dxy = dir / dirLen;
	}
	dxy *= 60.0f * 3;
	newMissile->move(dxy);
	entities.push_back(newMissile);
}

void World::LoadLevel(Entity* player,int nb) {
	playerLives = 3;
	
	int xl = 50;
	int yl = 50;
	int cs = 25;
	int xmax = 45;
	int ymax = 25;
	for (int x = 0; x < xmax; x++) {
		for (int y = 0; y < ymax; y++) {
			if (x == 0 || x == xmax-1 || y == 0 || y == ymax-1){
				auto wallshp = new sf::RectangleShape(sf::Vector2f(cs, cs));
				Entity * eWall = new Entity(_Wall, wallshp, sf::Vector2f(xl + x * cs, yl + y * cs));
				eWall->spr->setFillColor(sf::Color::Yellow);

				Level.push_back(eWall);
			}
		}
	}

	if (nb == 1) {
		for (int x = 6; x < 40; x+=32) {
			for (int y = 5; y < 20; y++) {
				auto wallshp = new sf::RectangleShape(sf::Vector2f(cs, cs));
				Entity * eWall = new Entity(_Wall, wallshp, sf::Vector2f(xl + x * cs, yl + y * cs));
				eWall->spr->setFillColor(sf::Color::Yellow);
				Level.push_back(eWall);
			}
		}

		for (int x = 22; x < 24; x ++) {
			for (int y = 1; y < 24; y++) {
				auto brickshp = new sf::RectangleShape(sf::Vector2f(cs, cs));
				Entity * eBrick = new Entity(_Brick, brickshp, sf::Vector2f(xl + x * cs, yl + y * cs));
				eBrick->spr->setFillColor(sf::Color::Red);
				Level.push_back(eBrick);
			}
		}

		for (int x = 7; x < 38; x++) {
			for (int y = 12; y < 14; y++) {
				if (x != 22 && x != 23) {
					auto holeshp = new sf::CircleShape(cs/2);
					Entity * eHole = new Entity(_Hole, holeshp, sf::Vector2f(xl + x * cs, yl + y * cs));
					eHole->spr->setFillColor(sf::Color::White);
					Level.push_back(eHole);
				}
			}
		}

		for (int x = 4; x < 42; x+=37) {
			for (int y = 4; y < 22; y+=17) {
				if (x == 4 && y == 4) {}
				else {
					Entity * eMissile = new Entity(_MissileIA, new sf::RectangleShape(sf::Vector2f(6, 10)), sf::Vector2f(1200, 700));
					eMissile->spr->setOrigin(3, 5);
					Entity * eIA = new Entity(_IA, new sf::RectangleShape(sf::Vector2f(cs, cs)), sf::Vector2f(xl + x * cs, yl + y * cs), eMissile);
					eIA->spr->setFillColor(sf::Color::Blue);
					eIA->spr->setOrigin(12.5f, 12.5f);
					iaCount++;
					Level.push_back(eIA);
					Level.push_back(eMissile);
				}
			}
		}
		player->position = Vector2f(100, 100);
		player->doDraw = true;
	}
	else if (nb == 2) {
		for (int x = 4; x < 40; x++) {
			for (int y = 4; y < 20; y++) {
				if (x == 4 || x == 40 - 1 || y == 4 || y == 20 - 1) {
					auto brickshp = new sf::RectangleShape(sf::Vector2f(cs, cs));
					Entity * eBrick = new Entity(_Brick, brickshp, sf::Vector2f(xl + x * cs, yl + y * cs));
					eBrick->spr->setFillColor(sf::Color::Red);

					Level.push_back(eBrick);
				}
			}
		}

		for (int x = 5; x < 39; x++) {
			for (int y = 12; y < 13; y++) {
				auto holeshp = new sf::CircleShape(cs / 2);
				Entity * eHole = new Entity(_Hole, holeshp, sf::Vector2f(xl + x * cs, yl + y * cs));
				eHole->spr->setFillColor(sf::Color::White);

				Level.push_back(eHole);
			}
		}
		for (int x = 22; x < 23; x++) {
			for (int y = 5; y < 19; y++) {
				auto holeshp = new sf::CircleShape(cs / 2);
				Entity * eHole = new Entity(_Hole, holeshp, sf::Vector2f(xl + x * cs, yl + y * cs));
				eHole->spr->setFillColor(sf::Color::White);

				Level.push_back(eHole);
			}
		}
		for (int x = 10; x < 31; x+=20) {
			for (int y = 7; y < 18; y+=10) {
				Entity * eMissile = new Entity(_MissileIA, new sf::RectangleShape(sf::Vector2f(6, 10)), sf::Vector2f(1200, 700));
				eMissile->spr->setOrigin(3, 5);
				Entity * eIA = new Entity(_IA, new sf::RectangleShape(sf::Vector2f(cs, cs)), sf::Vector2f(xl + x * cs, yl + y * cs), eMissile);
				eIA->spr->setFillColor(sf::Color::Blue);
				eIA->spr->setOrigin(12.5f, 12.5f);
				iaCount++;
				Level.push_back(eIA);
				Level.push_back(eMissile);
			}
		}
			player->position = Vector2f(100, 100);
			player->doDraw = true;
	}
	else if (nb == 3) {

		for (int x = 8; x < 37; x ++) {
			for (int y = 8; y < 17; y ++) {
				if (x == 8 || x == 37 -1 || y == 8 || y == 17 - 1) {
					auto holeshp = new sf::CircleShape(cs/2);
					Entity * eHole = new Entity(_Hole, holeshp, sf::Vector2f(xl + x * cs, yl + y * cs));
					eHole->spr->setFillColor(sf::Color::White);

					Level.push_back(eHole);
				}
			}
		}

		for (int x = 4; x < 42; x += 37) {
			for (int y = 4; y < 22; y += 17) {
				Entity * eMissile = new Entity(_MissileIA, new sf::RectangleShape(sf::Vector2f(6, 10)), sf::Vector2f(1200, 700));
				eMissile->spr->setOrigin(3, 5);
				Entity * eIA = new Entity(_IA, new sf::RectangleShape(sf::Vector2f(cs, cs)), sf::Vector2f(xl + x * cs, yl + y * cs), eMissile);
				eIA->spr->setFillColor(sf::Color::Blue);
				eIA->spr->setOrigin(12.5f, 12.5f);
				iaCount++;
				Level.push_back(eIA);
				Level.push_back(eMissile);
			}
		}

		player->position = Vector2f(640, 360);
		player->doDraw = true;
	}

		gameState = _Game;

	for (auto e : Level) {
		entities.push_back(e);
	}
}

void World::UnLoadLevel() {
	iaCount = 0;
	playerLives = 0;
	for (auto e : Level) {
		auto iter = std::find(entities.begin(), entities.end(), e);
		if (iter != entities.end())
			entities.erase(iter);
		e->~Entity();
	}
	Level.clear();
	//afficher le menu
}

void World::GameOver() {
	audio->over.play();
	UnLoadLevel();
	gameState = _GameOver;
}

void World::GameWon() {
	audio->over.play();
	UnLoadLevel();
	gameState = _GameWon;
}

Audio::Audio() {
	if (explBuffer.loadFromFile("res/explosion.wav")) {
		expl.setBuffer(explBuffer);
		expl.setVolume(15);
	}
	if (overBuffer.loadFromFile("res/Over.wav")) {
		over.setBuffer(overBuffer);
		over.setVolume(50);
	}
	if (music.openFromFile("res/tanks.wav")) {
		music.setVolume(75);
		music.play();
		music.setLoop(true);
	}
}