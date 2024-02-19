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


//벽 충돌 처리 windowBounds
void Ball::colCheck(sf::Vector2f d)
{
	sf::Vector2f pos = shape.getPosition();

	if (pos.x <= windowBounds.left || pos.x >= windowBounds.width) //왜 ballBounds.left로 비교하면 안될까??
	{
		direction.x = d.x * -1.f;
	}

	if (pos.y <= windowBounds.top)
	{
		direction.y = d.y * -1.f;
	}

	if (pos.y >= windowBounds.height) //왜 여기선 y direction 변경이 안되지?
	{
		isDead = true; //이 식을 넣으면 또 바로 죽음, 조건식 성립은 되는데 방향 변경이 안되는 중(다음에 원인 찾기..........)
	}

}

void Ball::Update(float dt)
{
	isBoundBat = false;

	sf::Vector2f pos = shape.getPosition();
	pos += direction * speed * dt;
	shape.setPosition(pos);

	const sf::FloatRect& ballBounds = shape.getGlobalBounds();
	const sf::FloatRect& batBounds = bat.shape.getGlobalBounds();
	
	colCheck({-1.f, -1.f});

	//bat 충돌 처리
	if (ballBounds.intersects(batBounds))
	{
		direction *= -1.f;
		isBoundBat = true;
	}
}

void Ball::Draw(sf::RenderWindow& window)
{
	window.draw(shape);
}
