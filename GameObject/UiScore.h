#pragma once
#include "TextGo.h"
class UiScore :  public TextGo
{
protected:
	UiScore(const UiScore&) = delete;
	UiScore(UiScore&&) = delete;
	UiScore& operator=(const UiScore&) = delete;
	UiScore& operator=(UiScore&&) = delete;

	std::string scoreFormat = "Score:";
	int score = 0;

public:
	UiScore(const std::string& name = "");

	void SetScore(int score);
	void AddScore(int score);

	void Reset() override;
};

