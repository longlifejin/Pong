#include "pch.h"
#include "Ball.h"
#include "Bat.h"

Ball::Ball(Bat& bat, const sf::FloatRect& bounds)
	:bat(bat), windowBounds(bounds)
{
	shape.setRadius(10.f);
	shape.setPosition({ 1920.f / 2.f, 1080.f - 35.f });
	shape.setFillColor(sf::Color::White);

	Utils::SetOrigin(shape, Origins::BC);
}

void Ball::Fire(sf::Vector2f d, float s)
{
	direction = d;
	speed = s;
	isDead = false;
}

void Ball::Update(float dt)
{
	isBoundBat = false;

	const sf::FloatRect& prevBallBounds = shape.getGlobalBounds();
	sf::Vector2f prevPos = shape.getPosition();
	sf::Vector2f pos = prevPos;
	pos += direction * speed * dt;
	shape.setPosition(pos);

	const sf::FloatRect& ballBounds = shape.getGlobalBounds();
	
	//벽 충돌 처리 windowBounds
	float ballLeft = ballBounds.left;
	float ballRight = ballBounds.left + ballBounds.width;
	float ballTop = ballBounds.top;
	float ballBottom = ballBounds.top + ballBounds.height;

	float windowLeft = windowBounds.left;
	float windowRight = windowBounds.left + windowBounds.width;
	float windowTop = windowBounds.top;
	float windowBottom = windowBounds.top + windowBounds.height;

	if (ballBottom > windowBottom)
	{
		isDead = true;
	}
	else if (ballTop < windowTop)
	{
		shape.setPosition(prevPos);
		direction.y *= -1.f;
	}
	else if (ballLeft < windowLeft || ballRight > windowRight)
	{
		shape.setPosition(prevPos);
		direction.x *= -1.f;
	}

	//bat 충돌 처리
	const sf::FloatRect& batBounds = bat.shape.getGlobalBounds();
	//이전과 현재의 충돌 상황을 비교
	if (!prevBallBounds.intersects(bat.prevGlobalBounds) && ballBounds.intersects(batBounds))
	{
		float batLeft = batBounds.left;
		float batRight = batBounds.left + batBounds.width;
		float batTop = batBounds.top;
		float batBottom = batBounds.top + batBounds.height;

		if (ballBottom > batTop || ballTop < batBottom)
		{
			direction.y *= -1.f;
		}
		else if (ballLeft > batRight || ballRight < batLeft)
		{
			direction.x *= -1.f;
		}
		shape.setPosition(prevPos);
		isBoundBat = true;
	}
}

void Ball::Draw(sf::RenderWindow& window)
{
	window.draw(shape);
}
