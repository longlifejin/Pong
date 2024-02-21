#pragma once
#include "TextGo.h"
class UiMessage :  public TextGo
{
protected:
	UiMessage(const UiMessage&) = delete;
	UiMessage(UiMessage&&) = delete;
	UiMessage& operator=(const UiMessage&) = delete;
	UiMessage& operator=(UiMessage&&) = delete;

	std::string scoreFormat = "Score:";
	int score = 0;

public:
	UiMessage(const std::string& name = "");

	void SetScore(int score);
	void AddScore(int score);

	void Reset() override;
};

