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
	Scene::Release(); //부모 클래스 함수 호출
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
