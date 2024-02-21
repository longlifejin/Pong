#include "pch.h"
#include "SceneGame.h"
#include "UiMessage.h"

SceneGame::SceneGame(SceneIds id)
	:Scene(id)
{
}

void SceneGame::Init()
{
	fontManager.Load("DS-DIGI.ttf");

	uiScore = new UiMessage("uiScore");
	uiScore->Set(fontManager.Get("DS-DIGI.ttf"), "", 40, sf::Color::White);
	uiScore->SetPosition({ 0.f,0.f });
	uiScore->SetOrigin(Origins::TL);
	uiScore->SetScore(0);
	AddGameObject(uiScore);

	uiLives = new UiMessage("uiMessage");
	uiLives->Set(fontManager.Get("DS-DIGI.ttf"), "", 40, sf::Color::White);
	uiLives->SetPosition({ 150.f,0.f });
	uiLives->SetOrigin(Origins::TL);
	uiLives->SetScore(0);
	AddGameObject(uiLives);



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
