#pragma once
#include <SFML/Graphics.hpp>
#include "pch.h"

class Bat
{
protected:


public:
	Bat();
	float speed = 300.f;

	sf::RectangleShape shape;

	void Init();
	void Update(float dt);
	void Draw(sf::RenderWindow& window);

};

