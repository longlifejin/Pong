#pragma once
#include "pch.h"
#include <SFML/Graphics.hpp>

class Bat
{
protected:


public:
	Bat();

	sf::FloatRect prevGlobalBounds;

	float speed = 300.f;

	sf::RectangleShape shape;

	void Init();
	void Update(float dt);
	void Draw(sf::RenderWindow& window);

};

