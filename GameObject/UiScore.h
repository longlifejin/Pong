#pragma once
#include "TextGo.h"
class UiScore :
    public TextGo
{
protected:
	UiScore(const UiScore&) = delete;
	UiScore(UiScore&&) = delete;
	UiScore& operator=(const UiScore&) = delete;
	UiScore& operator=(UiScore&&) = delete;

	std::string scoreFormat = "Score : ";
	unsigned score = 0;

public:
	UiScore(const std::string& name = "");

	std::string GetScore() { return this->scoreFormat.append(std::to_string(score)); }
	unsigned GetUnsignedScore() const { return score; }

	void SetScore(size_t score);
	void AddScore(size_t score);

	void Reset() override;
};

