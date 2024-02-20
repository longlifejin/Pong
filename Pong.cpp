#include "pch.h"
#include <SFML/Graphics.hpp>
#include "Bat.h"
#include "Ball.h"
#include "TextGo.h"

int main()
{
    sf::RenderWindow window(sf::VideoMode(1920, 1080), "Pong");

    InputMgr::Init();
    Bat bat;
    Ball ball(bat, { { 0.f,0.f }, { 1920.f, 1080.f } });

    bool isBallActive = false;
    sf::Vector2f fireDirection = { -1.f, -1.f };

    sf::Clock clock;

    TextGo* score;


    while (window.isOpen())
    {
        sf::Time deltaTime = clock.restart();
        float dt = deltaTime.asSeconds();
        InputMgr::Clear();
        sf::Event event;
        while (window.pollEvent(event))
        {
            if (event.type == sf::Event::Closed)
                window.close();

            InputMgr::UpdateEvent(event);
        }

        InputMgr::Update(dt);
        
        if (!isBallActive && InputMgr::GetKeyDown(sf::Keyboard::Space))
        {
            ball.Fire(fireDirection, 500.f);
            isBallActive = true;
        }

        bat.Update(dt);
        if (ball.isDead)
        {
            isBallActive = false;
            ball.Fire({0.f, 0.f}, 0.f);
            //게임 재시작 대기
        }
        else
        {
            bat.Update(dt);
        }

        if (!isBallActive)
        {
            ball.shape.setPosition(bat.shape.getPosition());
        }
        ball.Update(dt);

        window.clear();
        bat.Draw(window);
        ball.Draw(window);
        window.display();
    }

    return 0;
}