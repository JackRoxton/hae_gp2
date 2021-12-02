#pragma once
#include <SFML/Graphics.hpp>

class Player {
public:
	sf::Transform transform;

	sf::RectangleShape wheels;//vers le dépalcement
	sf::RectangleShape frame;//vers le dépalcement
	sf::RectangleShape turret;//vers la souris
	sf::RectangleShape canon;//vers la souris

	int lifeCount = 3;
	float speed;

	Player() {//même pour les IA
		transform.translate(200,200);
		wheels = sf::RectangleShape(sf::Vector2f(20, 40));
		frame = sf::RectangleShape(sf::Vector2f(20, 32));
		frame.setOrigin(0,4);
		turret = sf::RectangleShape(sf::Vector2f(12, 12));
		turret.setOrigin(2, 2);
		canon = sf::RectangleShape(sf::Vector2f(4, 8));
		canon.setOrigin(2, 2);
	}

	~Player() {
		
	}
};