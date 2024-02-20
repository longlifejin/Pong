#include "pch.h"
#include "UiScore.h"

UiScore::UiScore(const std::string& name)
	: TextGo(name)
{
}

void UiScore::SetScore(size_t score)
{
	this->score = score;
	text.setString(scoreFormat + std::to_string(this->score));
}

void UiScore::AddScore(size_t score)
{
	this->score += score;
	text.setString(scoreFormat + std::to_string(this->score));
}

void UiScore::Reset()
{
	SetScore(0);
}