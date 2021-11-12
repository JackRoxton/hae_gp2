#include "pch.h"
#include <iostream>
#include <SFML/Graphics.hpp>
#include <SFML/Main.hpp>
#include "particle.hpp"
#include "Entity.hpp"

int posx = 400, posy = 400;
int dt = 1;
bool keypress = false;

float catmull(float p0, float p1, float p2, float p3 , float t) {
	auto q = 2*p1;
	auto t2 = t * t;

	q += (-p0 + p2) 					* t;
	q += (2.0*p0 - 5.0*p1 + 4 * p2 - p3) 	* t2;
	q += (-p0 + 3 * p1 - 3 * p2 + p3) 	* t2 * t;

	return 0.5f*q;

	/*sf::VertexArray arr;
	arr.setPrimitiveType(sf::LineStrip);
	sf::Color col = sf::Color::Magenta;

	float baseline = 200;

	sf::Vector2f a(0, baseline);
	sf::Vector2f b(400, baseline + 150);
	sf::Vector2f c(800, baseline - 250);
	sf::Vector2f d(window.getSize().x, baseline);

	arr.append(sf::Vertex(a, col));
	arr.append(sf::Vertex(b, col));
	arr.append(sf::Vertex(c, col));
	arr.append(sf::Vertex(d, col));*/
}

void drawMountain(sf::RenderWindow& window) {
	sf::VertexArray arr;
	arr.setPrimitiveType(sf::LineStrip);
	sf::Color col = sf::Color::Yellow;
	
	float baseline = 200;

	sf::Vector2f a(0,baseline);
	sf::Vector2f b(400, baseline +100);
	sf::Vector2f c(800, baseline -100);
	sf::Vector2f d(window.getSize().x,baseline);

	/*arr.append(sf::Vertex(a, col));
	arr.append(sf::Vertex(b, col));
	arr.append(sf::Vertex(c, col));
	arr.append(sf::Vertex(d, col));*/

	col = sf::Color::Magenta;

	window.draw(arr);
	arr.clear();
	for (int i = 0; i < 256; ++i) {
		float t = 1.0f * i / 256;
		float x = catmull(a.x, a.x, b.x, c.x, t);
		float y = catmull(a.y, a.y, b.y, c.y , t);

		arr.append(sf::Vertex(sf::Vector2f(x,y),col));
	}
	window.draw(arr);
	arr.clear();
	for (int i = 0; i < 256; ++i) {
		float t = 1.0f * i / 256;
		float x = catmull(a.x, b.x, c.x, d.x, t);
		float y = catmull(a.y, b.y, c.y, d.y, t);

		arr.append(sf::Vertex(sf::Vector2f(x, y), col));
	}
	window.draw(arr);
	arr.clear();
	for (int i = 0; i < 256; ++i) {
		float t = 1.0f * i / 256;
		float x = catmull(b.x, c.x, d.x, d.x, t);
		float y = catmull(b.y, c.y, d.y, d.y, t);

		arr.append(sf::Vertex(sf::Vector2f(x, y), col));
	}

	window.draw(arr);
}

void drawGround(sf::RenderWindow& window){
	sf::VertexArray arr;
	arr.setPrimitiveType(sf::LineStrip);
	sf::Color col = sf::Color::Yellow;

	float baseline = 400+75;

	sf::Vector2f a(0, baseline);
	sf::Vector2f b(window.getSize().x, baseline);

	arr.append(sf::Vertex(a,col));
	arr.append(sf::Vertex(b,col));

	window.draw(arr);
}

int main()
{
	EntityManager repo;

	sf::RenderWindow window(sf::VideoMode(1280, 720), "SFML works!");
	window.setVerticalSyncEnabled(true);
	window.setFramerateLimit(60);
	sf::RectangleShape shape;
	shape.setSize(sf::Vector2f(50, 75));
	shape.setFillColor(sf::Color::Green);
	shape.setPosition(posx, posy);
	sf::RectangleShape gun;
	gun.setSize(sf::Vector2f(100, 25));
	gun.setFillColor(sf::Color::White);
	gun.setOrigin(10,10);
	gun.setPosition(posx, posy);
	sf::CircleShape mouse;
	mouse.setRadius(10.f);
	mouse.setFillColor(sf::Color::Yellow);
	mouse.setPosition(sf::Vector2f(sf::Mouse::getPosition()));

	particle bullets;
	
	/*sf::Font fHumble;
	if (!fHumble.loadFromFile("res/The Humble.ttf"))
		printf("font not loaded\n");
	sf::Text tdt;
	tdt.setFont(fHumble);
	tdt.setCharacterSize(45);*/

	/*bool bulletAlive = false;
	sf::Vector2f bulletTarget;
	sf::CircleShape bullet;
	sf::Vector2f characterToMouse;
	float norme;*/

	while (window.isOpen())
	{
		//repo.repository
		sf::Event event;
		while (window.pollEvent(event))
		{
			if (event.type == sf::Event::Closed)
				window.close();

			/*if (event.type == sf::Event::KeyPressed)
			{
				if (event.key.code == sf::Keyboard::Up)
					posy -= 5;
				if (event.key.code == sf::Keyboard::Down)
					posy += 5;
				if (event.key.code == sf::Keyboard::Left)
					posx -= 5;
				if (event.key.code == sf::Keyboard::Right)
					posx += 5;

				shape.setPosition(posx,posy);

				printf("%d, %d\n", posx, posy);
			}*/
		}
			auto pos = shape.getPosition();
			if (sf::Keyboard::isKeyPressed(sf::Keyboard::Left))
				posx -= dt; keypress = true;
			if (sf::Keyboard::isKeyPressed(sf::Keyboard::Right))
				posx += dt; keypress = true;
			/*if (sf::Keyboard::isKeyPressed(sf::Keyboard::Up))
				posy -= dt; keypress = true;
			if (sf::Keyboard::isKeyPressed(sf::Keyboard::Down))
				posy += dt; keypress = true;*/

			if (keypress) {
				shape.setPosition(posx, posy);
				gun.setPosition(posx + 25, posy + 10);
				keypress = false;
			}
			mouse.setPosition(sf::Vector2f(sf::Mouse::getPosition(window)));
			sf::Vector2f characterToMouse(mouse.getPosition().y - shape.getPosition().y,
				mouse.getPosition().x - shape.getPosition().x);
			float angle = atan2(characterToMouse.x, characterToMouse.y);
			gun.setRotation(angle * 57.2958);


			if (sf::Mouse::isButtonPressed(sf::Mouse::Left)) {
				auto pos = gun.getPosition();
				auto dir = sf::Vector2f(sf::Mouse::getPosition(window)) - pos;
				float dirLen = std::sqrt(dir.x*dir.x + dir.y*dir.y);
				sf::Vector2f dxy(1, 0);
				if (dirLen) {
					dxy = dir / dirLen;
				}
				dxy *= 60.0f * 3;
				bullets.create(pos.x, pos.y, dxy.x, dxy.y);
			}



			/*if (sf::Mouse::isButtonPressed(sf::Mouse::Left)&&!bulletAlive)
			{
				bullet.setRadius(10.f);
				bullet.setFillColor(sf::Color::Blue);
				bullet.setPosition(gun.getPosition());
				bulletAlive = true;
				bulletTarget = -sf::Vector2f(gun.getPosition().x-mouse.getPosition().x, gun.getPosition().y-mouse.getPosition().y);
				norme = std::sqrt(bulletTarget.x*bulletTarget.x+bulletTarget.y*bulletTarget.y);
				bulletTarget /= norme;
			}
		}
			if (bulletAlive) {
				bullet.move(bulletTarget);

				if (bullet.getPosition().x < 0 || bullet.getPosition().x > 1280
					|| bullet.getPosition().y < 0 || bullet.getPosition().y > 720)
				{
					bulletAlive = false;
				}
			}*/



			window.clear();

			bullets.update(dt);

			drawGround(window);
			drawMountain(window);

			bullets.draw(window);


			window.draw(shape);
			window.draw(gun);
			window.draw(mouse);

			/*if(bulletAlive)
				window.draw(bullet);

			window.draw(tdt);*/
			window.display();
		
	}

	return 0;
}