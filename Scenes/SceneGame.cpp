#include "pch.h"
#include "SceneGame.h"

SceneGame::SceneGame(SceneIds id)
	:Scene(id)
{
}

void SceneGame::Init()
{
}

void SceneGame::Release()
{
	Scene::Release(); //�θ� Ŭ���� �Լ� ȣ��
}

void SceneGame::Enter()
{
	Scene::Enter();
}

void SceneGame::Exit()
{
}

void SceneGame::Update(float dt)
{
	Scene::Update(dt);
}

void SceneGame::Draw(sf::RenderWindow& window)
{
	Scene::Draw(window);
}
