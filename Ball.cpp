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


//�� �浹 ó�� windowBounds
void Ball::colCheck(sf::Vector2f d)
{
	sf::Vector2f pos = shape.getPosition();

	if (pos.x <= windowBounds.left || pos.x >= windowBounds.width) //�� ballBounds.left�� ���ϸ� �ȵɱ�??
	{
		direction.x = d.x * -1.f;
	}

	if (pos.y <= windowBounds.top)
	{
		direction.y = d.y * -1.f;
	}

	if (pos.y >= windowBounds.height) //�� ���⼱ y direction ������ �ȵ���?
	{
		isDead = true; //�� ���� ������ �� �ٷ� ����, ���ǽ� ������ �Ǵµ� ���� ������ �ȵǴ� ��(������ ���� ã��..........)
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

	//bat �浹 ó��
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
