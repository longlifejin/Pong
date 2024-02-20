#include "pch.h"
#include "SceneGame.h"
#include "UiScore.h"

SceneGame::SceneGame(SceneIds id)
	:Scene(id)
{
}

void SceneGame::Init()
{
	fontManager.Load("./Pong Bin/DS-DIGI.ttf");

	uiScore = new UiScore("uiScore");
	uiScore->Set(fontManager.Get("./Pong Bin/DS-DIGI.ttf"), "", 40, sf::Color::White);
	uiScore->SetPosition({ 0.f,0.f });
	uiScore->SetOrigin(Origins::TL);
	uiScore->SetScore(0);
	AddGameObject(uiScore);




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
