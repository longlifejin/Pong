#pragma once

class Bat;

class Ball
{
protected:
	sf::Vector2f direction = { 0.f, 0.f };
	Bat& bat;
	float speed = 0.f;
	sf::FloatRect windowBounds;

public:
	bool isDead = false;
	bool isBoundBat = false;

	Ball(Bat& bat, const sf::FloatRect& bounds);
	
	sf::CircleShape shape;

	void Fire(sf::Vector2f d, float s);
	void colCheck(sf::Vector2f d);

	void Update(float dt);
	void Draw(sf::RenderWindow& window);

};

