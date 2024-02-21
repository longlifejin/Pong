#pragma once
#include "Scene.h"

class UiMessage;
class TextGo;

class SceneGame : public Scene
{
protected:
	UiMessage* uiScore;
	UiMessage* uiLives;

public:
	SceneGame(SceneIds id);
	~SceneGame() override = default;

	void Init() override;
	void Release()override;

	void Enter() override;
	void Exit() override;

	void Update(float dt) override;
	void Draw(sf::RenderWindow& window) override;

};

